module testbench();
reg clck, rst, EN1, EN2, LD;
reg [11:0]INP;
wire [7:0]PB;
wire [3:0]INSTR, OPRND;
EJ01 M1(clck, rst, EN1, EN2, LD, INP, PB, INSTR, OPRND);

initial begin
clck=0; rst=0; EN1=0; EN2=0; LD=0; INP=12'b0;
#1 rst=1;
#1 rst=0;
#1 INP=13;
#1 INP=4; LD=1;
#1 LD=0;
#1 EN1=1;
#5 EN1=0;
#1 INP=9; EN2=1; LD=1; EN1=1;
#1 LD=0;
end
always
#1 clck = ~clck;
initial
#40 $finish;

initial begin

    $dumpfile("EJ01_tb.vcd");
    $dumpvars(0,testbench);
  end
endmodule
