module lab2p4(SW,LEDR,HEX0,HEX1,HEX2,HEX3,HEX4,HEX5);
input [9:0]SW;
output [9:0]LEDR;
output [6:0]HEX0,HEX1,HEX2,HEX3,HEX4,HEX5;

wire[3:0]X,Y,V,A,sum1,sumO1,sum2,sumO2,sum3,sumO3;
wire [1:0]D;
wire cout,x,y,z;
assign X=SW[3:0];
assign Y=SW[7:4];
assign cin=SW[8];

assign LEDR[9]=x||y;
assign LEDR[3:0]=X;
assign LEDR[7:4]=Y;
assign LEDR[8]=cin;

comperator c3(x,X);
comperator c4(y,Y);


segment7 s1(X,HEX5);
segment7 s2(Y,HEX3);


ADDER_4bit adder1(X,Y,cin,sum1,cout);

comperator comp1(z,sum1);
converter conv1(sum1,sumO1);

mux m3(sumO2,z,sumO1,sum1);


converter2 conv2(sumO3,sumO2);
mux m4(sum3,cout,sumO3,sumO2);


segment7 s3(sum3,HEX0);


segment7 s4(z,HEX1);




endmodule




module converter2(A,B);
input [3:0]A;
output reg[ 3:0]B;
always@(A);
begin
    case(A)
    4'b0000: B=4'b0110;
    4'b0001: B=4'b0111;
    4'b0010:B=4'b1000;
    4'b0011: B=4'b1001;
    default:B=4'bxxxx;
endcase
end

endmodule

module segment7(A,HEX);
input [3:0]A;
output reg [6:0]HEX;
always@(A)
begin
case(A)
4'b0000:HEX=7'b0000001;
4'b0001:HEX=7'b1001111;
4'b0010:HEX=7'b0010010;
4'b0011:HEX=7'b0000110;
4'b0100:HEX=7'b1001100;
4'b0101:HEX=7'b0100100;
4'b0110:HEX=7'b0100000;
4'b0111:HEX=7'b0001111;
4'b1000:HEX=7'b0100000;
4'b1001:HEX=7'b0000100;
default:HEX=7'b1111111;
endcase
end
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

module ADDER_4bit(A,B,Cin,Sum,Cout);
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



