// Ejercicio05 Flip Flop tipo D de 4 bits 

module FFD4A(input clk , input reset, input set, input [3:0]d, output reg[3:0]q);

	always@(posedge clk, posedge reset)
	if(reset)q<=4'b0000;
	else 	q<=d;
	
	always@(posedge clk)
	if(set)q<=4'b1111;
	else 	q<=d;
endmodule

