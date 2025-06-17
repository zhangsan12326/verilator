// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VMUX41_MODULE__SYMS_H_
#define VERILATED_VMUX41_MODULE__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vmux41_module.h"

// INCLUDE MODULE CLASSES
#include "Vmux41_module___024root.h"

// SYMS CLASS (contains all model state)
class Vmux41_module__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vmux41_module* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vmux41_module___024root        TOP;

    // CONSTRUCTORS
    Vmux41_module__Syms(VerilatedContext* contextp, const char* namep, Vmux41_module* modelp);
    ~Vmux41_module__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
