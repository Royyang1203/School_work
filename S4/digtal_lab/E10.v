module E10(input enable, input iclk, input [7:0] in, output out, output [2:0]A);
    wire oclk;

    FreqDiv f0 (iclk, enable, oclk);
    upcounter u0(oclk, A);
    mux8to1 m0(in, out, A);
endmodule


module mux8to1(input [7:0] in,output reg out,input [2:0]input_data);
    always @(input_data)
    begin
	case (input_data)
	    3'b000: out=in[0];
	    3'b001: out=in[1];
	    3'b010: out=in[2];
	    3'b011: out=in[3];
	    3'b100: out=in[4];
	    3'b101: out=in[5];
	    3'b110: out=in[6];
	    3'b111: out=in[7];
	endcase
end
endmodule

module JK_FF (output reg Q,input J,input K,input CLK);
    always @ (negedge CLK)
    begin
	case ({J,K})
		2'b00: Q <= Q;
		2'b01: Q <= 1'b0;
		2'b10: Q <= 1'b1;
		2'b11: Q <= ~ Q;
	endcase
    end
endmodule

module upcounter(input clk, output [2:0]A);
    JK_FF(A[0], 1, 1, clk);
    JK_FF(A[1], 1, 1, A[0]);
    JK_FF(A[2], 1, 1, A[1]);
endmodule

module FreqDiv(input iclk, enable, output reg oclk);
    integer count;
    parameter Rate = 50000000;
    initial count = 0;

    always@(posedge iclk)
	begin
		if(count < Rate / 2)
			oclk = 1;
		else
			oclk = 0;
		count = (count + enable ) % Rate;
	end
endmodule


/*
module E10(input enable,input iclk,input [7:0] in,output out,output A,output B,output C);
wire oclk;
wire a,b,c;

FreqDiv f0 (iclk,oclk,enable);
upcounter u0(oclk,1,A,B,C);
assign a=A;
assign b=B;
assign c=C;
mul8to1 m0(in,out,a,b,c);

endmodule


module mul8to1(input [7:0] in,output reg out,input  A,B,C);
always @(A)
begin
	if(A==0&&B==0&&C==0) begin out=in[0]; end
	if(A==0&&B==0&&C==1) begin out=in[1]; end
	if(A==0&&B==1&&C==0) begin out=in[2]; end
	if(A==0&&B==1&&C==1) begin out=in[3]; end
	if(A==1&&B==0&&C==0) begin out=in[4]; end
	if(A==1&&B==0&&C==1) begin out=in[5]; end
	if(A==1&&B==1&&C==0) begin out=in[6]; end
	if(A==1&&B==1&&C==1) begin out=in[7]; end


end
endmodule

module JK(H,Q,clk);

input H;
input clk;
output reg Q;
always @(posedge clk)
begin
if(H==1) Q = ~Q;
end
endmodule

module upcounter(input clk,input H,output A,output B,output C);

JK j1(H,C,!clk);
JK j2(H,B,!C);
JK j3(H,A,!B);


endmodule

module FreqDiv(iclk,oclk,enable);
input iclk,enable;
output oclk;
reg oclk;
integer count;
parameter Rate = 50000000;
initial
 count=0;
 always@(posedge iclk)
 begin
	if(count < Rate/2)
		oclk = 1;
	else
		oclk = 0;
	count = (count + enable ) % Rate;
end
endmodule
*/

// module E10(iCLEAR, iPAUSE, iCLK, segDP06, segDP10);
//     input iCLEAR, iPAUSE, iCLK;
//     output [6:0] segDP06, segDP10;
//     wire [3:0] div6, div10;
//     wire clr6;
//     assign clr6 = ~(~div6[3] & div6[2] & div6[1] & ~div6[0]);
//     reg stop;
//     always @(posedge iPAUSE)
//     stop = ~stop;
//     wire oclk;
//     frequencyDivider fd0(iCLK, oclk);
//     SynCounter sc0(oclk & stop , iCLEAR, div10); //mod 10
//     AsynCounter ac0(div10[3], iCLEAR & clr6 , div6); //mod 06
//     decoder7447(div10, segDP10);
//     decoder7447(div6, segDP06);
// endmodule

// module SynCounter(iCLK, iCLEAR, Qs); //mod 10
//     input iCLK, iCLEAR;
//     output wire [3:0] Qs;
//     wire j1, j2, j3;
//     wire tempA, tempB;
//     and(j1, Qs[0],~Qs[3]);
//     and(j2, Qs[1], Qs[0]);
//     and(tempA, Qs[0], Qs[3]);
//     and(tempB, j2, Qs[2]);
//     or(j3, tempA, tempB);
//     JK_FlipFlop( 1, 1, iCLK, iCLEAR, Qs[0]);
//     JK_FlipFlop(j1, j1, iCLK, iCLEAR, Qs[1]);
//     JK_FlipFlop(j2, j2, iCLK, iCLEAR, Qs[2]);
//     JK_FlipFlop(j3, j3, iCLK, iCLEAR, Qs[3]);
// endmodule

// module AsynCounter(iCLK, iCLEAR, Qs); //mod 06
//     input iCLK, iCLEAR;
//     output [3:0] Qs;
//     JK_FlipFlop(1, 1, ~iCLK, iCLEAR, Qs[0]);
//     JK_FlipFlop(1, 1, ~Qs[0], iCLEAR, Qs[1]);
//     JK_FlipFlop(1, 1, ~Qs[1], iCLEAR, Qs[2]);
//     JK_FlipFlop(1, 1, ~Qs[2], iCLEAR, Qs[3]);
// endmodule

// module JK_FlipFlop(iJ, iK, iCLK, iCLEAR, Q);
//     input iJ, iK, iCLK, iCLEAR;
//     output reg Q;
//     always @(posedge iCLK or negedge iCLEAR)
//     begin
//         if (iCLEAR == 0)
//             Q=0;
//         else
//             begin
//             case ({iJ,iK})
//                 2'b00: Q = Q;
//                 2'b01: Q = 1'b0;
//                 2'b10: Q = 1'b1;
//                 2'b11: Q = ~Q;
//             endcase
//             end
//     end
// endmodule

// module frequencyDivider(iClk, oClk);
//     input iClk;
//     output oClk;
//     reg oClk;
//     integer count;
//     parameter RATE = 50000000;
//     initial count = 0;
//     always @(posedge iClk)
//     begin
//     if(count < RATE/2)
//         oClk = 1;
//     else
//         oClk = 0;
//     count = (count+1) % RATE;
//     end
// endmodule


// module E10(clk, enable, din, data, S);
// 	input clk,enable;
// 	output data;
// 	input[7:0] din;
// 	output [2:0]S;
// 	wire oclk;
// 	divider d(clk,enable,oclk);
// 	Count c(oclk,S);
// 	MUX m(din,data,S);
// endmodule

// module Count(clk,out);
// 	input clk;
// 	output [2:0]out;

// 	JK_FF f1(clk, out[0]);
// 	JK_FF f2(out[0], out[1]);
// 	JK_FF f3(out[1], out[2]);

// endmodule

// module JK_FF(clk, Q);
// 	input clk;
// 	output reg Q;
// 	always @(negedge clk)
// 		Q = ~Q;
// endmodule

// module divider(clk, enable, dclk);
// 	input clk, enable;
// 	output reg dclk;
// 	integer count;
// 	parameter Rate =  50000000;
// 	initial count=0;
// 	always@(posedge clk)
// 		if (enable)
// 		begin
// 			if(count<Rate/2)
// 				dclk = 1;
// 			else
// 				dclk = 0;

// 			count = (count + 1)%Rate;
//         end
// endmodule

// module MUX(din,out,S);
// 	input[7:0] din;
// 	input[2:0] S; //selection
// 	output reg out;
// 	always@(din or S)
// 		case(S)
// 		3'b000: out = din[0];
// 		3'b001: out = din[1];
// 		3'b010: out = din[2];
// 		3'b011: out = din[3];
// 		3'b100: out = din[4];
// 		3'b101: out = din[5];
// 		3'b110: out = din[6];
// 		3'b111: out = din[7];
// 		endcase

// endmodule
