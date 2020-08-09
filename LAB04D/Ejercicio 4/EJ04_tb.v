module testbench();
  reg p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14,
	  b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11, b12, b13, b14;
  wire led1, led2, led3, led4, led5, led6, led7, led8;

  Ej01Tabla01  G1(p1, p2, p3, led1);
  Ej01Tabla02  G2(p4, p5, p6, led2);
  Ej01Tabla03  G3(p7, p8, p9, p10, led3);
  Ej01Tabla04  G4(p11, p12, p13, p14, led4);
  Ej02Tabla01  G5(b1, b2, b3, b4, led5);
  Ej02Tabla02  G6(b5, b6, b7, led6);
  Ej02Tabla03  G7(b8, b9, b10, b11, led7);
  Ej02Tabla04  G8(b12, b13, b14, led8);

  
  initial begin
    #1
    $display(" Ejercicio 01 Tabla 01 ");
    $display("A B C | Y ");
    $display("------|----");
    $monitor("%b %b %b | %b ", p1, p2, p3, led1);
       p1 = 0; p2 = 0; p3 = 0;
    #1 p3 = 1;
    #1 p2 = 1; p3 = 0;
    #1 p3 = 1;
    #1 p1 = 1; p2 = 0; p3 = 0;
    #1 p3 = 1;
    #1 p2 = 1; p3 = 0;
    #1 p3 = 1;
  end
  
  initial begin
    #9
    $display("\n");
	$display(" Ejercicio 01 Tabla 02 ");
    $display("A B C | Y");
    $display("------|--");
    $monitor("%b %b %b | %b", p4, p5, p6, led2);
       p4 = 0; p5 = 0; p6 = 0;
    #1 p6 = 1;
    #1 p5 = 1; p6 = 0;
    #1 p6 = 1;
    #1 p4 = 1; p5 = 0; p6 = 0;
    #1 p6 = 1;
    #1 p5 = 1; p6 = 0;
    #1 p6 = 1;
  end
  
 initial begin
    #27
    $display("\n");
	$display(" Ejercicio 01 Tabla 03 ");
    $display("A B C D | Y");
    $display("--------|--");
    $monitor("%b %b %b %b | %b", p7, p8, p9, p10, led3);
       p7 = 0; p8 = 0; p9 = 0; p10 = 0;
    #1 p10 = 1;
    #1 p9 = 1; p10 = 0;
    #1 p10 = 1;
    #1 p8 = 1; p9 = 0; p10 = 0;
    #1 p10 = 1;
    #1 p9 = 1; p10 = 0;
    #1 p10 = 1;
	#1 p7 = 1; p8 = 0; p9 = 0; p10 = 0;
	#1 p10 = 1;
    #1 p9 = 1; p10 = 0;
    #1 p10 = 1;
    #1 p8 = 1; p9 = 0; p10 = 0;
    #1 p10 = 1;
    #1 p9 = 1; p10 = 0;
    #1 p10 = 1;
	
  end
  
  initial begin
    #45
    $display("\n");
	$display(" Ejercicio 01 Tabla 04 ");
    $display("A B C D | Y");
    $display("--------|--");
    $monitor("%b %b %b %b | %b", p11, p12, p13, p14, led4);
       p11 = 0; p12 = 0; p13 = 0; p14 = 0;
    #1 p14 = 1;
    #1 p13 = 1; p14 = 0;
    #1 p14 = 1;
    #1 p12 = 1; p13 = 0; p14 = 0;
    #1 p14 = 1;
    #1 p13 = 1; p14 = 0;
    #1 p14 = 1;
	#1 p11 = 1; p12 = 0; p13 = 0; p14 = 0;
	#1 p14 = 1;
    #1 p13 = 1; p14 = 0;
    #1 p14 = 1;
    #1 p12 = 1; p13 = 0; p14 = 0;
    #1 p14 = 1;
    #1 p13 = 1; p14 = 0;
    #1 p14 = 1;
	
  end
  
  initial begin
    #61
    $display("\n");
	$display(" Ejercicio 02 Tabla 01 ");
    $display("A B C D | Y");
    $display("--------|--");
    $monitor("%b %b %b %b | %b", b1, b2, b3, b4, led5);
       b1 = 0; b2 = 0; b3 = 0; b4 = 0;
    #1 b4 = 1;
    #1 b3 = 1; b4 = 0;
    #1 b4 = 1;
    #1 b2 = 1; b3 = 0; b4 = 0;
    #1 b4 = 1;
    #1 b3 = 1; b4 = 0;
    #1 b4 = 1;
	#1 b1 = 1; b2 = 0; b3 = 0; b4 = 0;
	#1 b4 = 1;
    #1 b3 = 1; b4 = 0;
    #1 b4 = 1;
    #1 b2 = 1; b3 = 0; b4 = 0;
    #1 b4 = 1;
    #1 b3 = 1; b4 = 0;
    #1 b4 = 1;
	
  end
  
    initial begin
    #82
    $display("\n");
	$display(" Ejercicio 02 Tabla 02 ");
    $display("A B C | Y");
    $display("------|--");
    $monitor("%b %b %b | %b", b5, b6, b7, led6);
       b5 = 0; b6 = 0; b7 = 0; 
    #1 b7 = 1;
    #1 b6 = 1; b7 = 0;
    #1 b7 = 1;
    #1 b5 = 1; b6 = 0; b7 = 0;
    #1 b7 = 1;
    #1 b6 = 1; b7 = 0;
    #1 b7 = 1;
	
  end
  
  initial begin
    #96
    $display("\n");
	$display(" Ejercicio 02 Tabla 03 ");
    $display("A B C D | Y");
    $display("--------|--");
    $monitor("%b %b %b %b | %b", b8, b9, b10, b11, led7);
       b8 = 0; b9 = 0; b10 = 0; b11 = 0; 
    #1 b11 = 1;
    #1 b10 = 1; b11 = 0;
    #1 b11 = 1;
    #1 b9 = 1; b10 = 0; b11 = 0;
    #1 b11 = 1;
    #1 b10 = 1; b11 = 0;
    #1 b11 = 1;
	#1 b8 = 1; b9 = 0; b10 = 0; b11 = 0;
    #1 b11 = 1;
    #1 b10 = 1; b11 = 0;
    #1 b11 = 1;
    #1 b9 = 1; b10 = 0; b11 = 0;
    #1 b11 = 1;
	#1 b10 = 1; b11 = 0;
    #1 b11 = 1;
	
  end
  
  initial begin
    #120
    $display("\n");
	$display(" Ejercicio 02 Tabla 04 ");
    $display("A B C | Y");
    $display("------|--");
    $monitor("%b %b %b | %b", b12, b13, b14, led8);
       b12 = 0; b13 = 0; b14 = 0; 
    #1 b14 = 1;
    #1 b13 = 1; b14 = 0;
    #1 b14 = 1;
    #1 b12 = 1; b13 = 0; b14 = 0;
    #1 b14 = 1;
    #1 b13 = 1; b14 = 0;
    #1 b14 = 1;
   end
  
 initial
    #135 $finish;
 initial begin
    $dumpfile("EJ04_tb.vcd");
    $dumpvars(0, testbench);
 end
  
endmodule