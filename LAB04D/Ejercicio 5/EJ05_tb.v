module testbench();
  reg d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, k1, k2, k3, k4, k5, k6;
  wire led1, led2, led3, led4, led5, led6;

  Ej05SOPGLM  G1(d1, d2, d3, led1);
  Ej05SOPB G2(d4, d5, d6, led2);
  Ej05POSGLM  G3(d7, d8, d9, led3);
  Ej05POSB G4(d10, d11, d12, led4);
  Ej05MKGLM G5(k1, k2, k3, led5);
  Ej05MKB  G6(k4, k5, k6, led6);
  
  initial begin
    #1
    $display("\n");
	$display(" Ejercicio 05 SOP GLM ");
    $display("A B C | Y");
    $display("------|--");
    $monitor("%b %b %b | %b", d1, d2, d3, led1);
       d1 = 0; d2 = 0; d3 = 0; 
    #1 d3 = 1;
    #1 d2 = 1; d3 = 0;
    #1 d3 = 1;
    #1 d1 = 1; d2 = 0;d3 = 0;
    #1 d3 = 1;
    #1 d2 = 1; d3 = 0;
    #1 d3 = 1;
	
  end
  
  initial begin
    #9
    $display("\n");
	$display(" Ejercicio 05 SOP B ");
    $display("A B C | Y");
    $display("------|--");
    $monitor("%b %b %b | %b", d4, d5, d6, led2);
       d4 = 0; d5 = 0; d6 = 0; 
    #1 d6 = 1;
    #1 d5 = 1; d6 = 0;
    #1 d6 = 1;
    #1 d4 = 1; d5 = 0;d6 = 0;
    #1 d6 = 1;
    #1 d5 = 1; d6 = 0;
    #1 d6 = 1;
	
  end
  
  
  initial begin
    #27
    $display("\n");
	$display(" Ejercicio 05 POS GLM ");
    $display("A B C | Y");
    $display("------|--");
    $monitor("%b %b %b | %b", d7, d8, d9, led3);
       d7 = 0; d8 = 0; d9 = 0; 
    #1 d9 = 1;
    #1 d8 = 1; d9 = 0;
    #1 d9 = 1;
    #1 d7 = 1; d8 = 0;d9 = 0;
    #1 d9 = 1;
    #1 d8 = 1; d9 = 0;
    #1 d9 = 1;
	
  end
  initial begin
    #40
    $display("\n");
	$display(" Ejercicio 05 POS B ");
    $display("A B C | Y");
    $display("------|--");
    $monitor("%b %b %b | %b", d10, d11, d12, led4);
       d10 = 0; d11 = 0; d12 = 0; 
    #1 d12 = 1;
    #1 d11 = 1; d12 = 0;
    #1 d12 = 1;
    #1 d10 = 1; d11 = 0;d12 = 0;
    #1 d12 = 1;
    #1 d11 = 1; d12 = 0;
    #1 d12 = 1;
	
  end
  
  initial begin
    #55
    $display("\n");
	$display(" Ejercicio 05 Mapa K GLM ");
    $display("A B C | Y");
    $display("------|--");
    $monitor("%b %b %b | %b", k1, k2, k3, led5);
       k1 = 0; k2 = 0; k3 = 0; 
    #1 k3 = 1;
    #1 k2 = 1; k3 = 0;
    #1 k3 = 1;
    #1 k1 = 1; k2 = 0;k3 = 0;
    #1 k3 = 1;
    #1 k2 = 1; k3 = 0;
    #1 k3 = 1;
	
  end
  
  initial begin
    #65
    $display("\n");
	$display(" Ejercicio 05 Mapa K B ");
    $display("A B C | Y");
    $display("------|--");
    $monitor("%b %b %b | %b", k4, k5, k6, led6);
       k4 = 0; k5 = 0; k6 = 0; 
    #1 k6 = 1;
    #1 k5 = 1; k6 = 0;
    #1 k6 = 1;
    #1 k4 = 1; k5 = 0;k6 = 0;
    #1 k6 = 1;
    #1 k5 = 1; k6 = 0;
    #1 k6 = 1;
	
  end
  
 initial
    #85 $finish;
 initial begin
    $dumpfile("EJ05_tb.vcd");
    $dumpvars(0, testbench);
 end
  
endmodule