//Creación del modulo
module EJ1Contador(input wire clock, reset, enable, load,
  input wire [11:0]entrada, output [11:0]salida);
//Definir el contador
  reg[11:0]contador;
//Condiciones del contador
  always @ (posedge clock or posedge reset or posedge load) begin
  if(reset)
  contador<=12'd0;
  else if(load)
  contador<=entrada;
  else begin
  //Si el contador esta lleno y enable sigue activado vuelva a 0
  if(contador == 12'b111111111111 & enable == 1)
  contador<=12'd0;
  else if(enable == 1)
  contador <= contador + 12'd1;
  end
  end
  assign salida = contador;
  endmodule
