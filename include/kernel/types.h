/*
 * type.h
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

#ifndef _TYPES_H_
#define _TYPES_H_

/*! \file types.h
 *  \brief Essential type definitions for CuRT
 */

#define bool _Bool
#define true  1
#define false 0

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

#ifndef NULL
#define NULL ((void *)0)
#endif

#define RET_NO_ERR 0
#define RET_ERR   -1

typedef unsigned char   u8_t;
typedef signed   char   s8_t;
typedef unsigned short  u16_t;
typedef signed   short  s16_t;
typedef unsigned long   u32_t;
typedef signed   long   s32_t;

typedef int* stk_t;
typedef int err_t;
typedef int cpu_sr_t;
typedef int tid_t;
typedef unsigned long	ulong;
typedef unsigned short	ushort;
typedef unsigned char	uchar;
typedef unsigned int	uint;

typedef enum {
	VAR_LONG = 32,
	VAR_SHORT = 16,
	VAR_CHAR = 8
} VAR_TYPE;

typedef char *va_list;
#define va_start(ap, p)		(ap = (char *) (&(p)+1))
#define va_arg(ap, type)	((type *) (ap += sizeof(type)))[-1]
#define va_end(ap)

#endif
