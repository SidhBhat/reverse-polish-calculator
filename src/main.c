#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<sys/ioctl.h>
#include<unistd.h>
#include"revrse_polish_calc.h"

#define MAX_STR MAXOP
#define STATE_FAIL 1
#define STATE_SUCCESS 0
#define STATE_RESET STATE_SUCCESS

static short popflg = STATE_RESET;
struct winsize w;

double popw(void)
{
	double val = pop();

	if((isnan(val) ? 1 : (popflg = STATE_SUCCESS, 0)) && popflg == STATE_SUCCESS) {
		printf("\x1b[31mError \x1b[0m: an empty stack event detected, please supply sufficient arguments\n");
		popflg = STATE_FAIL;
	}
	return val;
}

int main(void)
{
	int type;
	double oprd; //temp location for a oparand
	char str[MAX_STR];

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

	putchar('#');
	for (int i = 0; i < w.ws_col - 2; i++)
		putchar('-');
	printf("#\nReverse Polish Calculator\n#");
	for (int i = 0; i < w.ws_col - 2; i++)
		putchar('-');
	puts("#");


	while((type = getop(str)) != EOF)
		switch(type) {
			case NUMBER:
				push(atof(str));
				break;
			case '+':
				push(popw() + popw());
				break;
			case '*':
				push(popw() * popw());
				break;
			case '-':
				oprd = popw();
				push(popw() - oprd);
				break;
			case '/':
				oprd = popw();
				if(oprd == 0.0) {
					printf("\x1b[31mError \x1b[0m: Division by zero\n");
					push(INFINITY);
				}
				else
					push(popw() / oprd);
				break;
			case '%':
				oprd = popw();
				if(oprd == 0.0)
					printf("\x1b[31mError \x1b[0m: Division by zero\n");
				push(fmod(popw(), oprd));
				break;
			case '^':
				oprd = popw();
				push(pow(pop(), oprd));
				break;
			case '\n':
				printf("ans =\t%10.8g\n", pop());

				popflg = STATE_RESET;
				ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
				for (int i = 0; i < w.ws_col; i++)
					putchar('-');
				putchar('\n');
				break;
			default:
				printf("\x1b[31mError \x1b[0m: unknown command \"%s\"\n", str);
				break;
		}

	return 0;
}
