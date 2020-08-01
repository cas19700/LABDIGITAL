module Tabla04POS();

// Tabla04 POS

  reg A, B, C, D;
  wire wn1, wn2, wn3, wn4, wa1, wa2, wa3, wa4, wa5, wa6, wa7, wa8, wa9, wa10, out;

  not n0(wn1, A); 
  not n1(wn2, B);
  not n2(wn3, C);
  not n3(wn4, D);
  or  r0(wa1, A, wn2, C, D);
  or  r1(wa2, A, wn2, C, wn4);
  or  r2(wa3, wn1, B, C, wn4);
  or  r3(wa4, A, B, C, wn4);
  or  r4(wa5, wn1, B, C, wn4);
  or  r5(wa6, wn1, B, wn3, wn4);
  or  r6(wa7, wn1, wn2, C, D);
  or  r7(wa8, wn1, wn2, C, wn4);
  or  r8(wa9, wn1, wn2, wn3, D);
  or  r8(wa10, wn1, wn2, wn3, wn4);
  and a1(out, wa1, wa2, wa3, wa4, wa5, wa6, wa7, wa8, wa9, wa10);

  initial begin
    $display("A B C D | Y");
    $display("-------");
    $monitor("%b %b %b %b| %b", A, B, C, D, out);
   A = 0; B = 0; C = 0; D = 0;
   
    #1 D = 1;
    #1 C = 1; D = 0;
    #1 D = 1;
    #1 B = 1; C = 0; D = 0;
	#1 D = 1;
	#1 C = 1; D = 0;
	#1 D = 1;
	#1 A = 1; B = 0; C = 0; D = 0;
	#1 D = 1;
    #1 C = 1; D = 0;
    #1 D = 1;
    #1 B = 1; C = 0; D = 0;
	#1 D = 1;
	#1 C = 1; D = 0;
	#1 D = 1;
    #1 $finish;
  end

  initial 
    begin
      $dumpfile("Tabla04POS_tb.vcd"); 
      $dumpvars(0, Tabla04POS);
    end 

endmodule