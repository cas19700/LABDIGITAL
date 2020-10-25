module ALU (input wire [2:0]F,input wire[3:0]A, B, output wire[3:0]salida);
reg [3:0]val;
always @(F,A,B) begin
case(F)
3'b000: val <= A & B;
3'b001: val <= A | B;
3'b010: val <= A + B;
3'b011: val <= 4'b0;
3'b100: val <= A & ~B;
3'b101: val <= A | ~B;
3'b110: val <= A - B;
3'b111: val <= (A<B) ? 1:0;
default: val <= 4'b0;
endcase
end
assign salida = val;

endmodule
