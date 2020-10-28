ARCH = x86
ARCH_SRC_DIR = arch/x86
#ARCH = pxa255
#ARCH_SRC_DIR = arch/arm/mach-pxa

#######################################################################
# path setting
#######################################################################
TOP_DIR = $(shell pwd)
INCLUDE_DIR = -I$(TOP_DIR)/include/$(ARCH_SRC_DIR) -I$(TOP_DIR)/include

#######################################################################
# compiler / linker setting
#######################################################################
CFLAGS = \
	$(INCLUDE_DIR) -Wall $(DEFS)\
	-fno-builtin -O0 -g $(MACH_CFLAGS)

LDFLAGS = \
	-nostdlib -static --no-undefined -X

#######################################################################
# source / object file list
#######################################################################
# hardware indepedent
KERNEL_SRC = \
	$(TOP_DIR)/kernel/kernel.c \
	$(TOP_DIR)/kernel/thread.c \
	$(TOP_DIR)/kernel/list.c   \
	$(TOP_DIR)/kernel/sync.c  \
	$(TOP_DIR)/kernel/ipc.c

LIB_SRC = \
	$(TOP_DIR)/lib/stdio.c

SHELL_SRC = \
	$(TOP_DIR)/app/shell/main.c

KERNEL_OBJ = $(KERNEL_SRC:.c=.o)
SHELL_OBJ = $(SHELL_SRC:.c=.o)
LIB_OBJ = $(LIB_SRC:.c=.o)

export

#######################################################################
# Make Rules
#######################################################################

.PHONY: all run clean clean-all

all:
	$(MAKE) -C $(ARCH_SRC_DIR)

clean:
	rm -f $(KERNEL_OBJ) $(SHELL_OBJ) $(LIB_OBJ)
	$(MAKE) -C $(ARCH_SRC_DIR) clean

run: all
	$(MAKE) -C $(ARCH_SRC_DIR) run
