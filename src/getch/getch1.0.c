#include<stdio.h>
#include"getch1.0.h"

static unsigned short buf_pos = 0;
static char buf[BUFFSIZE];

/* get characters from buffer or stdin if buffer is empty */
int getch(void)
{
	return (buf_pos > 0) ? buf[--buf_pos] : getchar();
}

/* put characters into buffer */
void ungetch(char ch)
{
	if(buf_pos >= BUFFSIZE)
		buf_pos = 0;
	buf[buf_pos++] = ch;
}
