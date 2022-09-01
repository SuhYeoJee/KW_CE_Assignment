#include <systemc.h>
#include "CBA.h"
#include "tb.h"

SC_MODULE(SYSTEM) {
	cba32* cba32_0= NULL;	//CBA
	tb* tb_0 = NULL;		//testbench

	sc_clock clk_sig;		//clock

	sc_signal< sc_int<32> > A_sig;		//adder input, tb output
	sc_signal<sc_int<1> > A_valid_sig;
	sc_signal<sc_int<1> > A_ready_sig;

	sc_signal< sc_int<32> > B_sig;		//adder input, tb output
	sc_signal<sc_int<1> > B_valid_sig;
	sc_signal<sc_int<1> > B_ready_sig;

	sc_signal< sc_int<1> > Cin_sig;		//adder input, tb output
	sc_signal<sc_int<1> > Cin_valid_sig;
	sc_signal<sc_int<1> > Cin_ready_sig;

	sc_signal< sc_int<32> > result_sig;	//adder output, tb input
	sc_signal<sc_int<1> > result_valid_sig;
	sc_signal<sc_int<1> > result_ready_sig;

	sc_signal< sc_int<1> > Cout_sig;	//adder output, tb input
	sc_signal<sc_int<1> > Cout_valid_sig;
	sc_signal<sc_int<1> > Cout_ready_sig;


	SC_CTOR(SYSTEM) :clk_sig("clk_sig", 1, SC_NS) {
		cba32_0 = new cba32("cba32_0");		//CBA
		cba32_0->clk(clk_sig);
		
		cba32_0->A(A_sig);
		cba32_0->A_valid(A_valid_sig);
		cba32_0->A_ready(A_ready_sig);

		cba32_0->B(B_sig);
		cba32_0->B_valid(B_valid_sig);
		cba32_0->B_ready(B_ready_sig);

		cba32_0->Cin(Cin_sig);
		cba32_0->Cin_valid(Cin_valid_sig);
		cba32_0->Cin_ready(Cin_ready_sig);

		cba32_0->result(result_sig);
		cba32_0->result_valid(result_valid_sig);
		cba32_0->result_ready(result_ready_sig);

		cba32_0->Cout(Cout_sig);
		cba32_0->Cout_valid(Cout_valid_sig);
		cba32_0->Cout_ready(Cout_ready_sig);

		tb_0 = new tb("tb_0");				//Test bench
		tb_0->clk(clk_sig);

		tb_0->A(A_sig);
		tb_0->A_valid(A_valid_sig);
		tb_0->A_ready(A_ready_sig);

		tb_0->B(B_sig);
		tb_0->B_valid(B_valid_sig);
		tb_0->B_ready(B_ready_sig);

		tb_0->Cin(Cin_sig);
		tb_0->Cin_valid(Cin_valid_sig);
		tb_0->Cin_ready(Cin_ready_sig);

		tb_0->result(result_sig);
		tb_0->result_valid(result_valid_sig);
		tb_0->result_ready(result_ready_sig);

		tb_0->Cout(Cout_sig);
		tb_0->Cout_valid(Cout_valid_sig);
		tb_0->Cout_ready(Cout_ready_sig);
	}

	~SYSTEM() {
		delete cba32_0;
		delete tb_0;
	}
};