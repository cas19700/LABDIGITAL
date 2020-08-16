// Ejercicio04 MUX 2:1

module mux2(input wire d0 , d1, input wire s, output wire y);

	assign y = s ? d1 : d0;
endmodule

// Ejercicio04 MUX 4:1

module mux4(input wire d0, d1, d2, d3, input wire s0, s1, output wire y);
	wire y1, y2;
	
	mux2 M1(d2, d3, s0, y1);
	mux2 M2(d0, d1, s0, y2);
	mux2 M3(y2, y1, s1, y);

endmodule

// Ejercicio04 MUX 8:1

module mux8(input wire d0, d1, d2, d3, d4, d5, d6, d7, input wire s0, s1, s2, output wire y);
	wire y1, y2;
	
	mux4 M4(d4, d5, d6, d7, s1, s2, y1);
	mux4 M5(d0, d1, d2, d3, s1, s2, y2);
	mux2 M6(y2, y1, s0, y);

endmodule

// Ejercicio04 MUX 2:1 Tabla01

module mux2T01(input wire A, B, C, output wire y);
	wire d0, d1;
	assign d0 = (B ^ C);
	assign d1 = ~(B ^ C);
	mux2 B1(d0, d1, A, y);
endmodule

// Ejercicio04 MUX 4:1 Tabla01

module mux4T01(input wire A, B, C, output wire y);
	wire cn;
	assign cn = ~(C);
	mux4 B2(C, cn, cn, C, A, B, y);
endmodule

// Ejercicio04 MUX 8:1 Tabla01

module mux8T01(input wire A, B, C, output wire y);
	wire N, S;
	assign N = 0;
	assign S = 1;
	mux8 B3(N, S, S, N, S, N, N, S, A, B, C, y);
endmodule

// Ejercicio04 MUX 2:1 Tabla02

module mux2T02(input wire A, B, C, output wire y);
	wire d0, d1;
	assign d0 = ~(B | C);
	assign d1 = (B ^ C);
	mux2 B1(d0, d1, A, y);
endmodule

// Ejercicio04 MUX 4:1 Tabla02

module mux4T02(input wire A, B, C, output wire y);
	wire cn, N;
	assign N = 0;
	assign cn = ~(C);
	mux4 B2(cn, C, N, cn, A, B, y);
endmodule

// Ejercicio04 MUX 8:1 Tabla02

module mux8T02(input wire A, B, C, output wire y);
	wire N, S;
	assign N = 0;
	assign S = 1;
	mux8 B10(S, N, N, N, N, S, S, N, A, B, C, y);
endmodule