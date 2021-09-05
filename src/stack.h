#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include<limits.h>

#define STACK_SIZE 5

#if STACK_SIZE > USHRT_MAX
# error "Stack size cannot be greater then maximum of unsigned int"
#endif
/* push :function to write to stack */
double const *push(double val);
/* Return value is a pointer to the stack value
 * if stack if full then the the return value is a Null pointer, and the pushed to the start of the stack.
 * effectively the data in the stack is lost
 */

/* pop: function to get value from the stack */
double pop(void);
/* Returns NaN if stack is empty */


#endif // STACK_H_INCLUDED
