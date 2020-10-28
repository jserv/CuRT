/*
 * list.h
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

#ifndef CURT_LIST_H
#define CURT_LIST_H

/*! \file list.h
 *  \brief Generic linked-list.
 */

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "types.h"

typedef struct list_node {
	struct list_node *next, *prev;
} list_node_t;

typedef struct list_t {
	list_node_t head;
	list_node_t tail;
} list_t;

#define entry_list(LIST_NODE, STRUCT, MEMBER) \
  ((STRUCT *) ((u8_t *) &(LIST_NODE)->next    \
	       - offsetof (STRUCT, MEMBER.next)))

void init_list(list_t *plist);

list_node_t *begin_list(list_t *plist);
list_node_t *next_list(list_node_t *pnode);
list_node_t *end_list(list_t *plist);

list_node_t *head_list(list_t *plist);
list_node_t *tail_list(list_t *plist);

void insert_before_list(list_node_t *after, list_node_t *pnode);
void insert_after_list(list_node_t *before, list_node_t *pnode);
void insert_front_list(list_t *plist, list_node_t *pnode);
void insert_back_list(list_t *plist, list_node_t *pnode);

list_node_t *delete_list(list_node_t *pnode);
list_node_t *delete_front_list(list_t *plist);
list_node_t *delete_back_list(list_t *plist);

bool is_empty_list(list_t *plist);


#endif /* !CURT_LIST_H */
