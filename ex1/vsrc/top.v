module top(
  input [1:0]  x[4], // 有4个元素的数据宽度为2位的数组
  input [1:0]  s,
  output reg[1:0]  y
);


always@(x or s)begin
case(s)
2'b00:y=x[0];
2'b01:y=x[1];
2'b10:y=x[2];
2'b11:y=x[3];
endcase
end
endmodule

