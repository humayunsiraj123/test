module(SW,LEDR,HEX0,HEX1,KEY0);
input[9:0]SW;
output[9:0]LEDR;
output[6:0]HEX0,HEX1;
input clk;
wire  enable,reset,clear ,X;
wire [9:0]Y;
integer i;
assign X=enable;
assign Y[0]=enable;
for (i=0;i<8;i=1+i)
begin
    TFF tff[i](clk,Y[i],clear,Q[i]);
    assign y[i+1]=X&Q[i];





endmodule

module counter_4bit(clk,en,clr,Q);
input clk,en,clr;
output [3:0]Q;
wire [3:0] T,qs;

TFF t0(clk,en,clr,Q[0]);




module TFF(clk,enable,clear,Q);
input clk,enable,clear;
output  reg Q;
always@(clk)
begin
if (clear)
Q=0;
else if(enable)
Q=~Q;
end
endmodule
