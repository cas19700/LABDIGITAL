// Ejercicio 2 Flip Flop tipo D de 1 bit

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

// Ejercicio 2 Flip Flop tipo T

module FFT(input clk , input reset, E, input d1, output wire q1);
  wire dn = ~d1;
  FFD1 M1(clk, reset, E, dn, q1);
endmodule
