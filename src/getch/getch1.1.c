#include<stdio.h>
#include"getch1.1.h"

static unsigned short buf_pos = 0;
static int buf[BUFFSIZE];

/* get characters from buffer or stdin if buffer is empty */
int getch(void)
{
	return (buf_pos > 0) ? buf[--buf_pos] : getchar();
}

/* put characters into buffer */
int ungetch(int ch)
{
	if(buf_pos >= BUFFSIZE)
		buf_pos = 0;
	buf[buf_pos++] = ch;
	return ch;
}

/* put a whole string into buffer */
void ungetstr(char const *const s)
{
	int i = 0;

	while(s[i] != '\0')
		i++;
	while(i > 0)
		ungetch(s[--i]);
}
/* if the string is greater then buffer size then only a segment from the beginning is phrased into buff.
 */
