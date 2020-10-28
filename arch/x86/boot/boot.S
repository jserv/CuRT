.code16

.text
	mov %cs, %ax
	mov %ax, %ds
	mov %ax, %es

	mov $message, %ax
	mov %ax, %bp
	mov $19, %cx
	mov $0x1301, %ax
	mov $0x0009, %bx
	mov $0, %dl
	int $0x10
	jmp .

message: .ascii "bootloader testing!"
.org 510
.word 0xaa55
