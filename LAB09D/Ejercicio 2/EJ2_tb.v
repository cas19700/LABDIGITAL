module testbench();
	reg clk, reset;
	reg D, E;
	wire Q;

	FFT P1(clk, reset, E, D, Q);

	initial begin
	clk = 0; reset = 0; D=0; E=0;
	#1 reset = 1;
  #1 reset = 0; E=1;
  #1 D=1;
  #1 D=0;
  #1 D=1;
  #1 D=0;

	end
	always
    #2 clk = ~clk;
	initial
    #10 $finish;
	initial begin
    $dumpfile("EJ2_tb.vcd");
    $dumpvars(0, testbench);
	end

endmodule
