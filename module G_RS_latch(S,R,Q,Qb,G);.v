module G_RS_latch(S,R,Q,Qb,G);
input S,R,G;
output reg Q,Qb;

always@(*);
if(G)begin
    if(S)begin
        Q=1'b1;
        Qb=~Q;
    end
    else if(R) begin
    Q=1'b0;
    Qb=~Q;
        
    end 