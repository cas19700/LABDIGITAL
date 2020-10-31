// Ejercicio 3 Flip Flop tipo D de 1 bit

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

// Ejercicio 3 Flip Flop JK de 1 bit

module FFJK(input clk , input reset, E, J, K, output Q);
  wire nK, nQ, w1, w2, D;
  not(nK, K);
  not(nQ, Q);
  and(w1, nK, Q);
  and(w2, nQ, J);
  or (D, w1, w2);

  FFD1 M1(clk, reset, E, D, Q);
endmodule
