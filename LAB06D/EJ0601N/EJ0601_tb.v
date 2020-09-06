module testbench();
	reg clk, reset, A, B;
	wire Q;
	wire [1:0]SF, SP;
	EJ01 D1(clk, reset, A, B, Q, SF, SP);

	initial begin
    $display("\n");
		$display(" Ejercicio 01");
    $display("clk reset A B SF SP | Y");
    $display("--------------------|--");
    $monitor("%b %b %b %b %b %b | %b", clk, reset, A, B, SF, SP, Q);
	end

	initial begin
		clk = 0;
		reset = 0;
		A = 0;
		B = 0;
		#1 reset = 1;
		#1 reset = 0;
		#10
		A = 1;
		B = 0;
		#20
		A = 0;
		B = 0;
	end

	always
    #5 clk = ~clk;

	initial
    #80 $finish;

	initial begin
    $dumpfile("EJ0601_tb.vcd");
    $dumpvars(0, testbench);
	end

endmodule
