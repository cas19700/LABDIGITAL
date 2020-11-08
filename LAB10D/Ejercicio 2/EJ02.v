// Buffer Tri-estado de 4 bits
module BTE(input E, input [3:0]D,  output [3:0]Q);

    assign Q = E==1?D:4'bzzzz;

endmodule

//Flip Flop tipo D de 1 bit

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

//Flip Flop tipo D de 4 bits

module FFD4(input clk , input reset, E, input [3:0]d, output wire [3:0]q);

	FFD1 G1(clk, reset, E, d[0], q[0]);
  FFD1 G2(clk, reset, E, d[1], q[1]);
  FFD1 G3(clk, reset, E, d[2], q[2]);
  FFD1 G4(clk, reset, E, d[3], q[3]);
endmodule

//Modulo de la ALU

module ALU (input [2:0]F,input [3:0]A, B, output reg[3:0]salida, output reg carry, zero);
reg [4:0]CS,CR;
always @(F,A,B) begin
    case(F)
    3'b000: begin
    salida = A;
    carry = 0;
    end
    3'b001: begin
    CR = A-B;
    carry = CR[4];
    salida = A;
    end
    3'b010: begin
    salida = B;
    carry = 0;
    end
    3'b011: begin
    CS = A + B;
    carry = CS[4];
    salida = CS[3:0];
    end
    3'b100: begin
    salida = ~(A & B);
    carry = 0;
    end
    default: salida = A;
  endcase
  end
  always@(salida) begin
  if(salida == 0) begin
  zero = 1;
  end
  else
  zero = 0;
  end

endmodule

//Modulo de conexiones

module EJ02(input clk, reset, enable1, enable2, enable3, input [3:0]entrada, input [2:0]S, output Carry, Zero, output [3:0]salida);

  wire [3:0]data_bus, accu;
  wire [3:0]aluc;

  BTE U1(enable1, entrada,data_bus);
  FFD4 U2(clk, reset, enable2, aluc, accu);
  ALU U3(S, accu, data_bus, aluc, Carry, Zero);
  assign salida = aluc;
endmodule
