module testbench();

reg [11:0]address;
wire [7:0]val;

ROM U1(address, val);

initial begin
$display("Memoria ROM");
$display("    Address     |  Data");
$display("------------|---------");
$monitor("%b | %b", address, val);

address=12'b0;
#1 address=12'b000000000001;
#1 address=12'b000000000010;
#1 address=12'b000000000011;
#1 address=12'b000000000100;
#1 address=12'b000000000101;
#1 address=12'b000000000110;
#1 address=12'b000000000111;
#1 address=12'b000000001000;
#1 address=12'b000000001001;
#1 address=12'b000000001010;
#1 address=12'b000000001011;
end
initial
#13 $finish;

initial begin

    $dumpfile("EJ2_tb.vcd");
    $dumpvars(0,testbench);
  end
endmodule
