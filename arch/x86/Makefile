TARGET = CuRT-x86.img

CC = gcc
LD = ld

.SUFFIXES:.asm .bin .c .s .o .S
.PHONY:	all run clean

HW_DEP_ASM_SRC =

HW_DEP_ASM_OBJ = $(HW_DEP_ASM_SRC:.S=.o)

HW_DEP_C_SRC =

HW_DEP_C_OBJ = $(HW_DEP_C_SRC:.c=.o)

BOOT_OBJ = boot/boot.o boot/boot.bin

ALL_OBJS = $(SHELL_OBJ) $(KERNEL_OBJ) $(LIB_OBJ) \
	$(HW_DEP_ASM_OBJ) $(HW_DEP_C_OBJ) $(BOOT_OBJ)

CFLAGS += -fno-stack-protector
LDFLAGS +=

all: $(TARGET)

$(TARGET): boot/boot.bin
	dd if=/dev/zero of=$(TARGET) bs=512 count=2880
	dd if=boot/boot.bin of=$(TARGET) bs=512 seek=0 conv=notrunc

boot/boot.bin: boot/boot.o
	$(LD) $(LDFLAGS) --oformat binary -o boot/boot.bin -T boot/boot.ld $^

%.o:%.c
	$(CC) -c $(CFLAGS) $< -o $@

%.o:%.S
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(ALL_OBJS)

run: $(TARGET)
	qemu-system-x86_64 -m 32 -fda $< -boot a
