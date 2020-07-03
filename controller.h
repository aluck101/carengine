//
// Created by aluck on 03.07.20.
//
#include <systemc.h>
#include "modules.h"
#include "tb.h"

SC_MODULE(contoller) {

    ctrl_fsm_state ctrlFsmState;
    ctrl_fsm ctrlFsm;
    toggle_proc toggleProc;
    inst_reg_proc instRegProc;

    sc_clock clk;
    sc_in_clk clock;

    sc_in<sc_uint<2>> stp;
    sc_in<bool> rst;
    sc_in<bool> uSeq_bus;


    SC_CTOR(contoller):ctrlFsmState("ctrlFsmState"),ctrlFsm("ctrlFsm"),toggleProc("toggleProc"), instRegProc("instRegProc") {
        ctrlFsm.stp;

    }


};