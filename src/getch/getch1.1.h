#ifndef GETCH_H_INCLUDED
#define GETCH_H_INCLUDED

#include<limits.h>

#define BUFFSIZE 10

#if STACK_SIZE > USHRT_MAX
# error "Stack size cannot be greater then maximum of unsigned int"
#endif

/* get characters from buffer or stdin if buffer is empty */
int getch(void);

/* put characters into buffer */
int ungetch(int ch);

/* put a whole string into buffer */
void ungetstr(char const *const s);
/* if the string is greater then buffer size then only a segment from the beginning is phrased into buff.
 */

#endif // GETCH_H_INCLUDED
