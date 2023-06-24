#include "header.h"
/**
 * free_stack - frees the allocated memory of a stack
 * @stack: pointer to the stack
 * Return: nothing
*/
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
