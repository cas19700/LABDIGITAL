// Ejercicio01 Tabla01 Función a implementar: Y = (A' * B' ) + (B' * C')+(A * B') + (A * C)

module Ej01Tabla01(input wire A, B, C, output wire Y);

	
  assign Y = (~A & ~C ) | (~B & ~C) | (A & ~B) | (A & C);
endmodule

// Ejercicio01 Tabla02 Función a implementar: Y = B'

module Ej01Tabla02(input wire A, B, C, output wire Y);

	
  assign Y = (~B);
endmodule

// Ejercicio01 Tabla03 Función a implementar: Y = (A' * B' * C' * D') + (A' * B' * C * D) + (A' * B * C' * D) + (A' * B * C * D') +
//												  (A * B' * C' * D) + (A * B' * C * D') + (A * B * C' * D') + (A * B * C * D)							  

module Ej01Tabla03(input wire A, B, C, D, output wire Y);

	
  assign Y = (~A & ~B & ~C & ~D) | (~A & ~B & C & D) | (~A & B & ~C & D) | (~A & B & C & ~D) | (A & ~B & ~C & D) | (A & ~B & C & ~D) | (A & B & ~C & ~D) | (A & B & C & D);
endmodule

// Ejercicio01 Tabla04 Función a implementar: Y = (B' * D') + (A * B) + (A * C) 							  

module Ej01Tabla04(input wire A, B, C, D, output wire Y);

	
  assign Y = (~B & ~D) | (A & B) | (A & C);
endmodule

// Ejercicio02 Tabla01 Función a implementar: Y = (B' * C' * D') + (A * C') + (A * B') + (A * D')

module Ej02Tabla01(input wire A, B, C, D, output wire Y);

	wire nB, nC, nD, w1, w2, w3, w4;
	not(nB, B);
	not(nC, C);
	not(nD, D);
	and(w1, nB, nC, nD);
	and(w2, A, nC);
	and(w3, A, nB);
	and(w4, A, nD);
	or(Y, w1, w2, w3, w4);
endmodule
	
// Ejercicio02 Tabla02 Función a implementar: Y = C + B'

module Ej02Tabla02(input wire A, B, C, output wire Y);

	wire nB;
	not(nB, B);
	or(Y, nB, C);
endmodule
		
// Ejercicio02 Tabla03 Función a implementar: Y = B +(A * D) + (C' * D)

module Ej02Tabla03(input wire A, B, C, D, output wire Y);

	wire nC, w1, w2, wn2, w3;
	not(nC, C);
	and(w1, A, D);
	and(w2, nC, D);
	or(Y, B, w1, w2);
endmodule
		
// Ejercicio02 Tabla04 Función a implementar: Y = (A' * C') + B

module Ej02Tabla04(input wire A, B, C, output wire Y);

	wire nA, nC, w1;
	not(nA, A);
	not(nC, C);
	and(w1, nA, nC);
	or(Y, w1, B);
endmodule	



