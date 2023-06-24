#include "header.h"
/**
 * addNode - adds a node at the end of the node
 * @stack: pointer to the stack
 * @n: data to store in the node
 * Return: void
*/
void addNode(stack_t **stack, int n)
{
	stack_t *new, *tmp;

	tmp = *stack;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (tmp)
		tmp->prev = new;
	new->n = n;
	new->next = *stack;
	new->prev = NULL;
	*stack = new;
}
