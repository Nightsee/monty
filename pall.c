#include "header.h"

void fpall(stack_t **stack, unsigned int count)
{
	stack_t *tmp;
	(void) count;

	tmp = *stack;
	if (tmp == NULL)
		return ;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
