#ifndef REVRSE_POLISH_CALC_H_INCLUDED
#define REVRSE_POLISH_CALC_H_INCLUDED

#include"stack.h"

#define OPLIST {"sin","cos","tan","sinh","cosh","tanh","ln","log","pow",""}

extern const char *operators[];

const char my_strcomp(const char *str1, const char *str2);

// getop: function to recognise operators and numbers ,writing number to to string
int getop(char *const str);



#define MAXOP 100      /*max size of operator*/
#define NUMBER '0'          /*siganl that value is number */
#define OPERATOR '1'

#endif // REVRSE_POLISH_CALC_H_INCLUDED
