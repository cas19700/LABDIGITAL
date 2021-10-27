/*
  Codigo Tiva maestro (recibe la data)
  Proyecto juego Cowboys
  Brayan Castillo y Oscar Fuentes
 
*/

//see pins_energia.h for more LED definitions
#define LED GREEN_LED
int inByte;
byte boton1, boton2, boton3, boton4, boton5, boton6, boton7;
void setup() {
  // initialize both serial ports:
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  Serial5.begin(9600);
}

void loop() {
  if (Serial5.available()) {
    inByte = Serial5.read();
    Serial.write(inByte); 
  }

  boton1 = inByte & 1;
  if(boton1 == 0){
    digitalWrite(LED, HIGH);
  }
  else{
    digitalWrite(LED, LOW);
  }
  boton2 = inByte & 2;
  boton2 = boton2 >> 1;
  boton3 = inByte & 4;
  boton3 = boton3 >> 2;
  Serial.print(boton1);
  boton4 = inByte & 8;
  boton4 = boton4 >> 3;
  boton5 = inByte & 16;
  boton5 = boton5 >> 4;
  boton6 = inByte & 32;
  boton6 = boton6 >> 5;
  boton7 = inByte & 64;
  boton7 = boton7 >> 6;


}
