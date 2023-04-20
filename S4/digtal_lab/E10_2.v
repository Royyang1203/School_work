module E10_2 (input [2:0]A, data, output [7:0]led, output reg [2:0]AA, input DD);
	demux(A, data, led);
	always @(A)
	begin
		 AA = A;
		 DD = data;
	end
endmodule

module demux(input [2:0]A, input data, output reg [7:0]Out);
	always @(A)
		case(A)
			3'b000: Out = {7'b0000000,data};
			3'b001: Out = {6'b000000, data, 1'b0};
			3'b010: Out = {5'b00000, data, 2'b00};
			3'b011: Out = {4'b0000, data, 3'b000};
			3'b100: Out = {3'b000, data, 4'b0000};
			3'b101: Out = {2'b00, data, 5'b00000};
			3'b110: Out = {1'b0, data, 6'b000000};
			3'b111: Out = {data, 7'b0000000};
		endcase
endmodule
