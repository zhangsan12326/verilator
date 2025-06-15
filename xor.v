module xor(
    input wire a,
    input wire b,
    output reg f
);
 
always @(*) begin
    f = a ^ b;
end
 
endmodule
