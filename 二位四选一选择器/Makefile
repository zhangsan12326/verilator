TOPNAME = mux41_module
NXDC_FILES = constr/top.nxdc	#约束文件路径
INC_PATH ?=	#?=的意义是，INC_PATH如果被未被定义，则为?=后的值，如果被定义过，则保持原来的值
 
VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc  \
				-O3 --x-assign fast --x-initial fast --noassert
 
BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj_dir	#OBJ_DIR = ./build/obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)	#BIN = ./build/top
 
default: $(BIN)	#终极目标为default，依赖./build/top
 
$(shell mkdir -p $(BUILD_DIR))
 
# constraint file
SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)
$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 ${NVBOARD_HOME}/scripts/auto_pin_bind.py $^ $@
 
# project source
VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")
# 在vsrc目录中寻找所有的.v文件，并保存在变量VSRCS中
CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")
# 在csrc目录中寻找所有的.c/.cc/.cpp文件，并保存在变量CSRCS中
CSRCS += $(SRC_AUTO_BIND)
# 将auto_bind.cpp文件，追加在变量CSRCS中
 
# rules for NVBoard
NVBOARD_HOME ?= /home/zjc/.ssh/ysyx-workbench/nvboard
export NVBOARD_HOME
include $(NVBOARD_HOME)/scripts/nvboard.mk
# 包含NVBoard相关Makelile规则
 
# rules for verilator
INCFLAGS = $(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""
CXXFLAGS += -I$(NVBOARD_HOME)/include \
						-I$(NVBOARD_HOME)/usr/include \
						-DUSE_NVBOARD \
						-DNVBOARD_UPDATE=nvboard_update
LDFLAGS += -L$(NVBOARD_HOME)/build -l:nvboard.a
LDFLAGS += -lSDL2 -lSDL2_image -lSDL2_ttf
 
$(BIN): $(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE)
	@rm -rf $(OBJ_DIR) # 生成新的对象之前，删除旧的对象文件
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOPNAME) $^ \
		$(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN))
 
all: default
	
run: $(BIN)
	@$^
 
clean:
	rm -rf $(BUILD_DIR)
 
.PHONY: default all clean run
 
