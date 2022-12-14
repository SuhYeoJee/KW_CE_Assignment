module os_logic(state, d_in, d_out); //output logic
	parameter IDLE_STATE = 3'b000;
	parameter LOAD_STATE = 3'b001;
	parameter INC_STATE 	= 3'b010;
	parameter INC2_STATE = 3'b011;
	parameter DEC_STATE 	= 3'b100;
	parameter DEC2_STATE = 3'b101;
	
	input [2:0] state;
	input [7:0] d_in;
	output [7:0] d_out;
	reg [7:0] d_out;
	wire [7:0] d_inc, d_dec;
	wire co_inc, co_dec;
	
	always @ (state) //when state changes
	begin
		case(state)
			IDLE_STATE	:	d_out <= 8'b0;
			LOAD_STATE	:	d_out <= d_in;
			INC_STATE	:	d_out <= d_inc;
			INC2_STATE	:	d_out <= d_inc;
			DEC_STATE	:	d_out <= d_dec;
			DEC2_STATE	:	d_out <= d_dec;
			default		:	d_out <= 8'bx;
		endcase
	end
	
	cla8 U0_cla8(.a(d_out),.b(8'b00000001),.ci(0),.s(d_inc),.co(co_inc)); //inc/inc2
	cla8 U1_cla8(.a(d_out),.b(8'b11111110),.ci(~state[1]),.s(d_dec),.co(co_dec)); //dec/dec2
endmodule
		