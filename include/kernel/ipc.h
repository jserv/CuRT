/*
 * ipc.h
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

#ifndef CURT_IPC_H
#define CURT_IPC_H

/*! \file ipc.h
 *  \brief IPC routines for CuRT
 */

#include "kernel/list.h"

typedef struct {
	void *msg;
	list_t wait_list;
} mbox_struct;

err_t mbox_init(mbox_struct *mbox, void *pmsg);

void *mbox_recv(mbox_struct *mbox);

void *mbox_try_recv(mbox_struct *mbox);

err_t mbox_send(mbox_struct *mbox, void *pmsg);

typedef struct {
	list_t msg_list;
	list_t wait_list;
} msgq_struct;

typedef struct {
	list_node_t node;
	void *msg;
} msg_struct;

err_t msgq_init(msgq_struct *msgq);

void *msgq_recv(msgq_struct *msgq);

void *msgq_try_recv(msgq_struct *msgq);

err_t msgq_send(msgq_struct *msgq, msg_struct *msg);

#endif /* !CURT_IPC_H */
