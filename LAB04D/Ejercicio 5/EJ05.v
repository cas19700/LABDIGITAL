// Ejercicio05 SOP Gate Level Modelling Función a implementar: Y = (A * B' * C') + (A * B' * C) + (A * B * C)

module Ej05SOPGLM(input wire A, B, C, output wire Y);

	wire nB, nC, w1, w2, w3;
	not(nB, B);
	not(nC, C);
	and(w1, A, nB, nC);
	and(w2, A, nB, C);
	and(w3, A, B, C);
	or(Y, w1, w2, w3);
endmodule	

// Ejercicio05 SOP Behavior Función a implementar: Y = (A * B' * C') + (A * B' * C) + (A * B * C)

module Ej05SOPB(input wire A, B, C, output wire Y);

	assign Y = (A & ~B & ~C) | (A & ~B & C) | (A & B & C);
endmodule	

// Ejercicio05 POS Gate Level Modelling Función a implementar: Y = (A + B + C) * (A + B + C') * (A + B' + C) * (A + B' + C') * (A' + B' + C)

module Ej05POSGLM(input wire A, B, C, output wire Y);

	wire nA, nB, nC, w1, w2, w3, w4, w5;
	not(nA, A);
	not(nB, B);
	not(nC, C);
	or(w1, A, B, C);
	or(w2, A, B, nC);
	or(w3, A, nB, C);
	or(w4, A, nB, nC);
	or(w5, nA, nB, C);
	and(Y, w1, w2, w3, w4, w5);
endmodule	

// Ejercicio05 POS Behavior Función a implementar: Y = (A + B + C) * (A + B + C') * (A + B' + C) * (A + B' + C') * (A' + B' + C)

module Ej05POSB(input wire A, B, C, output wire Y);

	assign Y = (A | B | C) & (A | B | ~C) & (A | ~B | C) & (A | ~B | ~C) & (~A | ~B | C);
endmodule	

// Ejercicio05 Mapa de Karnaugh Gate Level Modelling Función a implementar: Y = (A * B') + (A * C)

module Ej05MKGLM(input wire A, B, C, output wire Y);

	wire nB, w1, w2, w3;
	not(nB, B);
	and(w1, A, nB);
	and(w2, A, C);
	or(Y, w1, w2);
endmodule	

// Ejercicio05 Mapa de Karnaugh Behavior Función a implementar: Y = (A * B') + (A * C)

module Ej05MKB(input wire A, B, C, output wire Y);

	assign Y = (A & ~B ) | (A & C);
endmodule	