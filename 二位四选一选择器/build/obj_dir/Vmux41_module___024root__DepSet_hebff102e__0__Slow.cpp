// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmux41_module.h for the primary calling header

#include "verilated.h"

#include "Vmux41_module___024root.h"

VL_ATTR_COLD void Vmux41_module___024root___eval_static(Vmux41_module___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux41_module__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux41_module___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vmux41_module___024root___eval_initial__TOP(Vmux41_module___024root* vlSelf);

VL_ATTR_COLD void Vmux41_module___024root___eval_initial(Vmux41_module___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux41_module__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux41_module___024root___eval_initial\n"); );
    // Body
    Vmux41_module___024root___eval_initial__TOP(vlSelf);
}

VL_ATTR_COLD void Vmux41_module___024root___eval_initial__TOP(Vmux41_module___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux41_module__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux41_module___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->mux41_module__DOT__i0__DOT__i0__DOT__key_list[0U] = 3U;
    vlSelf->mux41_module__DOT__i0__DOT__i0__DOT__key_list[1U] = 2U;
    vlSelf->mux41_module__DOT__i0__DOT__i0__DOT__key_list[2U] = 1U;
    vlSelf->mux41_module__DOT__i0__DOT__i0__DOT__key_list[3U] = 0U;
}

VL_ATTR_COLD void Vmux41_module___024root___eval_final(Vmux41_module___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux41_module__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux41_module___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vmux41_module___024root___eval_triggers__stl(Vmux41_module___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vmux41_module___024root___dump_triggers__stl(Vmux41_module___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vmux41_module___024root___eval_stl(Vmux41_module___024root* vlSelf);

VL_ATTR_COLD void Vmux41_module___024root___eval_settle(Vmux41_module___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux41_module__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux41_module___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vmux41_module___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vmux41_module___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("/home/xuhaitao/verilator2/vsrc/mux41_module.v", 54, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vmux41_module___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmux41_module___024root___dump_triggers__stl(Vmux41_module___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux41_module__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux41_module___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vmux41_module___024root___ico_sequent__TOP__0(Vmux41_module___024root* vlSelf);

VL_ATTR_COLD void Vmux41_module___024root___eval_stl(Vmux41_module___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux41_module__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux41_module___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vmux41_module___024root___ico_sequent__TOP__0(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmux41_module___024root___dump_triggers__ico(Vmux41_module___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux41_module__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux41_module___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VicoTriggered.at(0U)) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmux41_module___024root___dump_triggers__act(Vmux41_module___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux41_module__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux41_module___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmux41_module___024root___dump_triggers__nba(Vmux41_module___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux41_module__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux41_module___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vmux41_module___024root___ctor_var_reset(Vmux41_module___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux41_module__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux41_module___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->Y = 0;
    vlSelf->X0 = 0;
    vlSelf->X1 = 0;
    vlSelf->X2 = 0;
    vlSelf->X3 = 0;
    vlSelf->F = 0;
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->mux41_module__DOT__i0__DOT__i0__DOT__key_list[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->mux41_module__DOT__i0__DOT__i0__DOT__data_list[__Vi0] = 0;
    }
}
