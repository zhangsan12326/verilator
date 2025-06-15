#include <Vmy_xor.h>
#include <verilated.h>
#include <verilated_vcd_c.h>

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char** argv, char** env) {
    Verilated::commandArgs(argc, argv);
    Vmy_xor* top = new Vmy_xor;
    
    // 开启波形跟踪
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("waveform.vcd");

    int num_tests = 100;
    int test_count = 0;
    int time = 0;

    while (test_count < num_tests) {
        int a = rand() & 1;
        int b = rand() & 1;
        top->a = a;
        top->b = b;
        top->eval();
        printf("a = %d, b = %d, f = %d\n", a, b, top->f);
        assert(top->f == (a ^ b));

        tfp->dump(time);
        time++;
        test_count++;
    }

    tfp->close();
    top->final();
    delete top;
    delete tfp;
    return 0;
}
