// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vmy_xor.h for the primary calling header

#ifndef VERILATED_VMY_XOR___024ROOT_H_
#define VERILATED_VMY_XOR___024ROOT_H_  // guard

#include "verilated.h"

class Vmy_xor__Syms;

class Vmy_xor___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(a,0,0);
    VL_IN8(b,0,0);
    VL_OUT8(f,0,0);
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vmy_xor__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vmy_xor___024root(Vmy_xor__Syms* symsp, const char* v__name);
    ~Vmy_xor___024root();
    VL_UNCOPYABLE(Vmy_xor___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
