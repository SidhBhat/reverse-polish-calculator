#include<stdio.h>
#include"getch1.01.h"

static unsigned short buf_pos = 0;
static int buf[BUFFSIZE];
static short flag = 0;

#define FAIL 1

/* get characters from buffer or stdin if buffer is empty */
int getch(void)
{
	if(flag)
		return EOF;
	if(buf_pos > 0) {
		if(buf[--buf_pos] == EOF)
			flag = FAIL;
		return buf[buf_pos];
	}
	return getchar();
}

/* put characters into buffer */
int ungetch(int ch)
{
	if(buf_pos >= BUFFSIZE)
		buf_pos = 0;
	buf[buf_pos++] = ch;
	return ch;
}

// clearerrgetch : clear fail state if getch
void clearerrgetch(void)
{
	flag = 0;
}
