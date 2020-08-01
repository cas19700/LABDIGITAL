module Tabla01POS();

// Tabla01 POS

  reg A, B, C;
  wire wn1, wn2, wn3, wa1, wa2, wa3, out;


  not n0(wn1, A); 
  not n1(wn2, B);
  not n2(wn3, C);
  or  r0(wa1, A, B, wn3);
  or  r1(wa2, A, wn2, wn3);
  or  r2(wa3, wn1, wn2, C);
  and a1(out, wa1, wa2, wa3);

  initial begin
    $display("A B C | Y");
    $display("-------");
    $monitor("%b %b %b| %b", A, B, C, out);
    A = 0; B = 0; C = 0;
   
    #1 C = 1;
    #1 B = 1; C = 0;
    #1 C = 1;
    #1 A = 1; B = 0; C = 0;
	#1 C = 1;
	#1 B = 1; C = 0;
	#1 C = 1;
    #1 $finish;
  end

  initial 
    begin
      $dumpfile("Tabla01POS_tb.vcd"); 
      $dumpvars(0, Tabla01POS);
    end 

endmodule