// Ejercicio 1 Flip Flop tipo D de 1 bit

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

// Ejercicio 1 Flip Flop tipo D de 2 bits

module FFD2(input clk , input reset, E, input [1:0]d, output wire [1:0]q);

	FFD1 M1(clk, reset, E, d[0], q[0]);
  FFD1 M2(clk, reset, E, d[1], q[1]);
endmodule

// Ejercicio 1 Flip Flop tipo D de 4 bits

module FFD4(input clk , input reset, E, input [3:0]d, output wire [3:0]q);

	FFD1 G1(clk, reset, E, d[0], q[0]);
  FFD1 G2(clk, reset, E, d[1], q[1]);
  FFD1 G3(clk, reset, E, d[2], q[2]);
  FFD1 G4(clk, reset, E, d[3], q[3]);
endmodule
