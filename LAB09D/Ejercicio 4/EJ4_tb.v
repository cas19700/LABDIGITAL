module testbench();
  reg E;
  reg [3:0]D;
  wire[3:0]Q;

	BTE P1(E, D, Q);

	initial begin
	E = 0; D=0;
	#1 E = 1;
  #1 D = 4'b0001;
  #1 D = 4'b0010;
  #1 D = 4'b0011;
  #1 D = 4'b0100;
  #1 D = 4'b0101;
  #1 D = 4'b0110;
  #1 D = 4'b0111;E = 0;
  #1 D = 4'b1000;
  #1 D = 4'b1001;
  #1 D = 4'b1010;
  #1 D = 4'b1011;
  #1 D = 4'b1100;
  #1 D = 4'b1101;E = 1;
  #1 D = 4'b1110;
  #1 D = 4'b1111;
	end

	initial
    #20 $finish;
	initial begin
    $dumpfile("EJ4_tb.vcd");
    $dumpvars(0, testbench);
	end

endmodule
