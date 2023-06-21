#include "header.h"

void free_stack(stack_t *stack)
{
	stack_t *tmp;

	/*tmp = stack;*/
	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}
