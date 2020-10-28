# Tested on CodeSourcery G++ Lite 2008q1, 2010q1-202, 2011.03
CROSS_COMPILE = arm-linux-gnueabi-
CURT_IMAGE = curt_image

CC = $(CROSS_COMPILE)gcc
LD = $(CROSS_COMPILE)ld
OBJCOPY = $(CROSS_COMPILE)objcopy

MACH_CFLAGS = -march=armv5te -mtune=xscale -Wa,-mcpu=xscale \
	      -mabi=aapcs-linux -mno-thumb-interwork -fno-stack-protector

CFLAGS += $(MACH_CFLAGS)

LDSCRIPT := ld-script.lds
LDFLAGS += \
	-e _start -p \
	-T $(LDSCRIPT) \
	-Map $(CURT_IMAGE).map

OBJCOPYFLAGS = \
	-O binary \
	-R .note -R .note.gnu.build-id -R .comment \
	-S

#######################################################################
# architecture dependence source
#######################################################################
HW_DEP_ASM_SRC = \
	start.S \
	asm_port.S \

HW_DEP_C_SRC = \
	device/serial.c \
	port.c

HW_DEP_C_OBJ = $(HW_DEP_C_SRC:.c=.o)
HW_DEP_ASM_OBJ = $(HW_DEP_ASM_SRC:.S=.o)

ALL_OBJS = $(SHELL_OBJ) $(HW_DEP_C_OBJ) $(HW_DEP_ASM_OBJ) $(KERNEL_OBJ) $(LIB_OBJ)
#######################################################################
# Make Rules
#######################################################################
all: flash-image

flash-image: $(CURT_IMAGE).bin
	./prepare-flash

$(CURT_IMAGE).bin: $(CURT_IMAGE).elf
	$(OBJCOPY) $(OBJCOPYFLAGS) $< $@

$(CURT_IMAGE).elf: $(ALL_OBJS)
	$(LD) $(LDFLAGS) \
		-o $(CURT_IMAGE).elf $(ALL_OBJS)

$(HW_DEP_C_OBJ) : %.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(HW_DEP_ASM_OBJ) : %.o : %.S
	$(CC) -c $(CFLAGS) $< -o $@

$(SHELL_OBJ) $(LIB_OBJ) $(KERNEL_OBJ) : %.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

run:
	./run-on-connex

clean:
	rm -f ./*.o

distclean:
	rm -f $(CURT_IMAGE).bin $(CURT_IMAGE).elf flash-image
