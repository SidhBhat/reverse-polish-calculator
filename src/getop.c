#include<stdio.h>
#include<ctype.h>
#include"getch.h"
#include"revrse_polish_calc.h"

// getop: function to recognise operators and numbers ,writing number to to string
int getop(char *const str)
{
	int i = 0, ch;

	while((str[0] = ch = getch()) == ' ' || ch == '\t')
		;
	str[1] = '\0';
	if(!isdigit(ch) && ch != '.' && ch != '-')
		return ch;
	if(ch == '-')
		if(!isdigit(str[++i] = ch = getch()) && ch != '.') {
			ungetch(ch);
			str[i] = '\0';
			return '-';
		}
	if(isdigit(ch))
		while(isdigit(str[++i] = ch = getch()))
			;
	if(ch == '.')
		while(isdigit(str[++i] = ch = getch()))
			;
	if(ch == 'e' || ch == 'E') {
		if(isdigit(str[++i] = ch = getch()) || ch == '-')
			while(isdigit(str[++i] = ch = getch()))
			;
	}
	str[i] = '\0';
	if(ch != EOF)
		ungetch(ch);
	return NUMBER;

}
