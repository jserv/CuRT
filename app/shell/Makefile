# Tested on CodeSourcery G++ Lite 2008q1
CROSS_COMPILE = arm-none-linux-gnueabi-
CURT_IMAGE = curt_image

CC = $(CROSS_COMPILE)gcc
LD = $(CROSS_COMPILE)ld
OBJCOPY = $(CROSS_COMPILE)objcopy

MACH_CFLAGS = -march=armv5te -mtune=xscale -Wa,-mcpu=xscale \
	      -mabi=aapcs-linux -mno-thumb-interwork -fno-stack-protector

CFLAGS = \
	-I../../includes/arch/arm/mach-pxa \
	-I../../includes \
	-Wall -Werror -Wno-error=unused-but-set-variable \
	-fno-builtin \
	-O0 -g $(MACH_CFLAGS)

LDSCRIPT := ld-script.lds
LDFLAGS = \
	-nostdlib -static -e _start \
	-p --no-undefined -X \
	-T $(LDSCRIPT) \
	-Map $(CURT_IMAGE).map

OBJCOPYFLAGS = \
	-O binary \
	-R .note -R .note.gnu.build-id -R .comment \
	-S

SHELL_SRC = ./main.c

HW_DEP_ASM_SRC = \
	../../arch/arm/mach-pxa/start.S \
	../../arch/arm/mach-pxa/asm_port.S \

HW_DEP_C_SRC = \
	../../device/serial.c \
	../../lib/stdio.c \
	../../arch/arm/mach-pxa/port.c

KERNEL_SRC = \
	../../kernel/kernel.c \
	../../kernel/thread.c \
	../../kernel/list.c   \
	../../kernel/sync.c  \
	../../kernel/ipc.c

SHELL_OBJ = $(SHELL_SRC:.c=.o)
HW_DEP_C_OBJ = $(HW_DEP_C_SRC:.c=.o)
HW_DEP_ASM_OBJ = $(HW_DEP_ASM_SRC:.S=.o)
KERNEL_OBJ = $(KERNEL_SRC:.c=.o)

$(CURT_IMAGE).bin: $(CURT_IMAGE).elf
	$(OBJCOPY) $(OBJCOPYFLAGS) $< $@

$(CURT_IMAGE).elf: $(SHELL_OBJ) $(HW_DEP_C_OBJ) $(HW_DEP_ASM_OBJ) $(KERNEL_OBJ)
	$(LD) $(LDFLAGS) \
		-o $(CURT_IMAGE).elf \
		$(SHELL_OBJ) $(HW_DEP_C_OBJ) $(HW_DEP_ASM_OBJ) $(KERNEL_OBJ)

$(SHELL_OBJ) : %.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(HW_DEP_C_OBJ) : %.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(HW_DEP_ASM_OBJ) : %.o : %.S
	$(CC) -c $(CFLAGS) $< -o $@

$(KERNEL_OBJ) : %.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@


clean:
	rm -f ../../arch/arm/mach-pxa/*.o \
	      ../../kernel/*.o \
	      ../../device/*.o \
	      ../../lib/*.o \
	      ./*.o \
	      $(CURT_IMAGE).bin $(CURT_IMAGE).elf \
	      flash-image
