#ifndef CURT_MACH_PXA255_PORT_H
#define CURT_MACH_PXA255_PORT_H

#include "arch/arm/mach-pxa/pxa255.h"
#include "kernel/types.h"
#include "kernel/thread.h"

#define PXA255_TMR_CLK 3686400
#define OS_TICKS_PER_SEC 10

stk_t *init_thread_stack(THREAD_FUNC func,
                         void *pdata,
                         stk_t *stk_top_ptr);

void init_os_timer();

void interrupt_handler();

void init_interrupt_control();

/* context switching routines : architecture implementations */
extern void restore_context();
extern void context_switch();
extern int context_switch_in_interrupt();
extern cpu_sr_t save_cpu_sr();
extern void restore_cpu_sr();

#endif /* ! CURT_MACH_PXA255_PORT_H */

