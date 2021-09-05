#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<sys/ioctl.h>
#include<unistd.h>
#include"revrse_polish_calc.h"

#define MAX_STR MAXOP

struct winsize w;

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
	putchar('#');


	while((type = getop(str)) != EOF)
		switch(type) {
			case NUMBER:
				push(atof(str));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				oprd = pop();
				push(pop() - oprd);
				break;
			case '/':
				oprd = pop();
				if(oprd == 0.0) {
					printf("\x1b[31mError \x1b[0m: Division by zero\n");
					push(INFINITY);
				}
				else
					push(pop() / oprd);
				break;
			case '\n':
				if(isnan(oprd = pop()))
					printf("\x1b[31mError \x1b[0m: an empty stack event detected\n");
				printf("ans =\t%10.8g\n", oprd);
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
