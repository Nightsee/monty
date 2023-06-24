#include "header.h"
/**
 * fpall - prints the elements of a stack
 * @stack: pointer to the stack
 * @count: line number
 * @G_op: data container
 * Return: nothing
*/
void fpall(stack_t **stack, unsigned int count, operation_t *G_op)
{
	stack_t *tmp;
	(void) count;
	(void) G_op;

	tmp = *stack;
	if (tmp == NULL)
		return;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
