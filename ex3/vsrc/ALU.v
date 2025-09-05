module ALU (
    input [3:0] a,
    input [3:0] b,
    input [2:0] op,

    output reg [3:0] result,
    output reg      zero,
    output reg      c_out,
    output reg      of// // 溢出标志
);

    always begin
        case (op)
            3'b000: begin
                { c_out, result } = a + b; // op=000: sum
                zero = (result == 4'd0) ? 1 : 0;
                of = (a[3] == b[3]) && (result[3] != a[3]); 
            end
            3'b001: begin
                { c_out, result } = a - b;  // op=001: sub
                zero = (result == 4'd0) ? 1 : 0; 
                of = (a[3] == b[3]) && (result[3] != a[3]); 
            end
            3'b010: begin
                result = ~a;  // op=010: not a
                c_out = 1'd0;
                zero = 1'd0;
                of = 1'd0;
            end
            3'b011: begin
                result = a & b; // op=011: and
                c_out = 1'd0;
                zero = 1'd0;
                of = 1'd0;
            end
            3'b100: begin
                result = a | b;  // op=100: or
                c_out = 1'd0;
                zero = 1'd0;
                of = 1'd0;
            end
            3'b101: begin
                result = a ^ b; // op=101: xor
                c_out = 1'd0;
                zero = 1'd0;
                of = 1'd0;
            end
            3'b110: begin
                result = (a < b) ? 1 : 0; // op=110: compare
                c_out = 1'd0;
                zero = 1'd0;
                of = 1'd0;
            end
            3'b111: begin
                result = (a == b) ? 1 : 0; // op=111: equare
                c_out = 1'd0;
                zero = 1'd0;
                of = 1'd0;
            end
        endcase
    end

endmodule
