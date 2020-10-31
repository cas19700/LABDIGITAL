// Ejercicio 4 buffer Tri-estado de 4 bits

module BTE(input E, input [3:0]D,  output [3:0]Q);

    assign Q = E==1?D:4'bzzzz;

endmodule
