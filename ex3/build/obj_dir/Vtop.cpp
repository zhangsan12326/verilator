// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

//==========

void Vtop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval\n"); );
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/home/xuhaitao/verilator/ex3/vsrc/top.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/home/xuhaitao/verilator/ex3/vsrc/top.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtop::_combo__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->c_out = (1U & ((~ ((IData)(vlTOPp->op) 
                               >> 2U)) & ((~ ((IData)(vlTOPp->op) 
                                              >> 1U)) 
                                          & ((1U & (IData)(vlTOPp->op))
                                              ? (1U 
                                                 & (((IData)(vlTOPp->a) 
                                                     - (IData)(vlTOPp->b)) 
                                                    >> 4U))
                                              : (1U 
                                                 & (((IData)(vlTOPp->a) 
                                                     + (IData)(vlTOPp->b)) 
                                                    >> 4U))))));
    if ((4U & (IData)(vlTOPp->op))) {
        if ((2U & (IData)(vlTOPp->op))) {
            if ((1U & (IData)(vlTOPp->op))) {
                vlTOPp->result = (((IData)(vlTOPp->a) 
                                   == (IData)(vlTOPp->b))
                                   ? 1U : 0U);
                vlTOPp->zero = 0U;
                vlTOPp->of = 0U;
            } else {
                vlTOPp->result = (((IData)(vlTOPp->a) 
                                   < (IData)(vlTOPp->b))
                                   ? 1U : 0U);
                vlTOPp->zero = 0U;
                vlTOPp->of = 0U;
            }
        } else {
            if ((1U & (IData)(vlTOPp->op))) {
                vlTOPp->result = ((IData)(vlTOPp->a) 
                                  ^ (IData)(vlTOPp->b));
                vlTOPp->zero = 0U;
                vlTOPp->of = 0U;
            } else {
                vlTOPp->result = ((IData)(vlTOPp->a) 
                                  | (IData)(vlTOPp->b));
                vlTOPp->zero = 0U;
                vlTOPp->of = 0U;
            }
        }
    } else {
        if ((2U & (IData)(vlTOPp->op))) {
            if ((1U & (IData)(vlTOPp->op))) {
                vlTOPp->result = ((IData)(vlTOPp->a) 
                                  & (IData)(vlTOPp->b));
                vlTOPp->zero = 0U;
                vlTOPp->of = 0U;
            } else {
                vlTOPp->result = (0xfU & (~ (IData)(vlTOPp->a)));
                vlTOPp->zero = 0U;
                vlTOPp->of = 0U;
            }
        } else {
            if ((1U & (IData)(vlTOPp->op))) {
                vlTOPp->result = (0xfU & ((IData)(vlTOPp->a) 
                                          - (IData)(vlTOPp->b)));
                vlTOPp->zero = ((0U == (IData)(vlTOPp->result))
                                 ? 1U : 0U);
                vlTOPp->of = (((1U & ((IData)(vlTOPp->a) 
                                      >> 3U)) == (1U 
                                                  & ((IData)(vlTOPp->b) 
                                                     >> 3U))) 
                              & ((1U & ((IData)(vlTOPp->result) 
                                        >> 3U)) != 
                                 (1U & ((IData)(vlTOPp->a) 
                                        >> 3U))));
            } else {
                vlTOPp->result = (0xfU & ((IData)(vlTOPp->a) 
                                          + (IData)(vlTOPp->b)));
                vlTOPp->zero = ((0U == (IData)(vlTOPp->result))
                                 ? 1U : 0U);
                vlTOPp->of = (((1U & ((IData)(vlTOPp->a) 
                                      >> 3U)) == (1U 
                                                  & ((IData)(vlTOPp->b) 
                                                     >> 3U))) 
                              & ((1U & ((IData)(vlTOPp->result) 
                                        >> 3U)) != 
                                 (1U & ((IData)(vlTOPp->a) 
                                        >> 3U))));
            }
        }
    }
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vtop::_change_request_1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request_1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtop::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((a & 0xf0U))) {
        Verilated::overWidthError("a");}
    if (VL_UNLIKELY((b & 0xf0U))) {
        Verilated::overWidthError("b");}
    if (VL_UNLIKELY((op & 0xf8U))) {
        Verilated::overWidthError("op");}
}
#endif  // VL_DEBUG
