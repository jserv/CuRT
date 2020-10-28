/*
 * thread.h
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

#ifndef CURT_THREAD_H
#define CURT_THREAD_H

/*! \file thread.h
 *  \brief Thread definitions and routines for CuRT
 */

#include "kernel/types.h"
#include "kernel/list.h"

/** @brief state of threads
 */
typedef enum {
	READY, 
	RUNNING, 
	EVENT_WAIT, 
	BLOCK, 
	DELAY, 
	TERMINATE 
} THREAD_STATE;

typedef void (*THREAD_FUNC)(void *data);
 
/** @brief structure of one thread
 */
typedef struct {
	list_node_t node;
	stk_t *stack_ptr;
	tid_t tid;
	char *name;
	THREAD_STATE state;
	u8_t prio;
	u32_t time_quantum;
	u32_t delayed_time;
	void *msg;
} thread_struct;

/** @brief Create a new thread.
 */
tid_t thread_create(thread_struct *pthread, 
		    stk_t *thread_stk,
		    THREAD_FUNC func, 
		    char *name, 
		    u8_t prio, 
		    void *pdata);

err_t thread_delete(tid_t tid);

void thread_yield();

err_t thread_delay(u32_t tick);

err_t thread_suspend(tid_t tid);

err_t thread_resume(tid_t tid);

#endif /* !CURT_THREAD_H */

