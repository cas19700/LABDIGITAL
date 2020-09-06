module testbench();
	reg clk, reset, set;
	reg [0:3]D;
	wire [0:3]Q;
	
	FFD4A G1(clk, reset, set, D, Q);
	
	initial begin
	clk = 0;
	reset = 0;
	set = 0;
		
	#1 clk = 0; reset = 1;
	#1 reset = 0;D = 1;D = 0; 
	#1 set = 1; D = 2;
	#1 D = 3;reset = 1; set = 0;
	#1 D = 4;set = 1;
	#1 D = 5;set = 0;
	#1 D = 6; reset = 0;
	#1 D = 7;set = 1;
	#1 D = 8;set = 0;
	#1 D = 9;reset = 1;
	#1 D = 10;set = 1;
	#1 D = 11;reset = 0;
	#1 D = 12;set = 0;
	#1 D = 13;
	#1 D = 14;reset = 1;
	#1 D = 15;reset = 0;
	end
	always
    #2 clk = ~clk; 
	initial
    #200 $finish;
	initial begin
    $dumpfile("FFD4_tb.vcd");
    $dumpvars(0, testbench);
	end
  
endmodule