  module Tabla02SOP();

// Tabla02SOP

  reg A, B, C;
  wire wn1, wn2, wn3, wa1, wa2, wa3, out;


  not n0(wn1, A); 
  not n1(wn2, B);
  not n2(wn3, C);
  and a1(wa1, wn1, wn2, C);
  and a2(wa2, A, B, wn3);
  and a3(wa3, A, B, C);
  or  o1(out, wa1, wa2, wa3);

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
      $dumpfile("Tabla02SOP_tb.vcd"); 
      $dumpvars(0, Tabla02SOP);
    end 

endmodule