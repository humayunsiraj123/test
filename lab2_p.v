module lab2(SW,HEX0,HEX1);
input [9:0]SW;
output [6:0]HEX0,HEX1;
reg Z

reg [3:0]V,CA,FA,X,Y;
assign V=SW[3:0];
comperator c1(Z,V);
converter  cc1(Z,V,CA);
mux m1(FA,Z,CA,V);
assign X=SW[3:0];
assign y=SW[7:4];
seg7_3 d1 (Z,HEX1);
seg7_3 d0 (FA,HEX0);



endmodule
module comperator(z,V1);
input [3:0]V1;
output z;
assign z=(V1>4'b1000)?1'b1:1'b0;
/*if(V1>4'b1001)
assign z=1'b1;
else
assign z=1'b0;*/
endmodule

module (A,B,Cin,Sum,Cout);
input [3:0]A,B;
input Cin;
output [3:0]Sum;
output Cout;

assign{Cout,Sum}=A+B+Cin;

endmodule



module converter(z,A,CA);
input[3:0]A;
output[3:0]CA;
always @(A) begin
if(z)begin
    case(A)
    4'b1010:CA=4'b0000;
    4'b1011:CA=4'b0001;
    4'b1100:CA=4'b0010;
    4'b1101:CA=4'b0011;
    4'b1110:CA=4'b0100;
    4'b1111:CA=4'b0101;
    default:
    CA=4'bxxxx;
    

end
end
endmodule

module converter2(z,A,CA);
input[3:0]A;
output[3:0]CA;
always @(A) begin
if(z)begin
    case(A)
    4'b0000:CA=4'b0001;
    4'b0010:CA=4'b0010;
    4'b0011:CA=4'b0010;
    4'b1101:CA=4'b0011;
    4'b1110:CA=4'b0100;
    4'b1111:CA=4'b0101;
    default:
    CA=4'bxxxx;
    

end
end
endmodule


module mux(Q,S,A,B);
input [3:0]A,B;
input S;
output [3:0]Q;
assign Q=S?A:B;
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

task FA4bit:
input [3:0]A,B;
input cin;
output [3:0]Sum;
output cout;
reg [4:0]C;
C[0]=cin;
genvar  i;
for(i=0;i<4;i=i+1)begin
    C[i+1]=(A[i]^B[i])&c=C[i]|(A[i]&B[i]);
    Sum[i]=(A[i]^B[i])^C[i];
end

assign cout=C[4]:
endtask

module ADDER(A,B,cin,S,Co);
input [3:0]A,B;
output cin;
output [3:0]Sum;
output Co;
reg [4:0]C;
C[0]=cin;
generate
    integer i;
    for(i=0;i<4;i=i+1)
    begin
        C[i+1]=(A[i]^B[i])&c=C[i]|(A[i]&B[i]);
    Sum[i]=(A[i]^B[i])^C[i];
    end
assign Co=C[4];
endgenerate
endmodule



