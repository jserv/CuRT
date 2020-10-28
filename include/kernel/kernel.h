/*
 * kernel.h
 *
 * Copyright (c) 2009 Jim Huang <jserv.tw@gmail.com>
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that copyright
 * notice and this permission notice appear in supporting documentation, and
 * that the name of the copyright holders not be used in advertising or
 * publicity pertaining to distribution of the software without specific,                  
 * written prior permission.  The copyright holders make no representations
 * about the suitability of this software for any purpose.  It is provided "as
 * is" without express or implied warranty.
 *
 * THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
 * EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
 * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
 * OF THIS SOFTWARE.
 */

#ifndef CURT_KERNEL_H
#define CURT_KERNEL_H

/*! \file kernel.h
 *  \brief CuRT core APIs
 */

#include "kernel/list.h"
#include "kernel/thread.h"

#define TASK_STACK_SIZE 8192
#define THREAD_STACK_SIZE 8192
#define TIME_QUANTUM 10
#define MAX_PRIO 32
#define MAX_THREAD 100
#define IDLE_THREAD_TID 0

typedef enum {
	SCHED_TIME_EXPIRE,
	SCHED_THREAD_REQUEST
} SCHED_TYPE;

extern list_t ready_list[MAX_PRIO];
extern list_t termination_wait_list;
extern list_t delayed_list;
extern list_t blocked_list;

extern thread_struct *current_thread;
extern thread_struct *next_thread;

extern int os_time_tick;
extern int total_thread_cnt;
extern int total_csw_cnt;

extern int current_top_prio;
extern bool prio_exist_flag[MAX_PRIO];
extern bool is_start_os;
extern thread_struct *idle_thread_handle;
extern thread_struct *thread_table[MAX_THREAD];

tid_t get_tid();

u8_t get_top_prio();

void advance_time_tick();

void init_curt();

void start_curt();

void schedule(SCHED_TYPE sched_type);

void enter_interrupt();
void exit_interrupt();

void idle_thread_func(void *data);

#endif /* !CURT_KERNEL_H */
