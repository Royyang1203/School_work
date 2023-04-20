module BCSR (
  output reg    [7: 0]  A_par,  // 輸出
  input     [7: 0]  I_par,  // 初始化
  input         s1, s0, // 選擇輸入
            MSB_in, LSB_in,     // Serial inputs
            CLK, Clear_b        // Clock and Clear_b
);
  always @ (posedge CLK, negedge Clear_b)
    if (~Clear_b) A_par <= 8'b00000000;
    else
      case ({s1, s0})
        2'b00: A_par <= A_par;               // 不改變
        2'b01: A_par <= {MSB_in, A_par[7: 1]};   // 右移
        2'b10: A_par <= {A_par[6: 0], LSB_in};   // 左移
        2'b11: A_par <= I_par;           // 初始化
      endcase
endmodule
//==============================================================


// 4x1 multiplexer         // 模塊一l
module Mux_4_x_1 (mux_out, i0, i1, i2, i3, select);
  output    mux_out;
  input     i0, i1, i2, i3;
  input [1: 0]  select;
  reg       mux_out;
  always @ (select, i0, i1, i2, i3)
    case (select)
      2'b00:    mux_out = i0;
      2'b01:    mux_out = i1;
      2'b10:    mux_out = i2;
      2'b11:    mux_out = i3;
    endcase
endmodule


// Behavioral model of D flip-flop  // 模塊二
module D_flip_flop (Q, D, CLK, Clr_b);
  output    Q;
  input D, CLK, Clr_b;
  reg       Q;

  always @ (posedge CLK or negedge Clr_b)
    if (!Clr_b) Q <= 1'b0; else Q <= D;
endmodule



// One stage of shift register //模塊stage   用到模組1跟模組2
module stage (i0, i1, i2, i3, Q, select, CLK, Clr_b);
  input i0,     // circulation bit selection
    i1,     // data from left neighbor or serial input for shift-right
    i2,     // data from right neighbor or serial input for shift-left
    i3;     // data from parallel input
  output    Q;
  input [1: 0]  select;     // stage mode control bus
  input     CLK, Clr_b; // Clock, Clear for flip-flops
  wire      mux_out;

// instantiate mux and flip-flop
  Mux_4_x_1 M0  (mux_out, i0, i1, i2, i3, select);
  D_flip_flop   M1  (Q, mux_out, CLK, Clr_b);
endmodule



//用到模組stage
module Shift_Register_4_str (           // V2001, 2005
  output [3: 0]     A_par,              // Parallel output
  input [3: 0]  I_par,              // Parallel input
  input         s1, s0,             // Mode select
  input         MSB_in, LSB_in, CLK, Clear_b    // Serial inputs, clock, clear
);

// bus for mode control
  wire  [1:0]   select = {s1, s0};

// Instantiate the four stages
  stage ST0 (A_par[0], A_par[1], LSB_in, I_par[0], A_par[0], select, CLK, Clear_b);
  stage ST1 (A_par[1], A_par[2], A_par[0], I_par[1],A_par[1], select, CLK, Clear_b);
  stage ST2 (A_par[2], A_par[3], A_par[1], I_par[2], A_par[2], select, CLK, Clear_b);
  stage ST3 (A_par[3], MSB_in, A_par[2], I_par[3], A_par[3], select, CLK, Clear_b);
endmodule


module BCSR (
  output reg    [7: 0]  A_par,  // 輸出
  input     [7: 0]  I_par,  // 初始化
  input         s1, s0, // 選擇輸入
            MSB_in, LSB_in,     // Serial inputs
            CLK, Clear_b        // Clock and Clear_b
);
  always @ (posedge CLK, negedge Clear_b)
    if (~Clear_b) A_par <= 8'b00000000;
    else
      case ({s1, s0})
        2'b00: A_par <= A_par;               // 不改變
        2'b01: A_par <= {MSB_in, A_par[7: 1]};   // 右移
        2'b10: A_par <= {A_par[6: 0], LSB_in};   // 左移
        2'b11: A_par <= I_par;           // 初始化
      endcase
endmodule

module Mux_4_x_1 (mux_out, i0, i1, i2, i3, select);
    output reg mux_out;
    input i0, i1, i2, i3;
    input [1: 0] select;
    always @ (select, i0, i1, i2, i3)
        case (select)
            2'b00:    mux_out = i0;
            2'b01:    mux_out = i1;
            2'b10:    mux_out = i2;
            2'b11:    mux_out = i3;
        endcase
endmodule

module JK_FF (Q, J, K, CLK);
    output reg Q;
    input J, K;
    input CLK;

    always @ (posedge CLK)
    begin
        case ({J,K})
            2'b00: Q <= Q;
            2'b01: Q <= 1'b0;
            2'b10: Q <= 1'b1;
            2'b11: Q <= ~ Q;
        endcase
    end
endmodule

module Shift_Register (
    output reg [7:0] A_par,              // Parallel output
    input [7:0]  I_par,              // Parallel input
    input         s1, s0,             // Mode select
    input         MSB_in, LSB_in, CLK, Clear_b    // Serial inputs, clock, clear
);
    wire [7:0] temp;
    always @ (posedge CLK, negedge Clear_b)
    if (~Clear_b)
        temp <= 8'b00000000;
    else
    begin
        case ({s1,s0})
            2'b00: temp <= A_par;                   // 不改變
            2'b01: temp <= {MSB_in, A_par[7: 1]};   // 右移
            2'b10: temp <= {A_par[6: 0], LSB_in};   // 左移
            2'b11: temp <= I_par;                   // 初始化
        endcase
    end

    JK_FF ST0 (A_par[0], temp[0], ~temp[0], CLK);
    JK_FF ST1 (A_par[1], temp[1], ~temp[1], CLK);
    JK_FF ST2 (A_par[2], temp[2], ~temp[2], CLK);
    JK_FF ST3 (A_par[3], temp[3], ~temp[3], CLK);
    JK_FF ST4 (A_par[4], temp[4], ~temp[4], CLK);
    JK_FF ST5 (A_par[5], temp[5], ~temp[5], CLK);
    JK_FF ST6 (A_par[6], temp[6], ~temp[6], CLK);
    JK_FF ST7 (A_par[7], temp[7], ~temp[7], CLK);
endmodule