  //***************************************************************************************************************************************
/* Código de ejemplo de videojuego:
 * Detección de colisiones con objetos rectangulares.
 * Emplea estructuras para definir clases e instanciar objetos.
 * Incorpora actualización de cuadros cada 42ms ( aprox. 24fps).
 * Movimiento de sprite utilizando botones integrados.
 * Basado en librería para el uso de la pantalla ILI9341 en modo 8 bits
 * Autor: Diego Morales
 * IE3027: Electrónica Digital 2 - 2021
 */
//***************************************************************************************************************************************
#include <stdint.h>
#include <stdbool.h>
#include <TM4C123GH6PM.h>
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/rom_map.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"
#include "font.h"
#include "bitmaps.h"
#include "lcd_registers.h"

#include <SPI.h>
#include <SD.h>

#define LCD_RST PD_0
#define LCD_CS PD_1
#define LCD_RS PD_2
#define LCD_WR PD_3
#define LCD_RD PE_1
int DPINS[] = {PB_0, PB_1, PB_2, PB_3, PB_4, PB_5, PB_6, PB_7};  
//***************************************************************************************************************************************
// Functions Prototypes
//***************************************************************************************************************************************
void LCD_Init(void);
void LCD_CMD(uint8_t cmd);
void LCD_DATA(uint8_t data);
void SetWindows(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2);
void LCD_Clear(unsigned int c);
void H_line(unsigned int x, unsigned int y, unsigned int l, unsigned int c);
void V_line(unsigned int x, unsigned int y, unsigned int l, unsigned int c);
void Rect(unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned int c);
void FillRect(unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned int c);
void LCD_Print(String text, int x, int y, int fontSize, int color, int background);
void LCD_Bitmap(unsigned int x, unsigned int y, unsigned int width, unsigned int height, unsigned char bitmap[]);
void LCD_Sprite(int x, int y, float width, int height, unsigned char bitmap[],int columns, int index, char flip, char offset);
bool Collision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);

void MapSD(char x[]);   //Funciones para desplegar imagenes desde la SD
int ASCII_Hex(int a);

extern uint8_t cowboysp[]; // cargar bitmap desde memoria flash
int arriba = 0;            //Definicion de variables
int arriba2 = 0;
int inicio = 0;
int elegir = 0;
int reb1 = 1;
int reb2 = 1;
int reb3 = 1;
int menu = 0;
int start = 0;
int b1 = 0;
int b2 = 0;
int win = 0;
int endg = 0;
int endg2 = 0;
File ARCH;
uint8_t maps[640];
struct Sprite { // estructura para sprites
  int x; // posicion x
  int y; // posicion y
  int width; // ancho de bitmap
  int height; // altura de bitmap
  int columns; // columna sprite sheet
  int index; // indice sprite sheet
  int flip; // voltear imagen
  int offset; // desfase
} cowboy, cowboy2;

struct Rectangle{ // estructura para rectangulos
  int x; // posicion x
  int y; // posicion y
  int width; // ancho de rectángulo
  int height; // altura de rectángulo
  int color; // color de relleno  
} rect, rect2;


bool collision = false; // detección de colisión
bool collision2 = false; // detección de colisión

unsigned long previousMillis = 0;  
const long interval = 42;
//***************************************************************************************************************************************
// Initialization
//***************************************************************************************************************************************
void setup() {
  SysCtlClockSet(SYSCTL_SYSDIV_2_5|SYSCTL_USE_PLL|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);     //Inicializacion de la comunicación SPI
  Serial.begin(9600);
  GPIOPadConfigSet(GPIO_PORTB_BASE, 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7, GPIO_STRENGTH_8MA, GPIO_PIN_TYPE_STD_WPU);
  SPI.setModule(0);       //Set SPI module for the SD Card
  Serial.print("Initializing SD card...");
  //Check for correct SD Init
  if (!SD.begin(PA_3)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
  //Begin LCD init
  Serial.println("Start");
  LCD_Init();                           //Inicializacion de la pantalla
  LCD_Clear(0x00);

  FSD("f1.txt");                        //Desplegamos el primer fondo
  pinMode(PUSH1, INPUT_PULLUP); // botones integrados con como entrada pull-up    //Definimos los puertos
  pinMode(PUSH2, INPUT_PULLUP);
  pinMode(PA_6, INPUT_PULLUP);
  pinMode(PA_7, INPUT_PULLUP);
  pinMode(PD_7, INPUT_PULLUP);
  pinMode(PC_4, INPUT_PULLUP);
  pinMode(PC_7, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PUSH1), selection, CHANGE);               //Activamos las interrupciones
  attachInterrupt(digitalPinToInterrupt(PUSH2), selection, CHANGE);
  attachInterrupt(digitalPinToInterrupt(PA_7), opc, CHANGE);
  cowboy.x = 33;                                                                  //Configuramos las estructuras
  cowboy.y = 100;
  cowboy.width = 15;
  cowboy.height = 15;
  cowboy.columns = 4;
  cowboy.index = 0;
  cowboy.flip = 0;
  cowboy.offset = 0;

  cowboy2.x = 271;
  cowboy2.y = 100;
  cowboy2.width = 15;
  cowboy2.height = 15;
  cowboy2.columns = 4;
  cowboy2.index = 0;
  cowboy2.flip = 1;
  cowboy2.offset = 0;

  rect.x = 49;
  rect.y = cowboy.y+7;
  rect.width = 7;
  rect.height = 7;
  rect.color = 0x07E0;
  
  rect2.x = 275;
  rect2.y = cowboy2.y+7;
  rect2.width = 7;
  rect2.height = 7;
  rect2.color = 0x07E0;
  inicio = 0;

  //FillRect(unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned int c)    //Configuramos los mensajes a desplegar en el menu principal
  FillRect(142, 55, 128, 30, 0x9904);
  String textitulo = "Cowboys";
  LCD_Print(textitulo, 150, 62, 2, 0x9904 , 0xBCCE);

  FillRect(168, 105, 48, 20, 0x9904);
  String textjugar = "Jugar";
  LCD_Print(textjugar, 172, 109, 1, 0x9904, 0xBCCE);

  FillRect(168, 135, 72, 20, 0x9904);
  String textcreditos = "Creditos";
  LCD_Print(textcreditos, 172, 139, 1, 0x9904, 0xBCCE);

  
  FillRect(168, 165, 130, 20, 0x9904);
  String textmf = "Mas Informacion";
  LCD_Print(textmf, 172, 169, 1, 0x9904, 0xBCCE);

  elegir = 0;
}

//***************************************************************************************************************************************
// Interrupciones
//***************************************************************************************************************************************
void selection() {                          //Antirrebotes del boton 1 para elegir la opcion en el menu principal
  if(digitalRead(PUSH1) == 1){
    reb1 = 1;}
    if(digitalRead(PUSH1)==0 && reb1 == 1){
      if(elegir >= 2){
       
       elegir = 0;
      }
      else{
        elegir++;}
        reb1 = 0;
        }
     
  if(digitalRead(PUSH2)==1){                //Antirrebotes del boton 2 para elegir la opcion en el menu principal
    reb2 = 1;}
    if(digitalRead(PUSH2)==0 && reb2 == 1){
      if(elegir <= 0){
       elegir = 2;
      }
      else{
        elegir--;
        }
        reb2 = 0;}

 switch(elegir){
      case 0:{                             //Si la opcion esta en 0 marcar Jugar
        
        String textjugar = "Jugar";
        LCD_Print(textjugar, 172, 109, 1, 0xBCCE, 0x0000);

        String textcreditos = "Creditos";
        LCD_Print(textcreditos, 172, 139, 1, 0x9904, 0xBCCE);

        String textmf = "Mas Informacion";
        LCD_Print(textmf, 172, 169, 1, 0x9904, 0xBCCE);
        menu = 3;
      break;}
      
      case 1:{                         //Si la opcion esta en 1 marcar Créditos
        
        String textjugar = "Jugar";
        LCD_Print(textjugar, 172, 109, 1, 0x9904, 0xBCCE);
        
        String textcreditos = "Creditos";
        LCD_Print(textcreditos, 172, 139, 1, 0xBCCE, 0x0000);

        String textmf = "Mas Informacion";
        LCD_Print(textmf, 172, 169, 1, 0x9904, 0xBCCE);
        menu = 2;
      break;}
      
      case 2:{                           //Si la opcion esta en 2 marcar Mas informacion
        
        String textjugar = "Jugar";
        LCD_Print(textjugar, 172, 109, 1, 0x9904, 0xBCCE);
      
        String textcreditos = "Creditos";
        LCD_Print(textcreditos, 172, 139, 1, 0x9904, 0xBCCE);
        
        String textmf = "Mas Informacion";
        LCD_Print(textmf, 172, 169, 1, 0xBCCE  , 0x0000);
        menu = 1;
      break;}
    }
}


void opc() {
  if(digitalRead(PA_7) == 1){             //Antirrebote para el boton OK
    reb3 = 1;}
    if(digitalRead(PA_7)==0 && reb3 == 1){
      switch (menu){
        case 0:{
          menu = 4;
          win = 0;
        break;}

        case 1:{                          //En el caso 1 ir a la opcion de mas informacion, desplegar otro fondo y mostrar el siguiente mensaje
        //Mas informacion
        FSD("f2.txt");
        String textmr = "Para mas recursos visitar:";
        LCD_Print(textmr, 60, 100, 1, 0x00FF, 0x0000);
        
        String textgit = "https://github.com/cas19700/LABDIGITAL";
        LCD_Print(textgit, 10, 120, 1, 0x00FF, 0x0000);
        menu = 4;
        detachInterrupt(digitalPinToInterrupt(PUSH1));      //Desactivar interrupciones de los botones que no se utilicen
        detachInterrupt(digitalPinToInterrupt(PUSH2));
        break;}

        case 2:{                                            //En el caso 2 mostrar otro fondo y mostrar los nombres de los creadores
        //Creditos
        FSD("f3.txt");                        
        String textcrea = "Creadores:";
        LCD_Print(textcrea, 85, 100, 2, 0x06C0, 0x0000);
        String textb = "Brayan Castillo";
        LCD_Print(textb, 110, 120, 1, 0x06C0, 0x0000);
        String texto = "Oscar Fuentes";
        LCD_Print(texto, 110, 140, 1, 0x06C0, 0x0000);
        menu = 4;
        detachInterrupt(digitalPinToInterrupt(PUSH1));      //Desactivar interrupciones que no se utilicen
        detachInterrupt(digitalPinToInterrupt(PUSH2));
        break;}

        
        case 3:{
        //Juego
        detachInterrupt(digitalPinToInterrupt(PUSH1));      //Desactivar interrupciones
        detachInterrupt(digitalPinToInterrupt(PUSH2));
        
        inicio = 1;                                         //Iniciar el juego
        menu = 0;
        break;}

        
        case 4:{                                            //Regreso al menu principal para elegir la opcion
        start = 0;
        win = 0;
        endg = 0;
        endg2 = 0;
        b1 = 0;
        b2 = 0;
        inicio = 0;
        cowboy.x = 33;                                      //Configuramos las estructuras con los valores deseados
        cowboy.y = 100;
        cowboy.width = 15;
        cowboy.height = 15;
        cowboy.columns = 4;
        cowboy.index = 0;
        cowboy.flip = 0;
        cowboy.offset = 0;
      
        cowboy2.x = 271;
        cowboy2.y = 100;
        cowboy2.width = 15;
        cowboy2.height = 15;
        cowboy2.columns = 4;
        cowboy2.index = 0;
        cowboy2.flip = 1;
        cowboy2.offset = 0;
      
        rect.x = 49;
        rect.y = cowboy.y+7;
        rect.width = 7;
        rect.height = 7;
        rect.color = 0x07E0;

        rect2.x = 275;
        rect2.y = cowboy2.y+7;
        rect2.width = 7;
        rect2.height = 7;
        rect2.color = 0x07E0;
        attachInterrupt(digitalPinToInterrupt(PUSH1), selection, CHANGE); //Activamos interrupciones para el menu
        attachInterrupt(digitalPinToInterrupt(PUSH2), selection, CHANGE);
        attachInterrupt(digitalPinToInterrupt(PA_7), opc, CHANGE);
        FSD("f1.txt");
        //FillRect(unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned int c)      //Desplegamos el menu con sus mensajes
        FillRect(142, 55, 128, 30, 0x9904);
        String textitulo = "Cowboys";
        LCD_Print(textitulo, 150, 62, 2, 0x9904 , 0xBCCE);
      
        FillRect(168, 105, 48, 20, 0x9904);
        String textjugar = "Jugar";
        LCD_Print(textjugar, 172, 109, 1, 0x9904, 0xBCCE);
      
        FillRect(168, 135, 72, 20, 0x9904);
        String textcreditos = "Creditos";
        LCD_Print(textcreditos, 172, 139, 1, 0x9904, 0xBCCE);
      
        
        FillRect(168, 165, 130, 20, 0x9904);
        String textmf = "Mas Informacion";
        LCD_Print(textmf, 172, 169, 1, 0x9904, 0xBCCE);
      
        elegir = 0;
        break;}
        }
        reb3 = 0;
        }}

//***************************************************************************************************************************************
// Loop
//***************************************************************************************************************************************
void loop() {
  

  if(inicio){
  //FillRect(unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned int c)              //Generamos el mapa donde se llevara acabo el videojuego
  FillRect(0, 0, 320, 240, 0x0000);
  
  //LCD_Bitmap(unsigned int x, unsigned int y, unsigned int width, unsigned int height, unsigned char bitmap[]);
   for(int x = 0; x <319; x++){
    LCD_Bitmap(x, 0, 16, 15, tile  );
    LCD_Bitmap(x, 15, 16, 15, tile);
    LCD_Bitmap(x, 30, 16, 15, tile);
    LCD_Bitmap(x, 210, 16, 15, tile);
    LCD_Bitmap(x, 225, 16, 15, tile);
    x += 16;
 }

  for(int y = 0; y <239; y++){
    LCD_Bitmap(0, y, 16, 15, tile);
    LCD_Bitmap(16, y, 16, 15, tile);
    LCD_Bitmap(288, y, 16, 15, tile);
    LCD_Bitmap(304, y, 16, 15, tile);
    y += 15;
 }
 //LCD_Print(String text, int x, int y, int fontSize, int color, int background)      //Diferenciamos con nombres al jugador 1 y jugador 2
   String text1 = "P1";
  LCD_Print(text1, 68, 0, 2, 0xffff, 0x0000);
    String text2 = "P2";
  LCD_Print(text2, 222, 0, 2, 0xffff, 0x0000);

  
                                                    //Desplegamos la vida de los personajes
    LCD_Bitmap(68, 30, 16, 15, vida);
    
    LCD_Bitmap(238, 30, 16, 15, vida);
   
    start = true;                                                                        //Empezamos el juego
  }
  

  if(start){
  unsigned long currentMillis = millis();
  rect.color = 0x6B8D;
  rect2.color = 0x6B8D;
  rect.y = cowboy.y+7;
  rect2.y = cowboy2.y+7;
  // actualización de frame cada 42ms = 24fps
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
      bool up = !digitalRead(PUSH1); // lectura de entradas
      bool down = !digitalRead(PUSH2);
      bool up2 = !digitalRead(PC_4); // lectura de entradas
      bool down2 = !digitalRead(PD_7);
      bool s1 = !digitalRead(PA_6);
      bool s2 = !digitalRead(PC_7);
    if (down && cowboy.y < 192) { // modificación de atributos de sprite del vaquero 1 abajo
      cowboy.y += 4;
      cowboy.index++;
      cowboy.index %= 3;
      cowboy.flip = 0;
      arriba = 0;
    }
    if (down2 && cowboy2.y < 192) { // modificación de atributos de sprite del vaquero 2 abajo
      cowboy2.y += 4;
      cowboy2.index++;
      cowboy2.index %= 3;
      cowboy2.flip = 1;
      arriba2 = 0;
    }
    if (up && cowboy.y > 48) { // modificación de atributos de sprite del vaquero 1 arriba
      cowboy.y -= 4;
      cowboy.index++;
      cowboy.index %= 3;
      cowboy.flip = 0;
      arriba = 1;
    }
    
    if (up2 && cowboy2.y > 48) { // modificación de atributos de sprite del vaquero 2 arriba
      cowboy2.y -= 4;
      cowboy2.index++;
      cowboy2.index %= 3;
      cowboy2.flip = 1;
      arriba2 = 1;
    }
     
    if(b1 == 1){
    FillRect(rect.x, rect.y, rect.width, rect.height, rect.color);
    FillRect(rect.x  - 5, rect.y-rect.height, 8, rect.height*3, 0x0000); // se colorea resto de rectángulo del frame anterior
      rect.x+= 5;
    }
    
    if(s1){
      b1 = 1;
      }
 

    if(rect.x > 280){                                                //Desaparecer bala en caso no le de al vaquero contrario
      rect.x = 49;
      b1 = 0;
      FillRect(278, rect.y, rect.width+1, rect.height, 0x0000);
      }
    
    collision = Collision(cowboy2.x, cowboy2.y, cowboy2.width, cowboy2.height,
                          rect.x, rect.y, rect.width, rect.height); // detección de colisión
    if (collision) {                                                // se reemplaza el color al colisionar
      if(endg == 0){
      b1 = 0;
      win = 1;
      endg = 1;
      FillRect(rect.x-rect.width, rect.y, rect.width, rect.height, 0x0000);
    }}

    if(b2 == 1){                                                      //Desaparecer bala en caso no le de al vaquero contrario
    FillRect(rect2.x, rect2.y, rect2.width, rect2.height, rect2.color);
    FillRect(rect2.x  + 5, rect2.y-rect.height, 8, rect2.height*3, 0x0000); // se colorea resto de rectángulo del frame anterior
    rect2.x-= 5;
    }
    
    if(s2){
      b2 = 1;
      }

    if(rect2.x < 31){
      rect2.x = 275;
      b2 = 0;
      FillRect(35, rect2.y, rect2.width+1, rect2.height, 0x0000);
      }
    
    collision2 = Collision(cowboy.x, cowboy.y, cowboy.width, cowboy.height,
                          rect2.x, rect2.y, rect2.width, rect2.height); // detección de colisión
    if (collision2) { // se reemplaza el color al colisionar
      //rect.color = 0xF800;
      if(endg2 == 0){
      b2 = 0;
      win = 2;
      endg2 = 1;
      FillRect(rect2.x-rect2.width, rect2.y, rect2.width, rect2.height, 0x0000);
    }}
     
    if(win == 1){                                     //Gana el Jugador 1, desplegar mensaje
      FillRect(238, 30, 16, 15, 0x0000);
      String textg1 = "Gano el Jugador 1";
      LCD_Print(textg1, 25, 50, 2, 0x9904, 0xFF85);
      String textok = "Presiones OK 2 veces";
      LCD_Print(textok, 85, 120, 1, 0x9904, 0xFF85);
      String textcont = "Para Continuar";
      LCD_Print(textcont, 110, 140, 1, 0x9904, 0xFF85);
      endg = 1;
      endg2 = 1;
      win = 0;
      start = false;
      }
      
    else if(win == 2){                                //Gana el Jugador 2, desplegar mensaje
      FillRect(68, 30, 16, 15, 0x0000);
      String textg2 = "Gano el Jugador 2";
      LCD_Print(textg2, 25, 50, 2, 0x9904, 0xFF85);
      String textok = "Presiones OK 2 veces";
      LCD_Print(textok, 85, 120, 1, 0x9904, 0xFF85);
      String textcont = "Para Continuar";
      LCD_Print(textcont, 110, 140, 1, 0x9904, 0xFF85);
      endg = 1;
      endg2 = 1;
      win = 0;
      start = false;
      }
      else{
    
    if (arriba == 0){ // dependiendo de la dirección, se colorea resto del sprite del frame anterior vaquero 1
      FillRect(cowboy.x, cowboy.y - 4 , cowboy.width, 4, 0x0000);
    }
    else{
      FillRect(cowboy.x, cowboy.y + cowboy.height, cowboy.width, 4, 0x0000);
    }

    if (arriba2 == 0){ // dependiendo de la dirección, se colorea resto del sprite del frame anterior vaquero 2
      FillRect(cowboy2.x, cowboy2.y - 4 , cowboy2.width, 4, 0x0000);
    }
    else{
      FillRect(cowboy2.x, cowboy2.y + cowboy2.height, cowboy2.width, 4, 0x0000);
    }
    
    LCD_Sprite(cowboy.x, cowboy.y, cowboy.width, cowboy.height, cowboysp, cowboy.columns, cowboy.index, cowboy.flip, cowboy.offset);        //Desplegamos ambos sprites
    LCD_Sprite(cowboy2.x, cowboy2.y, cowboy2.width, cowboy2.height, cowboysp, cowboy2.columns, cowboy2.index, cowboy2.flip, cowboy.offset);
    inicio = 0;
  }}
    
}

}
//***************************************************************************************************************************************
// Función para el mapeo de las imagenes
//***************************************************************************************************************************************
void FSD(char x[]){
  ARCH = SD.open(x, FILE_READ);  //Abrir la imagen
  int hex = 0;
  int v1 = 0;
  int v2 = 0;
  int mapar = 0;
  int vert = 0;
  if(ARCH){                      //Si se abrio
    Serial.println("Leyendo el archivo...");
    while(vert <= 239){
      mapar = 0;
      while (mapar<640){
        hex = ARCH.read();
        if(hex==120){        //Comprobar que este en el rango
          v1 = ARCH.read();  //Leer los valores
          v2 = ARCH.read();
          v1 = ASCII_Hex(v1);
          v2 = ASCII_Hex(v2);
          maps[mapar] = (v1*16)+v2;
          mapar++;
        }
      }
      LCD_Bitmap(0, vert, 320, 1 , maps);
      vert++;
    }
    ARCH.close();
  }
  else{
    Serial.println("No se pudo encontrar el archivo");
    ARCH.close();
  }
}
//***************************************************************************************************************************************
// Función para pasar de ASCCI a HEX
//***************************************************************************************************************************************
int ASCII_Hex(int a){
  switch(a){
    case 48:
      return 0;
    case 49:
      return 1;
      case 50:
      return 2;
    case 51:
      return 3;
      case 52:
      return 4;
    case 53:
      return 5;
      case 54:
      return 6;
    case 55:
      return 7;
      case 56:
      return 8;
    case 57:
      return 9;
      case 97:
      return 10;
    case 98:
      return 11;
    case 99:
      return 12;
    case 100:
      return 13;
    case 101:
      return 14;
    case 102:
      return 15;
    default:
      return 0;
  }
}
//***************************************************************************************************************************************
// Función para inicializar LCD
//***************************************************************************************************************************************
void LCD_Init(void) {
  pinMode(LCD_RST, OUTPUT);
  pinMode(LCD_CS, OUTPUT);
  pinMode(LCD_RS, OUTPUT);
  pinMode(LCD_WR, OUTPUT);
  pinMode(LCD_RD, OUTPUT);
  for (uint8_t i = 0; i < 8; i++){
    pinMode(DPINS[i], OUTPUT);
  }
  //****************************************
  // Secuencia de Inicialización
  //****************************************
  digitalWrite(LCD_CS, HIGH);
  digitalWrite(LCD_RS, HIGH);
  digitalWrite(LCD_WR, HIGH);
  digitalWrite(LCD_RD, HIGH);
  digitalWrite(LCD_RST, HIGH);
  delay(5);
  digitalWrite(LCD_RST, LOW);
  delay(20);
  digitalWrite(LCD_RST, HIGH);
  delay(150);
  digitalWrite(LCD_CS, LOW);
  //****************************************
  LCD_CMD(0xE9);  // SETPANELRELATED
  LCD_DATA(0x20);
  //****************************************
  LCD_CMD(0x11); // Exit Sleep SLEEP OUT (SLPOUT)
  delay(100);
  //****************************************
  LCD_CMD(0xD1);    // (SETVCOM)
  LCD_DATA(0x00);
  LCD_DATA(0x71);
  LCD_DATA(0x19);
  //****************************************
  LCD_CMD(0xD0);   // (SETPOWER) 
  LCD_DATA(0x07);
  LCD_DATA(0x01);
  LCD_DATA(0x08);
  //****************************************
  LCD_CMD(0x36);  // (MEMORYACCESS)
  LCD_DATA(0x40|0x80|0x20|0x08); // LCD_DATA(0x19);
  //****************************************
  LCD_CMD(0x3A); // Set_pixel_format (PIXELFORMAT)
  LCD_DATA(0x05); // color setings, 05h - 16bit pixel, 11h - 3bit pixel
  //****************************************
  LCD_CMD(0xC1);    // (POWERCONTROL2)
  LCD_DATA(0x10);
  LCD_DATA(0x10);
  LCD_DATA(0x02);
  LCD_DATA(0x02);
  //****************************************
  LCD_CMD(0xC0); // Set Default Gamma (POWERCONTROL1)
  LCD_DATA(0x00);
  LCD_DATA(0x35);
  LCD_DATA(0x00);
  LCD_DATA(0x00);
  LCD_DATA(0x01);
  LCD_DATA(0x02);
  //****************************************
  LCD_CMD(0xC5); // Set Frame Rate (VCOMCONTROL1)
  LCD_DATA(0x04); // 72Hz
  //****************************************
  LCD_CMD(0xD2); // Power Settings  (SETPWRNORMAL)
  LCD_DATA(0x01);
  LCD_DATA(0x44);
  //****************************************
  LCD_CMD(0xC8); //Set Gamma  (GAMMASET)
  LCD_DATA(0x04);
  LCD_DATA(0x67);
  LCD_DATA(0x35);
  LCD_DATA(0x04);
  LCD_DATA(0x08);
  LCD_DATA(0x06);
  LCD_DATA(0x24);
  LCD_DATA(0x01);
  LCD_DATA(0x37);
  LCD_DATA(0x40);
  LCD_DATA(0x03);
  LCD_DATA(0x10);
  LCD_DATA(0x08);
  LCD_DATA(0x80);
  LCD_DATA(0x00);
  //****************************************
  LCD_CMD(0x2A); // Set_column_address 320px (CASET)
  LCD_DATA(0x00);
  LCD_DATA(0x00);
  LCD_DATA(0x01);
  LCD_DATA(0x3F);
  //****************************************
  LCD_CMD(0x2B); // Set_page_address 480px (PASET)
  LCD_DATA(0x00);
  LCD_DATA(0x00);
  LCD_DATA(0x01);
  LCD_DATA(0xE0);
//  LCD_DATA(0x8F);
  LCD_CMD(0x29); //display on 
  LCD_CMD(0x2C); //display on

  LCD_CMD(ILI9341_INVOFF); //Invert Off
  delay(120);
  LCD_CMD(ILI9341_SLPOUT);    //Exit Sleep
  delay(120);
  LCD_CMD(ILI9341_DISPON);    //Display on
  digitalWrite(LCD_CS, HIGH);
}
//***************************************************************************************************************************************
// Función para enviar comandos a la LCD - parámetro (comando)
//***************************************************************************************************************************************
void LCD_CMD(uint8_t cmd) {
  digitalWrite(LCD_RS, LOW);
  digitalWrite(LCD_WR, LOW);
  GPIO_PORTB_DATA_R = cmd;
  digitalWrite(LCD_WR, HIGH);
}
//***************************************************************************************************************************************
// Función para enviar datos a la LCD - parámetro (dato)
//***************************************************************************************************************************************
void LCD_DATA(uint8_t data) {
  digitalWrite(LCD_RS, HIGH);
  digitalWrite(LCD_WR, LOW);
  GPIO_PORTB_DATA_R = data;
  digitalWrite(LCD_WR, HIGH);
}
//***************************************************************************************************************************************
// Función para definir rango de direcciones de memoria con las cuales se trabajara (se define una ventana)
//***************************************************************************************************************************************
void SetWindows(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2) {
  LCD_CMD(0x2a); // Set_column_address 4 parameters
  LCD_DATA(x1 >> 8);
  LCD_DATA(x1);   
  LCD_DATA(x2 >> 8);
  LCD_DATA(x2);   
  LCD_CMD(0x2b); // Set_page_address 4 parameters
  LCD_DATA(y1 >> 8);
  LCD_DATA(y1);   
  LCD_DATA(y2 >> 8);
  LCD_DATA(y2);   
  LCD_CMD(0x2c); // Write_memory_start
}
//***************************************************************************************************************************************
// Función para borrar la pantalla - parámetros (color)
//***************************************************************************************************************************************
void LCD_Clear(unsigned int c){  
  unsigned int x, y;
  LCD_CMD(0x02c); // write_memory_start
  digitalWrite(LCD_RS, HIGH);
  digitalWrite(LCD_CS, LOW);   
  SetWindows(0, 0, 319, 239); // 479, 319);
  for (x = 0; x < 320; x++)
    for (y = 0; y < 240; y++) {
      LCD_DATA(c >> 8); 
      LCD_DATA(c); 
    }
  digitalWrite(LCD_CS, HIGH);
} 
//***************************************************************************************************************************************
// Función para dibujar una línea horizontal - parámetros ( coordenada x, cordenada y, longitud, color)
//*************************************************************************************************************************************** 
void H_line(unsigned int x, unsigned int y, unsigned int l, unsigned int c) {  
  unsigned int i, j;
  LCD_CMD(0x02c); //write_memory_start
  digitalWrite(LCD_RS, HIGH);
  digitalWrite(LCD_CS, LOW);
  l = l + x;
  SetWindows(x, y, l, y);
  j = l;// * 2;
  for (i = 0; i < l; i++) {
      LCD_DATA(c >> 8); 
      LCD_DATA(c); 
  }
  digitalWrite(LCD_CS, HIGH);
}
//***************************************************************************************************************************************
// Función para dibujar una línea vertical - parámetros ( coordenada x, cordenada y, longitud, color)
//*************************************************************************************************************************************** 
void V_line(unsigned int x, unsigned int y, unsigned int l, unsigned int c) {  
  unsigned int i,j;
  LCD_CMD(0x02c); //write_memory_start
  digitalWrite(LCD_RS, HIGH);
  digitalWrite(LCD_CS, LOW);
  l = l + y;
  SetWindows(x, y, x, l);
  j = l; //* 2;
  for (i = 1; i <= j; i++) {
    LCD_DATA(c >> 8); 
    LCD_DATA(c);
  }
  digitalWrite(LCD_CS, HIGH);  
}
//***************************************************************************************************************************************
// Función para dibujar un rectángulo - parámetros ( coordenada x, cordenada y, ancho, alto, color)
//***************************************************************************************************************************************
void Rect(unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned int c) {
  H_line(x  , y  , w, c);
  H_line(x  , y+h, w, c);
  V_line(x  , y  , h, c);
  V_line(x+w, y  , h, c);
}
//***************************************************************************************************************************************
// Función para dibujar un rectángulo relleno - parámetros ( coordenada x, cordenada y, ancho, alto, color)
//***************************************************************************************************************************************
void FillRect(unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned int c) {
  LCD_CMD(0x02c); // write_memory_start
  digitalWrite(LCD_RS, HIGH);
  digitalWrite(LCD_CS, LOW); 
  
  unsigned int x2, y2;
  x2 = x+w;
  y2 = y+h;
  SetWindows(x, y, x2-1, y2-1);
  unsigned int k = w*h*2-1;
  unsigned int i, j;
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      LCD_DATA(c >> 8);
      LCD_DATA(c); 
      k = k - 2;
     } 
  }
  digitalWrite(LCD_CS, HIGH);
}
//***************************************************************************************************************************************
// Función para dibujar texto - parámetros ( texto, coordenada x, cordenada y, color, background) 
//***************************************************************************************************************************************
void LCD_Print(String text, int x, int y, int fontSize, int color, int background) {
  int fontXSize ;
  int fontYSize ;
  
  if(fontSize == 1){
    fontXSize = fontXSizeSmal ;
    fontYSize = fontYSizeSmal ;
  }
  if(fontSize == 2){
    fontXSize = fontXSizeBig ;
    fontYSize = fontYSizeBig ;
  }
  
  char charInput ;
  int cLength = text.length();
  Serial.println(cLength,DEC);
  int charDec ;
  int c ;
  int charHex ;
  char char_array[cLength+1];
  text.toCharArray(char_array, cLength+1) ;
  for (int i = 0; i < cLength ; i++) {
    charInput = char_array[i];
    Serial.println(char_array[i]);
    charDec = int(charInput);
    digitalWrite(LCD_CS, LOW);
    SetWindows(x + (i * fontXSize), y, x + (i * fontXSize) + fontXSize - 1, y + fontYSize );
    long charHex1 ;
    for ( int n = 0 ; n < fontYSize ; n++ ) {
      if (fontSize == 1){
        charHex1 = pgm_read_word_near(smallFont + ((charDec - 32) * fontYSize) + n);
      }
      if (fontSize == 2){
        charHex1 = pgm_read_word_near(bigFont + ((charDec - 32) * fontYSize) + n);
      }
      for (int t = 1; t < fontXSize + 1 ; t++) {
        if (( charHex1 & (1 << (fontXSize - t))) > 0 ) {
          c = color ;
        } else {
          c = background ;
        }
        LCD_DATA(c >> 8);
        LCD_DATA(c);
      }
    }
    digitalWrite(LCD_CS, HIGH);
  }
}
//***************************************************************************************************************************************
// Función para dibujar una imagen a partir de un arreglo de colores (Bitmap) Formato (Color 16bit R 5bits G 6bits B 5bits)
//***************************************************************************************************************************************
void LCD_Bitmap(unsigned int x, unsigned int y, unsigned int width, unsigned int height, unsigned char bitmap[]){  
  LCD_CMD(0x02c); // write_memory_start
  digitalWrite(LCD_RS, HIGH);
  digitalWrite(LCD_CS, LOW); 
  
  unsigned int x2, y2;
  x2 = x+width;
  y2 = y+height;
  SetWindows(x, y, x2-1, y2-1);
  unsigned int k = 0;
  unsigned int i, j;

  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      LCD_DATA(bitmap[k]);
      LCD_DATA(bitmap[k+1]);
      //LCD_DATA(bitmap[k]);    
      k = k + 2;
     } 
  }
  digitalWrite(LCD_CS, HIGH);
}
//***************************************************************************************************************************************
// Función para dibujar una imagen sprite - los parámetros columns = número de imagenes en el sprite, index = cual desplegar, flip = darle vuelta
//***************************************************************************************************************************************
void LCD_Sprite(int x, int y, float width, int height, unsigned char bitmap[],int columns, int index, char flip, char offset){
  LCD_CMD(0x02c); // write_memory_start
  digitalWrite(LCD_RS, HIGH);
  digitalWrite(LCD_CS, LOW); 

  unsigned int x2, y2;
  x2 =   x+width;
  y2=    y+height;
  SetWindows(x, y, x2-1, y2-1);
  int k = 0;
  int ancho = ((width*columns));
  if(flip){
    for (int j = 0; j < height; j++){
        k = (j*(ancho) + index*width -1 - offset)*2;
        k = k+width*2;
       for (int i = 0; i < width; i++){
        LCD_DATA(bitmap[k]);
        LCD_DATA(bitmap[k+1]);
        k = k - 2;
       } 
    }
  }
  else{
     for (int j = 0; j < height; j++){
      k = (j*(ancho) + index*width + 1 + offset)*2;
     for (int i = 0; i < width; i++){
      LCD_DATA(bitmap[k]);
      LCD_DATA(bitmap[k+1]);
      k = k + 2;
     } 
    }
  }
  digitalWrite(LCD_CS, HIGH);
}
bool Collision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2){
  return (x1 < x2 + w2) && (x1+ w1 > x2) && (y1 < y2 + h2) && (y1 + h1 > y2);
}
