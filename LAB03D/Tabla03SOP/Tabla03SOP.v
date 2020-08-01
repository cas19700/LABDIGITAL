  module Tabla03SOP();

// Tabla03SOP

  reg A, B, C, D;
  wire wn1, wn2, wn3, wn4, wa1, wa2, wa3, wa4, wa5, wa6, wa7, out;


  not n0(wn1, A); 
  not n1(wn2, B);
  not n2(wn3, C);
  not n4(wn4, D);
  and a1(wa1, wn1, wn2, wn3, wn4);
  and a2(wa2, wn1, wn2, wn3,D);
  and a3(wa3, wn1, wn2, C, wn4);
  and a4(wa4, wn1, wn2, C, D);
  and a5(wa5, A, wn2, wn3, wn4);
  and a6(wa6, A, wn2, C, wn4);
  and a7(wa7, A, B, C, wn4);
  or  o1(out, wa1, wa2, wa3, wa4, wa5, wa6, wa7);

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
      $dumpfile("Tabla03SOP_tb.vcd"); 
      $dumpvars(0, Tabla03SOP);
    end 

endmodule