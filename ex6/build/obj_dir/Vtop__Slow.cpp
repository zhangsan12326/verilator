// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

//==========
CData/*7:0*/ Vtop::__Vtable1_seg0[16];
CData/*7:0*/ Vtop::__Vtable2_seg1[16];

VL_CTOR_IMP(Vtop) {
    Vtop__Syms* __restrict vlSymsp = __VlSymsp = new Vtop__Syms(this, name());
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtop::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vtop::~Vtop() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vtop::_settle__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__2\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->clk_led = vlTOPp->top__DOT__clk_o;
    vlTOPp->__Vtableidx1 = (0xfU & (IData)(vlTOPp->top__DOT__LFSR_to_seg));
    vlTOPp->seg0 = vlTOPp->__Vtable1_seg0[vlTOPp->__Vtableidx1];
    vlTOPp->__Vtableidx2 = (0xfU & ((IData)(vlTOPp->top__DOT__LFSR_to_seg) 
                                    >> 4U));
    vlTOPp->seg1 = vlTOPp->__Vtable2_seg1[vlTOPp->__Vtableidx2];
}

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_initial\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__top__DOT__clk_o 
        = vlTOPp->__VinpClk__TOP__top__DOT__clk_o;
}

void Vtop::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::final\n"); );
    // Variables
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::_eval_settle(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_settle\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void Vtop::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_ctor_var_reset\n"); );
    // Body
    clk = 0;
    rst = 0;
    din = 0;
    din_en = 0;
    clk_led = 0;
    seg0 = 0;
    seg1 = 0;
    top__DOT__LFSR_to_seg = 0;
    top__DOT__clk_o = 0;
    top__DOT__i_clock__DOT__clk_counter = 0;
    __Vtableidx1 = 0;
    __Vtable1_seg0[0] = 3U;
    __Vtable1_seg0[1] = 0x9fU;
    __Vtable1_seg0[2] = 0x25U;
    __Vtable1_seg0[3] = 0xdU;
    __Vtable1_seg0[4] = 0x99U;
    __Vtable1_seg0[5] = 0x49U;
    __Vtable1_seg0[6] = 0x41U;
    __Vtable1_seg0[7] = 0x1fU;
    __Vtable1_seg0[8] = 1U;
    __Vtable1_seg0[9] = 9U;
    __Vtable1_seg0[10] = 0x11U;
    __Vtable1_seg0[11] = 0xc1U;
    __Vtable1_seg0[12] = 0x63U;
    __Vtable1_seg0[13] = 0x85U;
    __Vtable1_seg0[14] = 0x61U;
    __Vtable1_seg0[15] = 0x71U;
    __Vtableidx2 = 0;
    __Vtable2_seg1[0] = 3U;
    __Vtable2_seg1[1] = 0x9fU;
    __Vtable2_seg1[2] = 0x25U;
    __Vtable2_seg1[3] = 0xdU;
    __Vtable2_seg1[4] = 0x99U;
    __Vtable2_seg1[5] = 0x49U;
    __Vtable2_seg1[6] = 0x41U;
    __Vtable2_seg1[7] = 0x1fU;
    __Vtable2_seg1[8] = 1U;
    __Vtable2_seg1[9] = 9U;
    __Vtable2_seg1[10] = 0x11U;
    __Vtable2_seg1[11] = 0xc1U;
    __Vtable2_seg1[12] = 0x63U;
    __Vtable2_seg1[13] = 0x85U;
    __Vtable2_seg1[14] = 0x61U;
    __Vtable2_seg1[15] = 0x71U;
    __VinpClk__TOP__top__DOT__clk_o = 0;
    __Vchglast__TOP__top__DOT__clk_o = 0;
}
