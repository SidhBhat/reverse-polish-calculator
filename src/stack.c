#include<math.h>
#include<stddef.h>
#include"stack.h"

static unsigned short stack_pos = 0;
static double stack[STACK_SIZE];

/* push :function to write to stack */
double const *push(double val)
{
	if(stack_pos < STACK_SIZE) {
		stack[stack_pos++] = val;
		return &stack[stack_pos];
	}
	stack_pos = 0;
	stack[stack_pos++] = val;

	return NULL;
}
/* Return value is a pointer to the stack value
 * if stack if full then the the return value is a Null pointer, and the pushed to the start of the stack.
 * effectively the data in the stack is lost
 */

/* pop: function to get value from the stack */
double pop(void)
{
	if (stack_pos > 0)
		return stack[--stack_pos];
	else {
		return nan("");
	}
}
/* Returns NaN if stack is empty */
