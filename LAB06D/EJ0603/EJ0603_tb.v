module testbench();
	reg clk, reset, A;
	wire Y1, Y2, Y3;
	EJ03 D1(A, clk, reset, Y1, Y2, Y3);
	
	initial begin
    $display("\n");
	$display(" Ejercicio 01");
    $display("clk reset A B SF SP | Y");
    $display("--------------------|--");
    $monitor("%b %b %b %b %b %b | %b", clk, reset, A, Y1, Y2, Y3);
	end
	
	initial begin
	clk = 0;
	reset = 0;
	A = 0;
	#1 reset = 1;
	#1 reset = 0;
	#10
	A = 1;
	#20
	A = 0;
	#30
	A = 1;
	#40
	A = 0;
	#50
	A = 1;
	#60
	A = 0;
	#70
	A = 1;
	end
	always
    #5 clk = ~clk; 
	initial
    #150 $finish;
	initial begin
    $dumpfile("EJ0603_tb.vcd");
    $dumpvars(0, testbench);
	end
  
endmodule