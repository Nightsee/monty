#include "header.h"

void fpush(stack_t **stack, unsigned int count)
{
	int flag = 0, i = 0, n;

	if (G_op.arg)
	{
		if (G_op.arg[0] == '-')
			i++;
		for (; G_op.arg[i] != '\0'; i++)
		{
			if (G_op.arg[i] > 57 || G_op.arg[i] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(G_op.file);
			free(G_op.content);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
		n = atoi(G_op.arg);
		addNode(stack, n);
	}
	else 
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(G_op.file);
		free(G_op.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
