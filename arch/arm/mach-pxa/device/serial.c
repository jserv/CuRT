/*
 * serial.c
 */

#include "arch/arm/mach-pxa/pxa255.h"
#include "kernel/types.h"

/* --- PXA255 specific implementation --- */

void SerialOutputByte(const char);
int SerialInputByte(char *);

void SerialInit(void)
{
	/* GP39, GP40, GP41 UART(10) */
        GAFR1_L |= 0x000A8000;
        GPDR1 |= 0x00000380;
	
        /* 8-bit, 1 stop, no parity */
	rFFLCR = 0x00000003;
	
	/* Reset tx, rx FIFO. clear. FIFO enable */
	rFFFCR = 0x00000007;
        
	/* UART Enable Interrupt */
	rFFIER = 0x00000040;

	/* DLAB set=latch registers, DLAB clear= . */
        rFFLCR |= 0x00000080;
        
	/* baud rate */
        rFFDLL = SERIAL_BAUD_115200;
	
	/* DLAB clear */
	rFFLCR &= 0xFFFFFF7F;
	
        /* Transmit Shift Register, Transmit Holding Register, FIFO
	 * wait for ready */
	while (!(rFFLSR & 0x00000040))
		/* wait */ ;

	return;
}

void SerialOutputByte(const char c)
{
	/* FIFO
	 * wait for ready */
	while ((rFFLSR & 0x00000020) == 0 )
		/* wait */ ;

	rFFTHR = ((ulong)c & 0xFF);

	/* regardless of c=='\n' or "\n\r", the same output. */
	if (c=='\n')
		SerialOutputByte('\r');
}
	        
int SerialInputByte(char *c)
{

	/* FIFO */
	if ((rFFLSR & 0x00000001) == 0) {
		return 0;
	}
	else {
		*(volatile char *) c = (char) rFFRBR;
		return 1;
	}
}

/**
 * @brief check if serial is ready
 * @retval 1 if the data received
 */
int SerialIsReadyChar(void)
{
	/* Make sure the data is received. */
	if (rFFLSR & 0x00000001)
	       	return 1;
	return 0;
}

/**
 * @brief Receives a character from serial device
 * @retval
 */
char SerialIsGetChar(void)
{
	/* received data */
	return (char) rFFRBR;
}
