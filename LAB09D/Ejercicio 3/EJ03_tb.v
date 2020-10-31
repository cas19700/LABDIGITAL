module testbench();
	reg clk, reset;
	reg J, K, E;
	wire Q;

	FFJK P1(clk, reset, E, J, K, Q);

	initial begin
	clk = 0; reset = 0; J = 0; K = 0; E = 0;
	#1 reset = 1; E=1;
  #1 reset = 0;
  #2 J=0; K=0;
  #2 J=1; K=0;
  #2 J=0; K=0;
  #2 J=0; K=1;
  #2 J=0; K=0;
  #2 J=1; K=1;

	end
	always
    #1 clk = ~clk;
	initial
    #20 $finish;
	initial begin
    $dumpfile("EJ03_tb.vcd");
    $dumpvars(0, testbench);
	end

endmodule
