/*
 * stdio.c
 */

#include "lib/stdio.h"

extern void SerialOutputByte(const char);
extern int SerialIsReadyChar( void );
extern char SerialIsGetChar( void );

/* internal helper functions */
static void _PrintChar(char *fmt, char c);
static void _PrintDec(char *fmt, int value);
static void _PrintHex(char *fmt, int value);
static void _PrintString(char *fmt, char *cptr);

void *memcpy(void *dest, const void *src, int cnt)
{
	char *s1 = dest;
	const char *s2 = src;
	char *endptr = (char *) dest + cnt;
	
	while (s1 < endptr)
		*s1++ = *s2++;
	return dest;
}

void *memset(void *dest, int c, int len)
{
	char *s = dest;
	char *limit = (char *) dest + len;

	while (s < limit)
		*s++ = c;
	return dest;
}

int strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s1 == *s2) {
		s1++;
		s2++;
	}
	return (*(unsigned char *) s1) - (*(unsigned char *) s2);
}

static bool DecToLong(char *s, long *retval)
{
	long remainder;
	if (!s || !s[0])
		return false;

	for (*retval = 0; *s; s++) {
		if (*s < '0' || *s > '9')
			return false;
		remainder = *s - '0';
		*retval = *retval * 10 + remainder;
	}

	return true;
}

/**
 * @brief printf() family produce output according to a format
 * The simple implementation in CuRT supports the following format:
 *   "%s", "%c", "%d", and "%x"
 * and the correspoding variants: "%08x", "%8x".
 */
int printf(const char *fmt, ...)
{
	int i;
	va_list args;
	const char *s = fmt;
	char format[10];
	
	va_start(args, fmt);
	while (*s) {
		if (*s == '%') {
			s++;
			/* s in "% 08lx" format to get the record format. */
			format[0] = '%';
			for (i = 1; i < 10; ) {
				if (*s=='c' || *s=='d' || *s=='x' ||
				    *s=='s' || *s=='%') {
					format[i++] = *s;
					format[i] = '\0';
					break;
				}
				else {
					format[i++] = *s++;
				}
			}
			/* "% s", "% c", "% d", "% x" to find the print
			 * function calls */
			switch (*s++) {
				case 'c' :
					_PrintChar(format, va_arg(args, int));
					break;
				case 'd' :
					_PrintDec(format, va_arg(args, int));
					break;
				case 'x' :
					_PrintHex(format, va_arg(args, int));
					break;
				case 's' :
					_PrintString(format, va_arg(args, char *));
					break;
				case '%' :
					_PrintChar("%c", '%');
					break;
				default:
					/* it shall not happend. */
					break;
			}
		}
		else {
			_PrintChar("%c", *s);
			s++;
		}
	}
	va_end(args);

	/* FIXME: Upon successful return, printf function shall return the
	 * number of characters printed.
	 */
	return 1;
}


static void _PrintChar(char *fmt, char c)
{
	SerialOutputByte(c);
	return;
}

static void _PrintDec(char *fmt, int l)
{
	char tol[10];
	int remainder;
	int count = 0;
	if (l == 0) {
		SerialOutputByte('0');
		return;
	}
	if (l < 0) {
		SerialOutputByte('-');
		l = -l;
	}
	/* FIXME: we don't intend to handle the number bigger than 100000. */
	if (l > 100000)
		return;

	for ( ; count < 10; count++)
		tol[count] = '\0';
	count = 7;
	do {
		remainder = l % 10;
		tol[count--] = '0' + remainder;
		l = (l - remainder) / 10;
	} while (count > 0);
	tol[0] = ' ';

	_PrintString(fmt, tol);
}

static void _PrintHex(char *fmt, int l)
{
	int i, j;
	char c, *s = fmt, tol[10];
	bool flag0 = false;
	long flagcnt = 0;
	bool leading_zero = true;
	char uHex, lHex;

	/* note: the format like "% 5x" only prints the number of 5. */

	/* format like "%081" is interpreted for '0', '8', 'l'
	 * individually. */
	for (i = 0; (c = s[i]) != 0; i++) {
		if (c == 'x')
			break;
		else if (c >= '1' && c <= '9') {
			for (j = 0; s[i] >= '0' && s[i] <= '9'; j++) {
				tol[j] = s[i++];
			}
			tol[j] = '\0';
			i--;
			DecToLong(tol, &flagcnt);
		}
		else if (c == '0')
			flag0 = true;
		else
			continue;
	}

	s = (char *)(&l);
	l = SWAP32(l);	/* depends on the endianess. */
	
	/* output, based on the flag */
	if (flagcnt) {
		if (flagcnt & 0x01) {	/* upper ignored, lower the output. */
			c = s[(8 - (flagcnt + 1)) / 2];
			
			/* check if lower 4 bits becomes ASCII code. */
			lHex = ((c >> 0) & 0x0f);
			if (lHex != 0)
				leading_zero = false;
			if (lHex < 10)
				lHex += '0';
			else         lHex += 'A' - 10;

			/* lower 4 bits */
			if (leading_zero) {
				if (flag0)
					SerialOutputByte('0');
				else
					SerialOutputByte(' ');
			}
			else SerialOutputByte(lHex);
			
			flagcnt--;
		}

		/* byte-level data, the output Hex */
		for (i = (8 - flagcnt) / 2; i < 4; i++) {
			c = s[i];
				
			/* get upper 4 bits and lower 4 bits. */
			uHex = ((c >> 4) & 0x0f);
			lHex = ((c >> 0) & 0x0f);

			/* upper 4 bits and lower 4 bits to '0'~'9', 'A'~'F'.
			   upper 4 bits: ascii code */
			if (uHex != 0)
				leading_zero = false;
			if (uHex < 10)
				uHex += '0';
			else
				uHex += 'A' - 10;

			/* upper 4 bits */
			if (leading_zero) {
				if (flag0)
					SerialOutputByte('0');
				else
					SerialOutputByte(' ');
			}
			else SerialOutputByte(uHex);
			
			/* lower 4 bits: ascii code */
			if (lHex != 0)
				leading_zero = false;
			if (lHex < 10)
				lHex += '0';
			else
				lHex += 'A' - 10;

			/* lower 4 bits */
			if (leading_zero) {
				if (flag0)
					SerialOutputByte('0');
				else
					SerialOutputByte(' ');
			}
			else
				SerialOutputByte(lHex);
		}
	}
	else {
		for (i = 0; i < 4; i++){
			c = s[i];
	
			/* get upper 4 bits and lower 4 bits. */
			uHex = ((c >> 4) & 0x0f);
			lHex = ((c >> 0) & 0x0f);

			/* upper 4 bits and lower 4 bits to '0'~'9', 'A'~'F'. */
			if (uHex != 0)
				leading_zero = false;
			if (uHex < 10)
				uHex += '0';
			else
				uHex += 'A' - 10;
			if (!leading_zero)
				SerialOutputByte(uHex);
			
			if (lHex != 0 || i == 3)
				leading_zero = false;
			if (lHex < 10)
				lHex += '0';
			else
				lHex += 'A' - 10;
			if (!leading_zero)
				SerialOutputByte(lHex);
		}
	}
	return;
}

static void _PrintString(char *fmt, char *s)
{
	if (!fmt || !s)
		return;
	while (*s)
		SerialOutputByte(*s++);
	return;
}

int getc(void)
{               
	while (!SerialIsReadyChar())
		/* Keep waiting */ ;
	return SerialIsGetChar() & 0xFF;
}

int gets(char *s)
{
	int cnt = 0;
	char  c;

	while ((c = getc()) != CR) {
		if (c != BS) {
			cnt++;
			*s++ = c;
			printf("%c",c );
		}
		else {
			if (cnt > 0) {
				cnt--;
				*s-- = ' ';
				printf("\b \b");
			}
		}
	}
	*s = 0;
	return cnt;
}

int putchar(int c)
{
	SerialOutputByte(c);
	return c;
}

int puts(const char *s)
{
	while (*s)
		SerialOutputByte(*s++);
	return 1;
}

static char * ___strtok;
char * strtok(char * s,const char * ct)
{
	char *sbegin, *send;

	sbegin  = s ? s : ___strtok;
	if (!sbegin) {
		return NULL;
	}
	sbegin += strspn(sbegin, ct);
	if (*sbegin == '\0') {
		___strtok = NULL;
		return( NULL );
	}
	send = strpbrk(sbegin, ct);
	if (send && *send != '\0')
		*send++ = '\0';
	___strtok = send;
	return (sbegin);
}

unsigned int strspn(const char *s, const char *accept)
{
	const char *p;
	const char *a;
	unsigned int count = 0;
	
	for (p = s; *p != '\0'; ++p) {
		for (a = accept; *a != '\0'; ++a) {
			if (*p == *a)
				break;
		}
		if (*a == '\0')
			return count;
		++count;
	}
	return count;
}

char * strpbrk(const char * cs,const char * ct)
{
	const char *sc1, *sc2;

	for (sc1 = cs; *sc1 != '\0'; ++sc1) {
		for (sc2 = ct; *sc2 != '\0'; ++sc2) {
			if (*sc1 == *sc2)
				return (char *) sc1;
		}
	}
	return NULL;
}

unsigned long strtoul(const char *str, char **endptr, int requestedbase)
{
	unsigned long num = 0;
	char c;
	unsigned char digit;
	int base = 10;
	int nchars = 0;
	int leadingZero = 0;
	
	while ((c = *str) != 0) {
		if (nchars == 0 && c == '0') {
			leadingZero = 1;
			goto step;
		}
		else if (leadingZero && nchars == 1) {
			if (c == 'x') {
				base = 16;
				goto step;
			}
			else if (c == 'o') {
				base = 8;
				goto step;
			}
		}
		if (c >= '0' && c <= '9') {
			digit = c - '0';
		}
		else if (c >= 'a' && c <= 'z') {
			digit = c - 'a' + 10;
		}
		else if (c >= 'A' && c <= 'Z') {
			digit = c - 'A' + 10;
		}
		else {
			return 0;
		}
		if (digit >= base) {
			return 0;
		}
		num *= base;
		num += digit;
step:
		str++;
		nchars++;
	}
	return num;
}

