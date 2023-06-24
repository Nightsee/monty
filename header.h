#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
*/

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct operation_s - a struct to help pass data
 * @arg: argument
 * @file: pointer to the file
 * @content: the command read from the file
 * Description: used to access data all over the function files
*/
typedef struct operation_s
{
	char *arg;
	FILE *file;
	char *content;
} operation_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
*/

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number, operation_t *G_op);
} instruction_t;


int execute_monty(char *line, stack_t **stack, unsigned int count,
		FILE *file, operation_t *G_op);
void free_stack(stack_t *stack);
void fpush(stack_t **stack, unsigned int count, operation_t *G_op);
void fpop(stack_t **stack, unsigned int count, operation_t *G_op);
void fadd(stack_t **stack, unsigned int count, operation_t *G_op);
void fnop(stack_t **stack, unsigned int count, operation_t *G_op);
void fpall(stack_t **stack, unsigned int count, operation_t *G_op);
void fpint(stack_t **stack, unsigned int count, operation_t *G_op);
void fswap(stack_t **stack, unsigned int count, operation_t *G_op);
void addNode(stack_t **stack, int n);
#endif
