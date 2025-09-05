module encode83(
    input [7:0] x,
    input  en,
    output reg [2:0] y,
    output reg in_val // input value bit
);

    integer i;
    always @(x or en) begin
        if (en) begin
            y = 0;
            for( i = 0; i <= 7; i = i + 1)
                if(x[i] == 1)    y = i[2:0];//由于循环从低位开始，高位会覆盖低位的赋值，最终 y 表示的是最高位为 1 的位置


        end
        else begin  
            y = 0;
        end
    end

    always @(x) begin
        if (x == 0) begin
            in_val = 1'b0;
        end
        else begin
            in_val = 1'b1;
        end
    end

endmodule
