/*! \file pxa255.h
 *  \brief register definitions for the PXA255 on-chip peripherals.
 */

#define vulong volatile unsigned long

/* --------------------------------------- */
/** Memory Controller */
#define MSC_BASE	0x48000000
#define MSC_REG(_x_)	*(vulong *)(MSC_BASE + _x_)


//---------------------------------------
/** UARTs */
#define FF_UART_BASE		0x40100000	/* Full Function UART Base Address */
#define FF_UART_REG(_x_)	*(vulong *)(FF_UART_BASE + _x_)
#define BT_UART_BASE		0x40200000	/* Bluetooth UART Base Address */
#define BT_UART_REG(_x_)	*(vulong *)(BT_UART_BASE + _x_)
#define STD_UART_BASE		0x40700000	/* Standard UART Base Address */
#define STD_UART_REG(_x_)	*(vulong *)(STD_UART_BASE + _x_)

#define UART_RBR	0x00	/* Receive Buffer Register (read only) */
#define UART_THR	0x00	/* Transmit Holding Register (write only) */
#define UART_IER	0x04	/* Interrupt Enable Register (read/write) */
#define UART_IIR	0x08	/* Interrupt ID Register (read only) */
#define UART_FCR	0x08	/* FIFO Control Register (write only) */
#define UART_LCR	0x0C	/* Line Control Register (read/write) */
#define UART_MCR	0x10	/* Modem Control Register (read/write) */
#define UART_LSR	0x14	/* Line Status Register (read only) */
#define UART_MSR	0x18	/* Modem Status Register (read only) */
#define UART_SPR	0x1C	/* Scratch Pad Register (read/write) */
#define UART_DLL	0x00	/* Baud divisor lower byte (read/write) */
#define UART_DLH	0x04	/* Baud divisor higher byte (read/write) */
#define UART_ISR	0x20	/* Infrared Select Register (read/write) */

/* --------------------------------------- */
/** OS Timer */
#define TMR_BASE	0x40A00000
#define TMR_REG(_x_)	*(vulong *)(TMR_BASE + _x_)
#define TMR_OSMR0	0x00	/* OS timer match registers<3:0> */
#define TMR_OSMR1	0x04	/* */
#define TMR_OSMR2	0x08	/* */
#define TMR_OSMR3	0x0C	/* */
#define TMR_OSCR	0x10	/* OS timer counter register */
#define TMR_OSSR	0x14	/* OS timer status register */
#define TMR_OWER	0x18	/* OS timer watchdog enable register */
#define TMR_OIER	0x1C	/* OS timer interrupt enable register */


/* --------------------------------------- */
/** Interrupt Control */
#define INT_BASE	0x40D00000	/* Interrupt controller IRQ pending register */
#define INT_REG(_x_)	*(vulong *)(INT_BASE + _x_)
#define INT_ICIP	0x00	/* Interrupt controller IRQ pending register */
#define INT_ICMR	0x04	/* Interrupt controller mask register */
#define INT_ICLR	0x08	/* Interrupt controller level register */
#define INT_ICFP	0x0C	/* Interrupt controller FIQ pending register */
#define INT_ICPR	0x10	/* Interrupt controller pending register */
#define INT_ICCR	0x14	/* Interrupt controller control register */


/* --------------------------------------- */
/** Clocks Manager */
#define CLK_BASE	0x41300000   
#define CLK_REG(_x_)	*(vulong *)(CLK_BASE + _x_)	
#define CLK_CCCR	0x00	/* Core Clock Configuration Register */
#define CLK_CKEN	0x04	/* Clock Enable Register */
#define CLK_OSCC	0x08	/* Oscillator Configuration Register */


/* --------------------------------------- */
/** Memory Controller Register */
#define MSC_MDCNFG	0x00	/* SDRAM configuration register 0 */
#define MSC_MDREFR	0x04	/* SDRAM refresh control register */
#define MSC_MSC0	0x08	/* Static memory control register 0 */
#define MSC_MSC1	0x0C	/* Static memory control register 1 */
#define MSC_MSC2	0x10	/* Static memory control register 2 */
#define MSC_MECR	0x14	/* Expansion memory (PCMCIA / Compact Flash)
				   bus configuration register */
#define MSC_SXCNFG	0x1C	/* Synchronous static memory control register */
#define MSC_SXMRS	0x24	/* MRS value to be written to Synchronous
				   Flash or SMROM */
#define MSC_MCMEM0	0x28	/* Card interface Common Memory Space
				   Socket 0 Timing Configuration */
#define MSC_MCMEM1	0x2C	/* Card interface Common Memory Space
				   Socket 1 Timing Configuration */
#define MSC_MCATT0	0x30	/* Card interface Attribute Space
				   Socket 0 Timing Configuration */
#define MSC_MCATT1	0x34	/* Card interface Attribute Space
				   Socket 1 Timing Configuration */
#define MSC_MCIO0	0x38	/* Card interface I/O Space Socket 0
				   Timing Configuration */
#define MSC_MCIO1	0x3C	/* Card interface I/O Space Socket 1
				   Timing Configuration */
#define MSC_MDMRS	0x40	/* MRS value to be written to SDRAM */
#define MSC_BOOTDEF	0x44	/* Read-Only Boot-time register.
				   Contains BOOT_SEL and PKG_SEL values. */

/** SDRAM configuration register 0 */
/* Pair 2/3 */
#define MDCNFG_DSA1111_1	BIT28	/* Use SA1111 Addressing Muxing Mode
					   for pair 2/3. */
#define MDCNFG_DLATCH1		BIT27	/* Return Data from SDRAM latching
					   scheme for pair 2/3, must be 1 */
#define MDCNFG_DADDR1		BIT26	/* Use alternate addressing for pair 2/3 */
#define MDCNFG_DTC1_0		(0x00 << 24)	/* 00 - tRP = 2 clks, CL = 2,
						   tRCD = 1 clks,
						   tRAS(min) = 3 clks,
						   tRC = 4 clks */
#define MDCNFG_DTC1_1		(0x01 << 24)	/* 01 - tRP = 2 clks, CL = 2,
						   tRCD = 2 clks,
						   tRAS(min) = 5 clks,
						   tRC = 8 clks */
#define MDCNFG_DTC1_2		(0x02 << 24)	/* 10 - tRP = 3 clks, CL = 3,
						   tRCD = 3 clks,
						   tRAS(min) =7 clks,
						   tRC=10 clks */
#define MDCNFG_DTC1_3		(0x03 << 24)	/* 11 - tRP = 3 clks, CL = 3,
						   tRCD = 3 clks,
						   tRAS(min) = 7 clks,
						   tRC = 11 clks */
#define MDCNFG_DNB1		BIT23		/* Number of banks in partition
						   pair 2/3, 0 = 2, 1 = 4 */
#define MDCNFG_DRAC1_11		(0x00 << 21)	/* SDRAM row address bit count
						   for partition pair 2/3 */
#define MDCNFG_DRAC1_12		(0x01 << 21)
#define MDCNFG_DRAC1_13		(0x02 << 21)
#define MDCNFG_DCAC1_8		(0x00 << 19)	/* Number of Column Address bits
						   for partition pair 2/3 */
#define MDCNFG_DCAC1_9		(0x01 << 19)
#define MDCNFG_DCAC1_10		(0x02 << 19)
#define MDCNFG_DCAC1_11		(0x03 << 19)
#define MDCNFG_DWID2_16		BIT18		/* SDRAM data bus width
						   for partition pair 2/3 */
#define MDCNFG_DE3		BIT17		/* SDRAM enable for partition 3 */
#define MDCNFG_DE2		BIT16		/* SDRAM enable for partition 2 */
/* Pair 0/1 */
#define MDCNFG_DSA1111_0	BIT12		/* Use SA1111 Addressing Muxing Mode
						   for pair 0/1. */
#define MDCNFG_DLATCH0		BIT11		/* Return Data from SDRAM latching
						   scheme for pair 0/1, must be 1 */
#define MDCNFG_DADDR0		BIT10		/* Use alternate addressing 
						   for pair 0/1 */
#define MDCNFG_DTC0_0		(0x00 << 8)	/* 00 - tRP = 2 clks, CL = 2,
						   tRCD = 1 clks,
						   tRAS(min) = 3 clks,
						   tRC = 4 clks */
#define MDCNFG_DTC0_1		(0x01 << 8)	/* 01 - tRP = 2 clks, CL = 2,
						   tRCD = 2 clks,
						   tRAS(min) = 5 clks,
						   tRC = 8 clks */
#define MDCNFG_DTC0_2		(0x02 << 8)	/* 10 - tRP = 3 clks, CL = 3,
						   tRCD = 3 clks,
						   tRAS(min) = 7 clks,
						   tRC=10 clks */
#define MDCNFG_DTC0_3		(0x03 << 8)	/* 11 - tRP = 3 clks, CL = 3,
						   tRCD = 3 clks,
						   tRAS(min) = 7 clks,
						   tRC = 11 clks */
#define MDCNFG_DNB0		BIT7		/* Number of banks in partition
						   pair 0/1, 0 = 2, 1 = 4 */
#define MDCNFG_DRAC0_11		(0x00 << 5)	/* SDRAM row address bit count
						   for partition pair 0/1 */
#define MDCNFG_DRAC0_12		(0x01 << 5)
#define MDCNFG_DRAC0_13		(0x02 << 5)
#define MDCNFG_DCAC0_8		(0x00 << 3)	/* Number of Column Address bits
						   for partition pair 0/1 */
#define MDCNFG_DCAC0_9		(0x01 << 3)
#define MDCNFG_DCAC0_10		(0x02 << 3)
#define MDCNFG_DCAC0_11		(0x03 << 3)
#define MDCNFG_DWID0_16	BIT2			/* SDRAM data bus width for
						   partition pair 0/1,
						   0 = 32, 1 = 16 */
#define MDCNFG_DE1		BIT1		/* SDRAM enable for partition 1 */
#define MDCNFG_DE0		BIT0		/* SDRAM enable for partition 0 */

/** SDRAM refresh control register */
#define MDREFR_K2FREE		BIT25		/* 1 = SDCLK2 is free-running
						   (ignores MDREFR[APD] or
						   MDREFR[K2RUN] bits) */
#define MDREFR_K1FREE		BIT24		/* 1 = SDCLK1 is free-running
						   (ignores MDREFR[APD] or
						   MDREFR[K1RUN] bits) */
#define MDREFR_K0FREE		BIT23		/* 1 = SDCLK0 is free-running
						   (ignores MDREFR[APD] or
						   MDREFR[K0RUN] bits) */
#define MDREFR_SLFRSH		BIT22		/* 1 = SDRAM Self-Refresh Enabled */
#define MDREFR_APD		BIT20		/* 1 = SDRAM/Synchronous Static
						   Memory Auto-Power-Down Enable. */
#define MDREFR_K2DB2		BIT19		/* SDCLK2 Divide by 2,
						   1 = Divide by 2 */
#define MDREFR_K2RUN		BIT18		/* SDCLK2 Run Control, 1 = Run */
#define MDREFR_K1DB2		BIT17		/* SDCLK1 Divide by 2,
						   1 = Divide by 2 */
#define MDREFR_K1RUN		BIT16		/* SDCLK1 Run Control, 1 = Run */
#define MDREFR_E1PIN		BIT15		/* SDCKE1 Level Control,
						   1 = Enabled */
#define MDREFR_K0DB2		BIT14		/* SDCLK0 Divide by 2,
						   1 = Divide by 2 */
#define MDREFR_K0RUN		BIT13		/* SDCLK0 Run Control, 1 = Run */
#define MDREFR_E0PIN		BIT12		/* SDCKE0 Level Control,
						   1 = Enabled */
#define MDREFR_DRI(_x_)		(_x_ & 0xfff)	/* Refresh Interval = 
						   (Refresh time/rows) x (MEMCLK/32) */

/** Full Function UART */
#define FFUART_BASE	0x40100000

#define FFRBR		0x00
#define FFTHR		0x00
#define FFIER		0x04
#define FFIIR		0x08
#define FFFCR		0x08
#define FFLCR		0x0C
#define FFMCR		0x10
#define FFLSR		0x14
#define FFMSR		0x18
#define FFSPR		0x1C
#define FFISR		0x20
#define FFDLL		0x00
#define FFDLH		0x04

/* FFUART Register initial values (9600 bps, 8N1) */
#define FFIER_VALUE		0x00000057
#define FFFCR_VALUE		0x00000041
#define FFLCR_VALUE_SETUP	0x00000083
#define FFLCR_VALUE_USAGE	0x00000003
#define FFMCR_VALUE		0x00000000
#define FFSPR_VALUE		0x00000000
#define FFISR_VALUE		0x00000000
#define FFDLL_VALUE		0x00000000	// 0x00000018 ?
#define FFDLH_VALUE		0x00000010

#define SERIAL_BAUD_115200	(0x00000008)
#define rFFRBR			(*((volatile ulong *)(FFUART_BASE+0x00)))
#define rFFTHR 			(*((volatile ulong *)(FFUART_BASE+0x00)))
#define rFFIER 			(*((volatile ulong *)(FFUART_BASE+0x04)))
#define rFFIIR 			(*((volatile ulong *)(FFUART_BASE+0x08)))
#define rFFFCR 			(*((volatile ulong *)(FFUART_BASE+0x08)))
#define rFFLCR 			(*((volatile ulong *)(FFUART_BASE+0x0C)))
#define rFFMCR 			(*((volatile ulong *)(FFUART_BASE+0x10)))
#define rFFLSR 			(*((volatile ulong *)(FFUART_BASE+0x14)))
#define rFFMSR			(*((volatile ulong *)(FFUART_BASE+0x18)))
#define rFFSPR 			(*((volatile ulong *)(FFUART_BASE+0x1C)))
#define rFFISR 			(*((volatile ulong *)(FFUART_BASE+0x20)))
#define rFFDLL 			(*((volatile ulong *)(FFUART_BASE+0x00)))
#define rFFDLH 			(*((volatile ulong *)(FFUART_BASE+0x04)))


/** General Programmable I/O */

#define GPIO_BASE	0x40E00000

#define GAFR1_L		(*((volatile ulong *)(GPIO_BASE+0x5c)))
#define GPDR1		(*((volatile ulong *)(GPIO_BASE+0x10)))

#define GPIO_REG(_x_)	*(volatile unsigned long *)(GPIO_BASE + _x_)
#define GPIO_GPLR0	0x00	/* GPIO<31: 0>	status register */
#define GPIO_GPLR1	0x04	/* GPIO<63:32>	status register */
#define GPIO_GPLR2	0x08	/* GPIO<80:64>	status register */
#define GPIO_GPDR0	0x0C	/* GPIO<31: 0>	direction register */
#define GPIO_GPDR1	0x10	/* GPIO<63:32>	direction register */
#define GPIO_GPDR2	0x14	/* GPIO<80:64>	direction register */
#define GPIO_GPSR0	0x18	/* GPIO<31: 0>	output set register */
#define GPIO_GPSR1	0x1C	/* GPIO<63:32>	output set register */
#define GPIO_GPSR2	0x20	/* GPIO<80:64>	output set register */
#define GPIO_GPCR0	0x24	/* GPIO<31: 0>	output clear register */
#define GPIO_GPCR1	0x28	/* GPIO<63:32>	output clear register */
#define GPIO_GPCR2	0x2C	/* GPIO<80:64>	output clear register */
#define GPIO_GRER0	0x30	/* GPIO<31: 0>	rising-edge detect register */
#define GPIO_GRER1	0x34	/* GPIO<63:32>  rising-edge detect register */
#define GPIO_GRER2	0x38	/* GPIO<80:64>	rising-edge detect register */
#define GPIO_GFER0	0x3C	/* GPIO<31: 0>	falling-edge detect register */
#define GPIO_GFER1	0x40	/* GPIO<63:32>	falling-edge detect register */
#define GPIO_GFER2	0x44	/* GPIO<80:64>	falling-edge detect register */
#define GPIO_GEDR0	0x48	/* GPIO<31: 0>	edge detect status register */
#define GPIO_GEDR1	0x4C	/* GPIO<63:32>	edge detect status register */
#define GPIO_GEDR2	0x50	/* GPIO<80:64>	edge detect status register */
#define GPIO_GAFR0L	0x54	/* GPIO<15: 0>	alternate function select
				   		register 0 Lower */
#define GPIO_GAFR0U	0x58	/* GPIO<31:16>	alternate function select
				   		register 0 Upper */
#define GPIO_GAFR1L	0x5C	/* GPIO<47:32>	alternate function select
				   		register 1 Lower */
#define GPIO_GAFR1U	0x60	/* GPIO<63:48>	alternate function select
				   		register 1 Upper */
#define GPIO_GAFR2L	0x64	/* GPIO<79:64>	alternate function select
				   		register 2 Lower */
#define GPIO_GAFR2U	0x68	/* GPIO80	alternate function select
				   		register 2 Upper */

#define BIT0		0x00000001
#define BIT1		0x00000002
#define BIT2		0x00000004
#define BIT3		0x00000008
#define BIT4		0x00000010
#define BIT5		0x00000020
#define BIT6		0x00000040
#define BIT7		0x00000080
#define BIT8		0x00000100
#define BIT9		0x00000200
#define BIT10		0x00000400
#define BIT11		0x00000800
#define BIT12		0x00001000
#define BIT13		0x00002000
#define BIT14		0x00004000
#define BIT15		0x00008000
#define BIT16		0x00010000
#define BIT17		0x00020000
#define BIT18		0x00040000
#define BIT19		0x00080000
#define BIT20		0x00100000
#define BIT21		0x00200000
#define BIT22		0x00400000
#define BIT23		0x00800000
#define BIT24		0x01000000
#define BIT25		0x02000000
#define BIT26		0x04000000
#define BIT27		0x08000000
#define BIT28		0x10000000
#define BIT29		0x20000000
#define BIT30		0x40000000
#define BIT31		0x80000000

#define GPIO_0		BIT0
#define GPIO_1		BIT1
#define GPIO_2		BIT2
#define GPIO_3		BIT3
#define GPIO_4		BIT4
#define GPIO_5		BIT5
#define GPIO_6		BIT6
#define GPIO_7		BIT7
#define GPIO_8		BIT8
#define GPIO_9		BIT9
#define GPIO_10		BIT10
#define GPIO_11		BIT11
#define GPIO_12		BIT12
#define GPIO_13		BIT13
#define GPIO_14		BIT14
#define GPIO_15		BIT15
#define GPIO_16		BIT16
#define GPIO_17		BIT17
#define GPIO_18		BIT18
#define GPIO_19		BIT19
#define GPIO_20		BIT20
#define GPIO_21		BIT21
#define GPIO_22		BIT22
#define GPIO_23		BIT23
#define GPIO_24		BIT24
#define GPIO_25		BIT25
#define GPIO_26		BIT26
#define GPIO_27		BIT27
#define GPIO_28		BIT28
#define GPIO_29		BIT29
#define GPIO_30		BIT30
#define GPIO_31		BIT31
/* GPLR1, GPDR1, GPSR1, GPCR1, GPRE1, GPFE1, GPED1 */
#define GPIO_32		BIT0
#define GPIO_33		BIT1
#define GPIO_34		BIT2
#define GPIO_35		BIT3
#define GPIO_36		BIT4
#define GPIO_37		BIT5
#define GPIO_38		BIT6
#define GPIO_39		BIT7
#define GPIO_40		BIT8
#define GPIO_41		BIT9
#define GPIO_42		BIT10
#define GPIO_43		BIT11
#define GPIO_44		BIT12
#define GPIO_45		BIT13
#define GPIO_46		BIT14
#define GPIO_47		BIT15
#define GPIO_48		BIT16
#define GPIO_49		BIT17
#define GPIO_50		BIT18
#define GPIO_51		BIT19
#define GPIO_52		BIT20
#define GPIO_53		BIT21
#define GPIO_54		BIT22
#define GPIO_55		BIT23
#define GPIO_56		BIT24
#define GPIO_57		BIT25
#define GPIO_58		BIT26
#define GPIO_59		BIT27
#define GPIO_60		BIT28
#define GPIO_61		BIT29
#define GPIO_62		BIT30
#define GPIO_63		BIT31
/* GPLR2, GPDR2, GPSR2, GPCR2, GPRE2, GPFE2, GPED2 */
#define GPIO_64		BIT0
#define GPIO_65		BIT1
#define GPIO_66		BIT2
#define GPIO_67		BIT3
#define GPIO_68		BIT4
#define GPIO_69		BIT5
#define GPIO_70		BIT6
#define GPIO_71		BIT7
#define GPIO_72		BIT8
#define GPIO_73		BIT9
#define GPIO_74		BIT10
#define GPIO_75		BIT11
#define GPIO_76		BIT12
#define GPIO_77		BIT13
#define GPIO_78		BIT14
#define GPIO_79		BIT15
#define GPIO_80		BIT16
/* appendix: pxa255-pro3 */
#define GPIO_81		BIT17
#define GPIO_84		BIT20

#define AF0		0x0
#define AF1		0x1
#define AF2		0x2
#define AF3		0x3
                         

/* GPAFR0_L */
#define GPIO_0_AF		(AF0 << 0)
#define GPIO_1_AF_RST		(AF1 << 2)	/* Set GPDR0, bit GPIO_1 = 0 */
#define GPIO_2_AF		(AF0 << 4)
#define GPIO_3_AF		(AF0 << 6)
#define GPIO_4_AF		(AF0 << 8)
#define GPIO_5_AF		(AF0 << 10)
#define GPIO_6_AF_MMC_CLK	(AF1 << 12)	/* Set GPDR0, bit GPIO_6 = 1 */
#define GPIO_7_AF_48MHZ		(AF1 << 14)	/* Set GPDR0, bit GPIO_7 = 1 */
#define GPIO_8_AF_MMC_CS0	(AF1 << 16)	/* Set GPDR0, bit GPIO_8 = 1 */
#define GPIO_9_AF_MMC_CS1	(AF1 << 18)	/* Set GPDR0, bit GPIO_9 = 1 */
#define GPIO_10_AF_RTC_CLK	(AF1 << 20)	/* Set GPDR0, bit GPIO_10 = 1 */
#define GPIO_11_AF_3_68MHZ	(AF1 << 22)	/* Set GPDR0, bit GPIO_11 = 1 */
#define GPIO_12_AF_32KHZ	(AF1 << 24)	/* Set GPDR0, bit GPIO_12 = 1 */
#define GPIO_13_AF_MBGNT	(AF2 << 26)	/* Set GPDR0, bit GPIO_13 = 1 */
#define GPIO_14_AF_MBREQ	(AF1 << 28)	/* Set GPDR0, bit GPIO_14 = 0 */
#define GPIO_15_AF_CS1		(AF2 << 30)	/* Set GPDR0, bit GPIO_15 = 1 */

/* GPAFR0_U */
#define GPIO_16_AF_PWM0		(AF2 << 0)	/* Set GPDR0, bit GPIO_16 = 1 */
#define GPIO_17_AF_PWM1		(AF2 << 2)	/* Set GPDR0, bit GPIO_17 = 1 */
#define GPIO_18_AF_RDY		(AF1 << 4)	/* Set GPDR0, bit GPIO_18 = 0 */
#define GPIO_19_AF_DREQ1	(AF1 << 6)	/* Set GPDR0, bit GPIO_19 = 0 */
#define GPIO_20_AF_DREQ0	(AF1 << 8)	/* Set GPDR0, bit GPIO_20 = 0 */
#define GPIO_21_AF		(AF0 << 10)
#define GPIO_22_AF		(AF0 << 12)
#define GPIO_23_AF_SSP_CLK	(AF2 << 14)	/* Set GPDR0, bit GPIO_23 = 1 */
#define GPIO_24_AF_SSP_FRM	(AF2 << 16)	/* Set GPDR0, bit GPIO_24 = 1 */
#define GPIO_25_AF_SSP_TXD	(AF2 << 18)	/* Set GPDR0, bit GPIO_25 = 1 */
#define GPIO_26_AF_SSP_RXD	(AF1 << 20)	/* Set GPDR0, bit GPIO_26 = 0 */
#define GPIO_27_AF_SSP_EXTCLK	(AF1 << 22)	/* Set GPDR0, bit GPIO_27 = 0 */
#define GPIO_28_AF_AC97_BCLK_IN	(AF1 << 24)	/* When GPDR0, bit GPIO_28 = 0 */
#define GPIO_28_AF_I2S_BCLK_IN	(AF2 << 24)	/* When GPDR0, bit GPIO_28 = 0 */
#define GPIO_28_AF_I2S_BCLK_OUT	(AF1 << 24)	/* When GPDR0, bit GPIO_28 = 1 */
#define GPIO_28_AF_AC97_BCLK_OUT  (AF2 << 24)	/* When GPDR0, bit GPIO_28 = 1 */
#define GPIO_29_AF_AC97_SDIN0	(AF1 << 26)	/* Set GPDR0, bit GPIO_29 = 0 */
#define GPIO_29_AF_I2S_SDIN	(AF2 << 26)	/* Set GPDR0, bit GPIO_29 = 0 */
#define GPIO_30_AF_I2S_SDOUT	(AF1 << 28)	/* Set GPDR0, bit GPIO_30 = 1 */
#define GPIO_30_AF_AC97_SDOUT	(AF2 << 28)	/* Set GPDR0, bit GPIO_30 = 1 */
#define GPIO_31_AF_I2S_SYNC	(AF1 << 30)	/* Set GPDR0, bit GPIO_31 = 1 */
#define GPIO_31_AF_AC97_SYNC	(AF2 << 30)	/* Set GPDR0, bit GPIO_31 = 1 */

/* GPAFR1_L */
#define GPIO_32_AF_AC97_SDIN1	(AF1 << 0)	/* When GPDR1, BIT GPIO_32 = 0 */
#define GPIO_32_AF_I2S_SYSCLK	(AF1 << 0)	/* When GPDR1, BIT GPIO_32 = 1 */
#define GPIO_33_AF_CS5		(AF2 << 2)	/* Set GPDR1, BIT GPIO_33 = 1 */
#define GPIO_34_AF_FF_RXD	(AF1 << 4)	/* Set GPDR1, BIT GPIO_34 = 0 */
#define GPIO_34_AF_MMC_CS0	(AF2 << 4)	/* Set GPDR1, BIT GPIO_34 = 1 */
#define GPIO_35_AF_FF_CTS	(AF1 << 6)	/* Set GPDR1, BIT GPIO_35 = 0 */
#define GPIO_36_AF_FF_DCD	(AF1 << 8)	/* Set GPDR1, BIT GPIO_36 = 0 */
#define GPIO_37_AF_FF_DSR	(AF1 << 10)	/* Set GPDR1, BIT GPIO_37 = 0 */
#define GPIO_38_AF_FF_RI	(AF1 << 12)	/* Set GPDR1, BIT GPIO_38 = 0 */
#define GPIO_39_AF_MM_CS1	(AF1 << 14)	/* Set GPDR1, BIT GPIO_39 = 1 */
#define GPIO_39_AF_FF_TXD	(AF2 << 14)	/* Set GPDR1, BIT GPIO_39 = 1 */
#define GPIO_40_AF_FF_DTR	(AF2 << 16)	/* Set GPDR1, BIT GPIO_40 = 1 */
#define GPIO_41_AF_FF_RTS	(AF2 << 18)	/* Set GPDR1, BIT GPIO_41 = 1 */
#define GPIO_42_AF_BT_RXD	(AF1 << 20)	/* Set GPDR1, BIT GPIO_42 = 0 */
#define GPIO_43_AF_BT_TXD	(AF2 << 22)	/* Set GPDR1, BIT GPIO_43 = 1 */
#define GPIO_44_AF_BT_CTS	(AF1 << 24)	/* Set GPDR1, BIT GPIO_44 = 0 */
#define GPIO_45_AF_BT_RTS	(AF2 << 26)	/* Set GPDR1, BIT GPIO_45 = 1 */
#define GPIO_46_AF_IR_RXD	(AF1 << 28)	/* Set GPDR1, BIT GPIO_46 = 0 */
#define GPIO_46_AF_STD_RXD	(AF2 << 28)	/* Set GPDR1, BIT GPIO_46 = 0 */
#define GPIO_47_AF_IR_TXD	(AF1 << 30)	/* Set GPDR1, BIT GPIO_47 = 1 */
#define GPIO_47_AF_STD_TXD	(AF2 << 30)	/* Set GPDR1, BIT GPIO_47 = 1 */

/* GPAFR1_U */
#define GPIO_48_AF_POE		(AF2 << 0)	/* Set GPDR1, BIT GPIO_48 = 1 */
#define GPIO_49_AF_PWE		(AF2 << 2)	/* Set GPDR1, BIT GPIO_49 = 1 */
#define GPIO_50_AF_PIOR		(AF2 << 4)	/* Set GPDR1, BIT GPIO_50 = 1 */
#define GPIO_51_AF_PIOW		(AF2 << 6)	/* Set GPDR1, BIT GPIO_51 = 1 */
#define GPIO_52_AF_PCE1		(AF2 << 8)	/* Set GPDR1, BIT GPIO_52 = 1 */
#define GPIO_53_AF_MMC_CLK	(AF1 << 10)	/* Set GPDR1, BIT GPIO_53 = 1 */
#define GPIO_53_AF_PCE2		(AF2 << 10)	/* Set GPDR1, BIT GPIO_53 = 1 */
#define GPIO_54_AF_MMC_CLK	(AF1 << 12)	/* Set GPDR1, BIT GPIO_54 = 1 */
#define GPIO_54_AF_PSKTSEL	(AF2 << 12)	/* Set GPDR1, BIT GPIO_54 = 1 */
#define GPIO_55_AF_PREG		(AF2 << 14)	/* Set GPDR1, BIT GPIO_55 = 1 */
#define GPIO_56_AF_PWAIT	(AF1 << 16)	/* Set GPDR1, BIT GPIO_56 = 0 */
#define GPIO_57_AF_IOIS16	(AF1 << 18)	/* Set GPDR1, BIT GPIO_57 = 0 */
#define GPIO_58_AF_LDD0		(AF2 << 20)	/* Set GPDR1, BIT GPIO_58 = 1 */
#define GPIO_59_AF_LDD1		(AF2 << 22)	/* Set GPDR1, BIT GPIO_59 = 1 */
#define GPIO_60_AF_LDD2		(AF2 << 24)	/* Set GPDR1, BIT GPIO_60 = 1 */
#define GPIO_61_AF_LDD3		(AF2 << 26)	/* Set GPDR1, BIT GPIO_61 = 1 */
#define GPIO_62_AF_LDD4		(AF2 << 28)	/* Set GPDR1, BIT GPIO_62 = 1 */
#define GPIO_63_AF_LDD5		(AF2 << 30)	/* Set GPDR1, BIT GPIO_63 = 1 */

/* GPAFR2_L */
#define GPIO_64_AF_LDD6		(AF2 << 0)	/* Set GPDR1, BIT GPIO_64 = 1 */
#define GPIO_65_AF_LDD7		(AF2 << 2)	/* Set GPDR1, BIT GPIO_65 = 1 */
#define GPIO_66_AF_MBREQ	(AF1 << 4)	/* Set GPDR1, BIT GPIO_66 = 0 */
#define GPIO_66_AF_LDD8		(AF2 << 4)	/* Set GPDR1, BIT GPIO_66 = 1 */
#define GPIO_67_AF_MMC_CS0	(AF1 << 6)	/* Set GPDR1, BIT GPIO_67 = 1 */
#define GPIO_67_AF_LDD9		(AF2 << 6)	/* Set GPDR1, BIT GPIO_67 = 1 */
#define GPIO_68_AF_MMC_CS1	(AF1 << 8)	/* Set GPDR1, BIT GPIO_68 = 1 */
#define GPIO_68_AF_LDD10	(AF2 << 8)	/* Set GPDR1, BIT GPIO_68 = 1 */
#define GPIO_69_AF_MMC_CLK	(AF1 << 10)	/* Set GPDR1, BIT GPIO_69 = 1 */
#define GPIO_69_AF_LDD11	(AF2 << 10)	/* Set GPDR1, BIT GPIO_69 = 1 */
#define GPIO_70_AF_RTC_CLK	(AF1 << 12)	/* Set GPDR1, BIT GPIO_70 = 1 */
#define GPIO_70_AF_LDD12	(AF2 << 12)	/* Set GPDR1, BIT GPIO_70 = 1 */
#define GPIO_71_AF_3_68MHZ	(AF1 << 14)	/* Set GPDR1, BIT GPIO_71 = 1 */
#define GPIO_71_AF_LDD13	(AF2 << 14)	/* Set GPDR1, BIT GPIO_71 = 1 */
#define GPIO_72_AF_32KHZ	(AF1 << 16)	/* Set GPDR1, BIT GPIO_72 = 1 */
#define GPIO_72_AF_LDD14	(AF2 << 16)	/* Set GPDR1, BIT GPIO_72 = 1 */
#define GPIO_73_AF_MBGNT	(AF1 << 18)	/* Set GPDR1, BIT GPIO_73 = 1 */
#define GPIO_73_AF_LDD15	(AF2 << 18)	/* Set GPDR1, BIT GPIO_73 = 1 */
#define GPIO_74_AF_LCD_FCLK	(AF2 << 20)	/* Set GPDR1, BIT GPIO_74 = 1 */
#define GPIO_75_AF_LCD_LCLK	(AF2 << 22)	/* Set GPDR1, BIT GPIO_75 = 1 */
#define GPIO_76_AF_LCD_PCLK	(AF2 << 24)	/* Set GPDR1, BIT GPIO_76 = 1 */
#define GPIO_77_AF_LCD_BIAS	(AF2 << 26)	/* Set GPDR1, BIT GPIO_77 = 1 */
#define GPIO_78_AF_CS2		(AF2 << 28)	/* Set GPDR1, BIT GPIO_78 = 1 */
#define GPIO_79_AF_CS3		(AF2 << 30)	/* Set GPDR1, BIT GPIO_79 = 1 */

/* GPAFR2_U */
#define GPIO_80_AF_CS4		(AF2 << 0)	/* Set GPDR1, BIT GPIO_80 = 1 */

/** Power management */
#define RCSR			0x40F00030	/* Reset Controller Status
						   register */
#define RCSR_SLEEP		0x00000004	/* Power Manager Sleep Configuration
						   register */
#define PSPR			0x40F00008	/* Power Manager Scratch-Pad
						   register */ 
#define PSSR			0x40F00004	/* Power Manager Sleep Status
						   register */
#define PSSR_PH			0x00000010
#define PSSR_RDH		0x00000020
#define PSSR_STATUS_MASK	0x00000007

