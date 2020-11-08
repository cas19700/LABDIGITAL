//Modulo del ProgramCounter
module ProgramCounter(input wire clock, reset, enable, load,
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

//Modulo de la memoria ROM
module ROM(input wire [11:0]address, output wire[7:0]val);

reg[7:0] M[0:4095];
initial begin
  $readmemh("ROMM.list",M);
  end
  assign val = M[address];
endmodule

// Flip Flop tipo D de 1 bit
module FFD1(input clk , input reset, E, input d,  output reg q);

  always@(posedge clk, posedge reset) begin
    if(E == 1) begin
    q <= d;
    end
    if(reset) begin
    q <= 0;
    end
  end
endmodule

//Flip Flop tipo D de 8 bits
module FFD8(input clk , input reset, E, input [7:0]d, output wire [3:0]in, op);

	FFD1 G1(clk, reset, E, d[0], op[0]);
  FFD1 G2(clk, reset, E, d[1], op[1]);
  FFD1 G3(clk, reset, E, d[2], op[2]);
  FFD1 G4(clk, reset, E, d[3], op[3]);
  FFD1 G5(clk, reset, E, d[4], in[0]);
  FFD1 G6(clk, reset, E, d[5], in[1]);
  FFD1 G7(clk, reset, E, d[6], in[2]);
  FFD1 G8(clk, reset, E, d[7], in[3]);
endmodule

//Modulo de conexiones
module EJ01(input clk, reset, enable1, enable2, load, input [11:0]entrada, output [7:0]program_byte, output [3:0]instr, oprnd);

  wire [11:0]PC;
  wire [7:0]programb;

  ProgramCounter U1(clk, reset, enable1, load, entrada, PC);
  ROM U2(PC,programb);
  FFD8 U3(clk, reset, enable2, programb, instr, oprnd);
  assign program_byte = programb;
endmodule
