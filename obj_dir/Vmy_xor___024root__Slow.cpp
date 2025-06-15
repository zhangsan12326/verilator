// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmy_xor.h for the primary calling header

#include "verilated.h"

#include "Vmy_xor__Syms.h"
#include "Vmy_xor___024root.h"

void Vmy_xor___024root___ctor_var_reset(Vmy_xor___024root* vlSelf);

Vmy_xor___024root::Vmy_xor___024root(Vmy_xor__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vmy_xor___024root___ctor_var_reset(this);
}

void Vmy_xor___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vmy_xor___024root::~Vmy_xor___024root() {
}
