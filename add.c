#include "header.h"

/**
 * fadd - adds an element to the stack.
 * @st: pointer to the stack
 * @count: line number
 * @G_op: data container
 * Return: nothing
*/

void fadd(stack_t **st, unsigned int count, operation_t *G_op)
{
	stack_t *tmp;
	int len = 0, t;

	tmp = *st;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		fclose(G_op->file);
		free(G_op->content);
		free_stack(*st);
		exit(EXIT_FAILURE);
	}
	tmp = *st;
	t = tmp->n + tmp->next->n;
	tmp->next->n = t;
	*st = tmp->next;
	free(tmp);
}
