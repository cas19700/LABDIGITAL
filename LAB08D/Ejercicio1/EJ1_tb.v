module testbench();

reg clck, rst, EN, LD;
reg [11:0]INP;
wire [11:0]OTP;
EJ1Contador U1(clck, rst, EN, LD, INP, OTP);

initial begin
clck=0; rst=0; EN=0; LD=0; INP=0;
#1 INP=102; LD=1;
#1 INP=23;
#1 INP=12;
#1 LD=0;
#1 EN = 1;
#3 rst=1;
#1 rst=0;
end
always
#1 clck = ~clck;
initial
#40 $finish;

initial begin

    $dumpfile("EJ1_tb.vcd");
    $dumpvars(0,testbench);
  end
endmodule
