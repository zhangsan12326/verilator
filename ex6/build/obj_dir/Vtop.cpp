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
            VL_FATAL_MT("/home/xuhaitao/verilator/ex6/vsrc/top.v", 1, "",
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
            VL_FATAL_MT("/home/xuhaitao/verilator/ex6/vsrc/top.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdly__top__DOT__clk_o;
    IData/*31:0*/ __Vdly__top__DOT__i_clock__DOT__clk_counter;
    // Body
    __Vdly__top__DOT__i_clock__DOT__clk_counter = vlTOPp->top__DOT__i_clock__DOT__clk_counter;
    __Vdly__top__DOT__clk_o = vlTOPp->top__DOT__clk_o;
    if (vlTOPp->rst) {
        __Vdly__top__DOT__i_clock__DOT__clk_counter = 0U;
        __Vdly__top__DOT__clk_o = 0U;
    } else {
        if ((0x4c4b40U == vlTOPp->top__DOT__i_clock__DOT__clk_counter)) {
            __Vdly__top__DOT__clk_o = (1U & (~ (IData)(vlTOPp->top__DOT__clk_o)));
            __Vdly__top__DOT__i_clock__DOT__clk_counter = 0U;
        } else {
            __Vdly__top__DOT__i_clock__DOT__clk_counter 
                = ((IData)(1U) + vlTOPp->top__DOT__i_clock__DOT__clk_counter);
        }
    }
    vlTOPp->top__DOT__i_clock__DOT__clk_counter = __Vdly__top__DOT__i_clock__DOT__clk_counter;
    vlTOPp->top__DOT__clk_o = __Vdly__top__DOT__clk_o;
}

VL_INLINE_OPT void Vtop::_combo__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_combo__TOP__3\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->clk_led = vlTOPp->top__DOT__clk_o;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__4\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__LFSR_to_seg = ((IData)(vlTOPp->rst)
                                      ? 0U : ((IData)(vlTOPp->din_en)
                                               ? (IData)(vlTOPp->din)
                                               : ((0x80U 
                                                   & ((((0xffffff80U 
                                                         & ((IData)(vlTOPp->top__DOT__LFSR_to_seg) 
                                                            << 3U)) 
                                                        ^ 
                                                        (0xffffff80U 
                                                         & ((IData)(vlTOPp->top__DOT__LFSR_to_seg) 
                                                            << 4U))) 
                                                       ^ 
                                                       (0xffffff80U 
                                                        & ((IData)(vlTOPp->top__DOT__LFSR_to_seg) 
                                                           << 5U))) 
                                                      ^ 
                                                      ((IData)(vlTOPp->top__DOT__LFSR_to_seg) 
                                                       << 7U))) 
                                                  | (0x7fU 
                                                     & ((IData)(vlTOPp->top__DOT__LFSR_to_seg) 
                                                        >> 1U)))));
    vlTOPp->__Vtableidx1 = (0xfU & (IData)(vlTOPp->top__DOT__LFSR_to_seg));
    vlTOPp->seg0 = vlTOPp->__Vtable1_seg0[vlTOPp->__Vtableidx1];
    vlTOPp->__Vtableidx2 = (0xfU & ((IData)(vlTOPp->top__DOT__LFSR_to_seg) 
                                    >> 4U));
    vlTOPp->seg1 = vlTOPp->__Vtable2_seg1[vlTOPp->__Vtableidx2];
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    vlTOPp->_combo__TOP__3(vlSymsp);
    if (((IData)(vlTOPp->__VinpClk__TOP__top__DOT__clk_o) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__clk_o)))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__clk_o 
        = vlTOPp->__VinpClk__TOP__top__DOT__clk_o;
    vlTOPp->__VinpClk__TOP__top__DOT__clk_o = vlTOPp->top__DOT__clk_o;
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
    __req |= ((vlTOPp->top__DOT__clk_o ^ vlTOPp->__Vchglast__TOP__top__DOT__clk_o));
    VL_DEBUG_IF( if(__req && ((vlTOPp->top__DOT__clk_o ^ vlTOPp->__Vchglast__TOP__top__DOT__clk_o))) VL_DBG_MSGF("        CHANGE: /home/xuhaitao/verilator/ex6/vsrc/top.v:13: top.clk_o\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__top__DOT__clk_o = vlTOPp->top__DOT__clk_o;
    return __req;
}

#ifdef VL_DEBUG
void Vtop::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((din_en & 0xfeU))) {
        Verilated::overWidthError("din_en");}
}
#endif  // VL_DEBUG
