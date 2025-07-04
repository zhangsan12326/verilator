// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vmux41_module.h for the primary calling header

#ifndef VERILATED_VMUX41_MODULE___024ROOT_H_
#define VERILATED_VMUX41_MODULE___024ROOT_H_  // guard

#include "verilated.h"

class Vmux41_module__Syms;

class Vmux41_module___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(Y,1,0);
    VL_IN8(X0,1,0);
    VL_IN8(X1,1,0);
    VL_IN8(X2,1,0);
    VL_IN8(X3,1,0);
    VL_OUT8(F,1,0);
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*1:0*/, 4> mux41_module__DOT__i0__DOT__i0__DOT__key_list;
    VlUnpacked<CData/*1:0*/, 4> mux41_module__DOT__i0__DOT__i0__DOT__data_list;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vmux41_module__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vmux41_module___024root(Vmux41_module__Syms* symsp, const char* v__name);
    ~Vmux41_module___024root();
    VL_UNCOPYABLE(Vmux41_module___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
