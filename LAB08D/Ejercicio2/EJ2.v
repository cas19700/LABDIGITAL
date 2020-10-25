module ROM(input wire [11:0]address, output wire[7:0]val);
reg[7:0] M[0:4095];
initial begin
    $readmemh("ROMM.list",M);
    end
    assign val = M[address];
    endmodule
