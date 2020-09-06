//Flip Flop
module FF (input clk, reset, D, output reg Q);
    always @ (posedge clk or posedge reset)begin
    if (reset)
		Q <= 1'b0;
    else
		Q <= D;
    end
endmodule

//Ejercicio 03
module EJ03(input A, clk, reset, output wire Y1, Y2, Y3);
    wire S0, S1, S2, S00, S11, S22;

    assign S00 = (~S1 & ~S0 & ~A) | (S1 & ~S0 & A) | (S2 & S0);
    assign S01 = (~S2 & S0 & A) | (S2 & S0 & ~A) | (S1 & ~S0);
    assign S22 = (~S2 & ~S1 & A) | (S2 & ~S1 & ~A) | (~S2 & S1 & ~A) | (S2 & S1 & A);

    FF U1(clk, reset, S00, S0);
    FF U2(clk, reset, S11, S1);
    FF U3(clk, reset, S22, S2);

    assign Y1 = S0;
    assign Y2 = S1;
    assign Y3 = S2;

endmodule