#include "header.h"
/**
 * fpop - pops an element from the stack
 * @stack: pointer to the stack
 * @count: line number
 * @G_op: data container
 * Return: Nothing
*/
void fpop(stack_t **stack, unsigned int count, operation_t *G_op)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		fclose(G_op->file);
		free(G_op->content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = tmp->next;
	free(tmp);
}
