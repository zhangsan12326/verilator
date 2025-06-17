#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>  // 添加usleep函数需要
#include <verilated.h>
#include "Vmux41_module.h"  // Verilator生成的头文件
#include "nvboard.h"        // NVBoard头文件
 
// NVBoard引脚绑定函数
static void nvboard_bind_all_pins(Vmux41_module* dut) {
    // 绑定输入a[3:0]到4个开关
    nvboard_bind_pin(&dut->Y, 2, SW1, SW0);
    // 绑定选择信号s[1:0]到2个开关
    nvboard_bind_pin(&dut->X0, 2, SW3, SW2);
		nvboard_bind_pin(&dut->X1, 2, SW5, SW4);
		nvboard_bind_pin(&dut->X2, 2, SW7, SW6);
		nvboard_bind_pin(&dut->X3, 2, SW9, SW8);
    // 绑定输出y到LED
    nvboard_bind_pin(&dut->F, 2, LD1, LD0);
}
 
int main(int argc, char** argv, char** env) {
    // 初始化NVBoard
    nvboard_init();
    
    // 初始化Verilator
    Verilated::commandArgs(argc, argv);
    Vmux41_module *dut = new Vmux41_module;
    
    // 绑定NVBoard引脚
    nvboard_bind_all_pins(dut);
    
    // 主仿真循环
    while (1) {
        // 更新NVBoard输入状态
        nvboard_update();
        
        // 评估模型
        dut->eval();
        
        // 更新NVBoard显示
//        nvboard_display();
        
        // 添加小延迟以减少CPU占用
        usleep(10000);  // 10ms
    }
    
    // 清理（通常不会执行到这里）
    nvboard_quit();
    delete dut;
    return 0;
}
