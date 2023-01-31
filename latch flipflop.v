module P1(clk,s,r,q);
input clk,s,r;
output q;
wire r_g,s_gq,qa,qb
assign r_g=clk&r;
assign s_g=clk&s;
assign qa=~(r_g |qb);
assign qb=~(s_g |qa);

assign q=qa;
endmodule


module p2(SW,LEDR);
input [9:0]SW;
output [9:0]LEDR;

DFF f1(SW[0],S[1],LEDR[0]);
D_FF f2(S[2],S[3],LEDR[1]);
endmodule
module DFF(clk,D,Q);
input clk,D;
output Q;

wire S,R;
assign S=D;
assign R=~D;

wire r_g,s_gq,qa,qb
assign r_g=clk&r;
assign s_g=clk&s;
assign qa=~(r_g |qb);
assign qb=~(s_g |qa);
assign Q=qa;
endmodule

module D_FF(clk,D,Q);

input clk,D;
output Q;

DFF d1(~clk,D,Q);
DFF d2(clk,Q,D);
endmodule


module D_latch(clk,d,q);
input clk,d;
output reg q;
always @(clk)
begin
q<=d;
end
endmodule

module flippyfloppy(clk,d,q);
input clk,d;
output q;
wire qm;
D_latch d1(~clk,d,qm);
D_latch d2(clk,qm,q);
endmodule 


