#include "header.h"

void fadd(stack_t **st, unsigned int count)
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
		fclose(G_op.file);
		free(G_op.content);
		free_stack(*st);
		exit(EXIT_FAILURE);
	}
	tmp = *st;
	t = tmp->n + tmp->next->n;
	tmp->next->n = t;
	*st = tmp->next;
	free(tmp);
}
