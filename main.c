#define  _GNU_SOURCE
#include "header.h"

operation_t G_op = {NULL, NULL, NULL};

int main(int ac, char **av)
{
	FILE *file;
	size_t size = 0;
	char *line;
	ssize_t readline = 1;
	stack_t *stack = NULL;
	unsigned int count = 1;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	G_op.file = file;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	/* read the file */
	while (readline > 0)
	{
		line = NULL;
		readline = getline(&line, &size, file);
		G_op.content = line;
		if (line != NULL)
		{
			execute_monty(line, &stack, count, file);
		}
		count++;
		free(line);
	}
	free_stack(stack);
	fclose(file);

	return (0);
}
