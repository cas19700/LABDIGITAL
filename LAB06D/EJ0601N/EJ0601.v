//Flip Flop
module FF (input clk, reset, D, output reg Q);
    always @ (posedge clk or posedge reset)begin
    if (reset)
		Q <= 1'b0;
    else
		Q <= D;
    end
endmodule

//Ejercicio 01 en Verilog
module EJ01(input clck, reset, A, B, output wire Q, output wire [1:0]SF, SP);
        //wire SP0, SP1, SF0, SF1;

        assign SF[0] = (~SP[1] & ~SP[0] & A);
        assign SF[1] = (SP[0] & B) | (SP[1] & A & B);
        assign Q = (SP[1] & ~SP[0] & A & B);

		    FF M1(.clk(clk), .reset(reset), .D(SF[1]), .Q(SP[1]));
		    FF M0(.clk(clk), .reset(reset), .D(SF[0]), .Q(SP[0]));
endmodule
