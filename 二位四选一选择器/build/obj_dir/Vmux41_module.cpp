// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vmux41_module.h"
#include "Vmux41_module__Syms.h"

//============================================================
// Constructors

Vmux41_module::Vmux41_module(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vmux41_module__Syms(contextp(), _vcname__, this)}
    , Y{vlSymsp->TOP.Y}
    , X0{vlSymsp->TOP.X0}
    , X1{vlSymsp->TOP.X1}
    , X2{vlSymsp->TOP.X2}
    , X3{vlSymsp->TOP.X3}
    , F{vlSymsp->TOP.F}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vmux41_module::Vmux41_module(const char* _vcname__)
    : Vmux41_module(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vmux41_module::~Vmux41_module() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vmux41_module___024root___eval_debug_assertions(Vmux41_module___024root* vlSelf);
#endif  // VL_DEBUG
void Vmux41_module___024root___eval_static(Vmux41_module___024root* vlSelf);
void Vmux41_module___024root___eval_initial(Vmux41_module___024root* vlSelf);
void Vmux41_module___024root___eval_settle(Vmux41_module___024root* vlSelf);
void Vmux41_module___024root___eval(Vmux41_module___024root* vlSelf);

void Vmux41_module::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmux41_module::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vmux41_module___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vmux41_module___024root___eval_static(&(vlSymsp->TOP));
        Vmux41_module___024root___eval_initial(&(vlSymsp->TOP));
        Vmux41_module___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vmux41_module___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vmux41_module::eventsPending() { return false; }

uint64_t Vmux41_module::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vmux41_module::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vmux41_module___024root___eval_final(Vmux41_module___024root* vlSelf);

VL_ATTR_COLD void Vmux41_module::final() {
    Vmux41_module___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vmux41_module::hierName() const { return vlSymsp->name(); }
const char* Vmux41_module::modelName() const { return "Vmux41_module"; }
unsigned Vmux41_module::threads() const { return 1; }
