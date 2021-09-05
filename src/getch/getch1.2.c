#include<stdio.h>
#include"getch1.2.h"

static int buf = 0;

/* get characters from buffer or stdin if buffer is empty */
int getch(void)
{
	if(buf) {
		int tmp = buf;
		return buf = 0,tmp;
	}
	else
		return getchar();

}

/* put characters into buffer */
int ungetch(int ch)
{
	if(buf == 0)
		return buf = ch;
	return buf;
}
