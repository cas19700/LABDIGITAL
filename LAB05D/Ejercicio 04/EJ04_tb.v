module testbench();
  reg d1, d0, k1, k2, b1, b2, c1, c2, e1, e2, m1, m2, s, s1, s2, s3, s4, s5;
  wire y0, y1, y2, y3, y4, y5;

  mux2T01 G1(d0, d1, s, y0);
  mux4T01 G2(k1, k2, s1, y1);
  mux8T01 G3(b1, b2, s2, y2);
  mux2T02 G4(c1, c2, s3, y3);
  mux4T02 G5(e1, e2, s4, y4);
  mux8T02 G6(m1, m2, s5, y5);
  
  initial begin
    #1
    $display("\n");
	$display(" Ejercicio 04 Tabla01 MUX 2:1");
    $display("A B C | Y");
    $display("------|--");
    $monitor("%b %b %b | %b", d0, d1, s, y0);
       d0 = 0; d1 = 0;  s = 0;
    #1 s = 1; 
    #1 d1 = 1; s = 0;
    #1 s = 1;
	#1 d0 = 1; d1 = 0; s = 0;
	#1 s = 1;
	#1 d1 = 1; s = 0;
	#1 s = 1;
    
  end
  
    initial begin
    #20
    $display("\n");
	$display(" Ejercicio 04 Tabla01 MUX 4:1");
    $display("A B C | Y");
    $display("------|--");
    $monitor("%b %b %b | %b", k1, k2, s1, y1);
       k1 = 0; k2 = 0;  s1 = 0;
    #1 s1 = 1; 
    #1 k2 = 1; s1 = 0;
    #1 s1 = 1;
	#1 k1 = 1; k2 = 0; s1 = 0;
	#1 s1 = 1;
	#1 k2 = 1; s1 = 0;
	#1 s1 = 1;
    
  end
  
  initial begin
    #40
    $display("\n");
	$display(" Ejercicio 04 Tabla01 MUX 8:1");
    $display("A B C | Y");
    $display("------|--");
    $monitor("%b %b %b | %b", b1, b2, s2, y2);
       b1 = 0; b2 = 0;  s2 = 0;
    #1 s2 = 1; 
    #1 b2 = 1; s2 = 0;
    #1 s2 = 1;
	#1 b1 = 1; b2 = 0; s2 = 0;
	#1 s2 = 1;
	#1 b2 = 1; s2 = 0;
	#1 s2 = 1;
    
  end
  
   initial begin
    #60
    $display("\n");
	$display(" Ejercicio 04 Tabla02 MUX 2:1");
    $display("A B C | Y");
    $display("------|--");
    $monitor("%b %b %b | %b", c1, c2, s3, y3);
       c1 = 0; c2 = 0;  s3 = 0;
    #1 s3 = 1; 
    #1 c2 = 1; s3 = 0;
    #1 s3 = 1;
	#1 c1 = 1; c2 = 0; s3 = 0;
	#1 s3 = 1;
	#1 c2 = 1; s3 = 0;
	#1 s3 = 1;
    
  end
  
  initial begin
    #80
    $display("\n");
	$display(" Ejercicio 04 Tabla02 MUX 4:1");
    $display("A B C | Y");
    $display("------|--");
    $monitor("%b %b %b | %b", e1, e2, s4, y4);
       e1 = 0; e2 = 0;  s4 = 0;
    #1 s4 = 1; 
    #1 e2 = 1; s4 = 0;
    #1 s4 = 1;
	#1 e1 = 1; e2 = 0; s4 = 0;
	#1 s4 = 1;
	#1 e2 = 1; s4 = 0;
	#1 s4 = 1;
    
  end
  
    initial begin
    #100
    $display("\n");
	$display(" Ejercicio 04 Tabla02 MUX 8:1");
    $display("A B C | Y");
    $display("------|--");
    $monitor("%b %b %b | %b", m1, m2, s5, y5);
       m1 = 0; m2 = 0;  s5 = 0;
    #1 s5 = 1; 
    #1 m2 = 1; s5 = 0;
    #1 s5 = 1;
	#1 m1 = 1; m2 = 0; s5 = 0;
	#1 s5 = 1;
	#1 m2 = 1; s5 = 0;
	#1 s5 = 1;
    
  end
  
   initial
    #120 $finish;
 initial begin
    $dumpfile("EJ04_tb.vcd");
    $dumpvars(0, testbench);
 end
  
endmodule