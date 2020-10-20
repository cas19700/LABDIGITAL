module testbench();

reg clck, rst, W1, A1, ES1, D1, STL1, R1, T1;
reg [2:0]EST;
wire [2:0]ST2, SF2, S2;
wire [3:0]M1, YA1, AR1, F1;
wire [5:0]SY1,SF1,S1;
wire To1;

Proyecto1 U1(clck, rst, W1, A1, ES1, D1, STL1, R1, T1, M1, YA1, AR1, F1);

initial begin
clck=0; rst=0; STL1=0; R1=0; EST=0; T1=0;

#1 W1=0; A1=0; ES1=0; D1=0; STL1=0; R1=0; rst=1;
#1 W1=0; A1=0; ES1=0; D1=1; STL1=0; R1=0; rst=0;
#1 W1=0; A1=0; ES1=1; D1=0; STL1=0; R1=0; T1=0;
#1 W1=0; A1=0; ES1=1; D1=1; STL1=0; R1=0; T1=0;
#1 W1=0; A1=1; ES1=0; D1=0; STL1=0; R1=0; T1=0;
#1 W1=0; A1=1; ES1=0; D1=1; STL1=0; R1=0; T1=0;
#1 W1=0; A1=1; ES1=1; D1=0; STL1=0; R1=0; T1=0;
#1 W1=0; A1=1; ES1=1; D1=1; STL1=1; R1=0; T1=0;
#1 W1=1; A1=0; ES1=0; D1=0; STL1=0; R1=0; T1=1;
#1 W1=1; A1=0; ES1=0; D1=1; STL1=0; R1=0; T1=1;
#1 W1=1; A1=0; ES1=1; D1=0; STL1=0; R1=0; T1=1;
#1 W1=1; A1=0; ES1=1; D1=1; STL1=0; R1=0; T1=1;
#1 W1=1; A1=1; ES1=0; D1=0; STL1=0; R1=0; T1=1;
#1 W1=1; A1=1; ES1=0; D1=1; STL1=0; R1=0; T1=1;
#1 W1=1; A1=1; ES1=1; D1=0; STL1=0; R1=0; T1=1;
#1 W1=1; A1=1; ES1=1; D1=1; STL1=0; R1=0; T1=1;
#1 W1=0; A1=0; ES1=0; D1=0; STL1=0; R1=0; T1=1;
#1 W1=0; A1=0; ES1=0; D1=1; STL1=0; R1=0; T1=1;
#1 W1=0; A1=0; ES1=1; D1=0; STL1=0; R1=0; T1=1;
#1 W1=0; A1=0; ES1=1; D1=1; STL1=0; R1=0; T1=1;
#1 W1=0; A1=0; ES1=0; D1=0; STL1=0; R1=0; T1=0;
#1 W1=0; A1=0; ES1=0; D1=1; STL1=0; R1=0; T1=1;
#1 W1=0; A1=0; ES1=0; D1=0; STL1=0; R1=0; T1=1;
#1 W1=0; A1=0; ES1=1; D1=1; STL1=0; R1=0; T1=1;
#1 W1=1; A1=0; ES1=1; D1=0; STL1=0; R1=0; T1=1;
#1 W1=1; A1=1; ES1=0; D1=1; STL1=1; R1=0; T1=1;
#1 W1=1; A1=1; ES1=0; D1=0; STL1=1; R1=0; T1=1;
#1 W1=1; A1=1; ES1=0; D1=1; STL1=1; R1=0; T1=1;
#1 W1=1; A1=1; ES1=0; D1=0; STL1=1; R1=0; T1=1;
#1 W1=1; A1=1; ES1=0; D1=1; STL1=1; R1=0; T1=1;
#1 W1=1; A1=1; ES1=0; D1=0; STL1=1; R1=0; T1=1;
#1 W1=1; A1=1; ES1=0; D1=1; STL1=1; R1=0; T1=1;
#1 W1=0; A1=0; ES1=0; D1=0; STL1=1; R1=0; T1=1;
#1 W1=0; A1=0; ES1=0; D1=1; STL1=1; R1=0; T1=0;
end

always
#3 clck = ~clck;
initial
#45 $finish;

initial begin

    $dumpfile("Proyecto1_tb.vcd");
    $dumpvars(0,testbench);
  end

endmodule //
