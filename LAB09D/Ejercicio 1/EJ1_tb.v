module testbench();
	reg clk, reset;
	reg D, E;
  reg [1:0]D1;
  reg [3:0]D2;
	wire Q;
  wire [1:0]Q1;
  wire [3:0]Q2;

	FFD1 P1(clk, reset, E, D, Q);
  FFD2 P2(clk, reset, E, D1, Q1);
  FFD4 P3(clk, reset, E, D2, Q2);

	initial begin
	clk = 0; reset = 0; D=0; D1=2'b00; D2=4'b0000; E=0;
	#1 reset = 1;
  #1 reset = 0;
  #1 D=1; D1=2'b01; D2=4'b0001; E=1;
  #2 D=0; D1=2'b10; D2=4'b0010;
  #1 D=0; D1=2'b11; D2=4'b0011;
  #1 D=1; D1=2'b00; D2=4'b0100;
  #1 D=1; D1=2'b01; D2=4'b0101;
  #1 D=0; D1=2'b10; D2=4'b0110;
  #1 D=1; D1=2'b11; D2=4'b0111;
  #1 D=0; D1=2'b00; D2=4'b1000;
  #1 D=1; D1=2'b01; D2=4'b1001;
  #1 D=0; D1=2'b10; D2=4'b1010;
  #1 D=1; D1=2'b11; D2=4'b1011;
  #1 D=0; D1=2'b00; D2=4'b1100;
  #1 D=1; D1=2'b01; D2=4'b1101;
  #1 D=0; D1=2'b10; D2=4'b1110;
  #1 D=1; D1=2'b11; D2=4'b1111;
	end
	always
    #1 clk = ~clk;
	initial
    #20 $finish;
	initial begin
    $dumpfile("EJ1_tb.vcd");
    $dumpvars(0, testbench);
	end

endmodule
