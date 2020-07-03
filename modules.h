//
// Created by aluck on 03.07.20.
//

#include <systemc.h>

SC_MODULE(ctrl_fsm_state) {
    sc_in_clk clock;
    sc_in<bool>next_state;
    sc_out<bool>curr_state;

    void doAction();

    SC_CTOR(ctrl_fsm_state) {
        sensitive << clock.pos();
        sensitive << next_state;
        SC_THREAD(doAction);
    }
};

SC_MODULE(ctrl_fsm) {
    sc_in<bool> rst, stp, curr_state;
    sc_out<bool> next_state, toggle, ldinst, lddir;
    void doAction();
    SC_CTOR(ctrl_fsm){
        sensitive << rst << stp << curr_state;
        SC_THREAD(doAction);
    }
};
SC_MODULE(toggle_proc) {
    sc_in<bool> toggle;
    sc_in_clk clock;
    sc_in<bool> tgl_cnt;
    void doAction();

    SC_CTOR(toggle_proc){
        sensitive << toggle;
        sensitive << clock.pos();
        SC_METHOD(doAction)
    }
};
SC_MODULE(inst_reg_proc) {
    sc_in<bool> uSeq_bus;
    sc_in_clk clock;
    sc_in<bool> ldinst;
    sc_out<bool> reverse;

    void doAction();

    SC_CTOR(inst_reg_proc){
        sensitive << uSeq_bus;
        sensitive << clock.pos();
        SC_THREAD(doAction);
    }
};


