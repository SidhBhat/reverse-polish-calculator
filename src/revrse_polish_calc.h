#ifndef REVRSE_POLISH_CALC_H_INCLUDED
#define REVRSE_POLISH_CALC_H_INCLUDED

#include"stack.h"
#include"getch.h"

// getop: function to recognise operators and numbers ,writing number to to string
int getop(char *const str);

#define MAXOP 100      /*max size of operator*/
#define NUMBER '0'          /*siganl that value is number */

#endif // REVRSE_POLISH_CALC_H_INCLUDED
