module testbench();
  reg [6:0]IN;
  wire[12:0]OTP;

	ROM P1(IN, OTP);

	initial begin
	IN = 0;
	#1 IN = 7'b0000000;
  #1 IN = 7'b0000101;
  #1 IN = 7'b0000001;
  #1 IN = 7'b0001101;
  #1 IN = 7'b0001001;
  #1 IN = 7'b0010001;
  #1 IN = 7'b0011001;
  #1 IN = 7'b0100001;
  #1 IN = 7'b0101001;
  #1 IN = 7'b0110001;
  #1 IN = 7'b0111001;
  #1 IN = 7'b1000011;
  #1 IN = 7'b1000001;
  #1 IN = 7'b1001011;
  #1 IN = 7'b1001001;
  #1 IN = 7'b1010001;
  #1 IN = 7'b1011001;
  #1 IN = 7'b1100001;
  #1 IN = 7'b1101001;
  #1 IN = 7'b1110001;
  #1 IN = 7'b1111001;
  #1 IN = 7'b0000111;
  #1 IN = 7'b0000011;
  #1 IN = 7'b0001111;
  #1 IN = 7'b0001011;
  #1 IN = 7'b0010111;
	end

	initial
    #30 $finish;
	initial begin
    $dumpfile("EJ5_tb.vcd");
    $dumpvars(0, testbench);
	end
endmodule
