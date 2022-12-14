module alu4(a,b,op,result,c,n,z,v); //4bits arithmetic logic unit
	input [3:0] a,b;
	input [2:0] op;
	output [3:0] result;
	output c,n,z,v;
	wire [3:0] w_not_a, w_not_b, w_and, w_or, w_xor, w_xnor, w_add, w_sub;
	wire c3_add, co_add, c3_sub, co_sub;
	
	_inv_4bits U0_inv_4bits(.a(a),.y(w_not_a)); // Not A
	_inv_4bits U1_inv_4bits(.a(b),.y(w_not_b)); // Not B
	_and2_4bits U2_and2_4bits(.a(a),.b(b),.y(w_and)); // And
	_or2_4bits U3_or2_4bits(.a(a),.b(b),.y(w_or)); // Or
	_xor2_4bits U4_xor2_4bits(.a(a),.b(b),.y(w_xor)); // xor
	_xnor2_4bits U5_xnor2_4bits(.a(a),.b(b),.y(w_xnor)); // xnor
	cla4_ov U6_cla4_ov(.a(a),.b(b),.ci(0),.s(w_add),.co(co_add),.c3(c3_add)); // add
	cla4_ov U7_cla4_ov(.a(a),.b(w_not_b),.ci(1),.s(w_sub),.co(co_sub),.c3(c3_sub)); // sub
	
	// select 1 operation
	mx8_4bits U8_mx8_4bits(.a(w_not_a), .b(w_not_b), .c(w_and), .d(w_or), .e(w_xor), .f(w_xnor),
					.g(w_add), .h(w_sub), .s0(op[0]),.s1(op[1]),.s2(op[2]), .y(result));
	
	// calculate flags
	cal_flags4 U9_cal_flags4(.op(op),.result(result),.co_add(co_add),.c3_add(c3_add),
					.co_sub(co_sub),.c3_sub(c3_sub),.c(c),.n(n),.z(z),.v(v));
	endmodule
	