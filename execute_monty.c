#include "header.h"

int execute_monty(char *line, stack_t **stack, unsigned int count, FILE *file)
{
	instruction_t operations[] = {
		{"push", fpush},
		{"pall", fpall},
		{"pint", fpint},
		{"pop", fpop},
		{"swap", fswap},
		{"add", fadd},
		{"nop", fnop},
		{NULL, NULL}
	};

	int i = 0;
	char *op;

	op = strtok(line, " \n\t");
	if (op && op[0] == '#')
	{
		return (0);
	}
	G_op.arg = strtok(NULL, " \n\t");
	while (operations[i].opcode && op)
	{
		if (strcmp(operations[i].opcode, op) == 0)
		{
			operations[i].f(stack, count);
			return (0);
		}
		i++;
	}
	/* if the code does not match with any of those in operations opcodes then we should print error */
	if (op && operations[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, op);
		fclose(file);
		free(line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
