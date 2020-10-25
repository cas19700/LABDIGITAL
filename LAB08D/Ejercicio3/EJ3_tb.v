module testbench();

reg [2:0]F;
reg [3:0]A,B;
wire [3:0]salida;
ALU U1(F,A,B,salida);

initial begin
F=3'b011; A=4'b0; B=4'b0;
#1 A=4'b0101; B=4'b0100; F=3'b0;
#1 F=3'b001;
#1 F=3'b010;
#1 F=3'b011;
#1 F=3'b100;
#1 F=3'b101;
#1 F=3'b110;
#1 F=3'b111;
#1 A=4'b0100; B=4'b0101;

end

initial
#15 $finish;

initial begin

    $dumpfile("EJ3_tb.vcd");
    $dumpvars(0,testbench);
  end
endmodule
