#include "header.h"
/**
 * fpush - pushes a node to the stack
 * @stack: pointer to the stack
 * @count: line number
 * @G_op: data container
 * Return: Nothing
*/
void fpush(stack_t **stack, unsigned int count, operation_t *G_op)
{
	int flag = 0, i = 0, n;

	if (G_op->arg)
	{
		if (G_op->arg[0] == '-')
			i++;
		for (; G_op->arg[i] != '\0'; i++)
		{
			if (G_op->arg[i] > 57 || G_op->arg[i] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(G_op->file);
			free(G_op->content);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
		n = atoi(G_op->arg);
		addNode(stack, n);
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(G_op->file);
		free(G_op->content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
