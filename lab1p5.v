module LAB1_P5(SW,LEDR,HEX0,HEX1,HEX2,HEX3);

input [9:0] SW;
output [9:0] LEDR;
output [6:0] HEX0,HEX1,HEX2,HEX3;
reg [1:0]W,X,Y,Z,S,M1,M2,M3,M4;
assign X=SW[3:2];
assign Y=SW[5:4];
assign Z=SW[7:6];
assign W=SW[1:0];
assign S=SW[9:0];

mux m1(M1,S,W,X,Y,Z);
seg7_1 hex0(M1,HEX0);

mux m2(M2,S,X,Y,Z,W);
seg7_1 hex1(M1,HEX1);


mux m3(M3,S,Y,Z,W,X);
seg7_1 hex2(M1,HEX2);

mux m4(M4,S,Z,W,X,Y);
seg7_1 hex3(M4,HEX3);


endmodule
module mux(Q,S,a,b,c,d);
input [1:0]a,b,c,d,S;
output [1:0]Q;
assign q[0]=s[1]?(s[0]?d[0]:c[0]):(s[0]?b[0]:a[0]);
assign q[1]=s[1]?(s[0]?d[1]:c[1]):(s[0]?b[1]:a[1]);
endmodule


module seg7_1(c,hex);
input[1:0]c;
output[6:0]hex;

assign hex[0]=~c[1]&~c[0]|c[1]&~c[0]|c[1]&c[0];
assign hex[1]=~c[1]&c[0]|c[1]&c[0];
assign hex[2]=~c[1]&c[0]|c[1]&c[0];
assign hex[3]=c[1]&~c[0]|c[1]&c[0];
assign hex[4]=c[1]&~c[0];|c[1]&c[0]
assign hex[5]=~c[1]&~c[0]|c[1]&~c[0]|c[1]&c[0];
assign hex[6]=c[1]&~c[0]|c[1]&c[0];
endmodule

module seg7_2(c,hex);
input[1:0]c;
output[6:0]hex;
always @(c) begin
    case (c)
        2'b00:hex=7'b1011110;
        2'b01:hex=7'b1111001;
        2'b10:hex=7'b0000110;
        default:hex=7'bxxxxxxxx; 
    endcase
end
endmodule


module seg7_3(C,hex);
input[3:0]C;
output[6:0]hex;

always@(C)
begin
    case (C)
        4'b0000:7'b0111111;
        4'b0001:7'b0000010;
        4'b0010:7'b1011011;
        4'b0011:7'b1001111;
        4'b0100:7'b1100110;
        4'b0101:7'b1101101;
        4'b0111:7'b1101101;
        4'b1000:7'b1111111;
        4'b1001:7'b1101111;
        4'b1010:7'b1110111;
        4'b1011:7'b1111100;
        4'b1100:7'b1111001;
        4'b1101:7'b1011110;
        4'b1111:7'b1110001;
         
        default:7'bxxxxxxxx; 
    endcase
end
endmodule