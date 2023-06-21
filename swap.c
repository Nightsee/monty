#include "header.h"

void fswap(stack_t **stack, unsigned int count)
{
	stack_t *h;
	int len = 0, p;

	h = *stack;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		fclose(G_op.file);
		free(G_op.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	p = h->n;
	h->n = h->next->n;
	h->next->n = p;
}
