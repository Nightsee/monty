#include "header.h"

/**
 * fpint - prints the data in one.
 * @stack: pointer to the stack
 * @count: line number
 * Return: nothing
*/

void fpint(stack_t **stack, unsigned int count)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", count);
		fclose(G_op.file);
		free(G_op.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
