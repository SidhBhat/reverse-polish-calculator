#include<stdio.h>
#include<ctype.h>
#include"getch.h"

#define NUMBER '0'

// getop: function to recognise operators and numbers ,writing number to to string
int getop(char *const str)
{
	int i = 0, ch;

	while((str[0] = ch = getch()) == ' ' || ch == '\t')
		;
	str[1] = '\0';
	if(!isdigit(ch) && ch != '.')
		return ch;
	if(isdigit(ch))
		while(isdigit(str[++i] = ch = getch()))
			;
	if(ch == '.')
		while(isdigit(str[++i] = ch = getch()))
			;
	str[i] = '\0';
	if(ch != EOF)
		ungetch(ch);
	return NUMBER;

}
