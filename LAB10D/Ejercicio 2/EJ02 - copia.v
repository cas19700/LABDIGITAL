module testbench();
reg clck, rst, EN1, EN2, EN3;
reg [3:0]Entrada;
reg [2:0]S;
wire Carry, Zero;
wire [3:0]salida;
EJ02 M1(clck, rst, EN1, EN2, EN3, Entrada, S, Carry, Zero, salida);

initial begin
clck=0; rst=0; EN1=0; EN2=0; EN3=0; Entrada=0; S=0;
#1 rst=1;
#1 rst=0;
#1 Entrada= 4'b0010; EN1=1; EN2=1; EN3=1;S=3'b000;
#4 Entrada= 4'b0001; S=3'b010;
#4 Entrada= 4'b0011;
#4 Entrada= 4'b0100; S=3'b011;
#4 Entrada= 4'b0101; S=3'b100;
#4 Entrada= 4'b1010; S=3'b001;
#2 Entrada= 4'b0111;
#4 Entrada= 4'b0111; S=3'b011;

end
always
#1 clck = ~clck;
initial
#40 $finish;

initial begin

    $dumpfile("EJ02_tb.vcd");
    $dumpvars(0,testbench);
  end
endmodule
