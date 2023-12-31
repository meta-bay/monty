#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

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
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct glo_vars_s - declared use for global varialables
 * @opcode: operation code
 * @args: operation arguments
 * @line_number: line number on file where operation is
 * @err_stat: holds the error status when an error is triggered
 * @SQ: flag that tells program if mode is stack or queue
 * @line_read: the line pointer
 * @the_tokens: the tokens
*/

typedef struct glo_vars_s
{
	char *opcode;
	char *args;
	char *line_read;
	char *the_tokens[3];
	unsigned int line_number;
	int err_stat;
	int SQ;
} glo_vars;

extern glo_vars *glob_vars;

/*task functions*/
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
size_t stack_length(stack_t *stack);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
void rotl_f(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, __attribute__ ((unused))unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, __attribute__ ((unused))unsigned int line_number);
void to_queue(stack_t **stack,
		__attribute__ ((unused))unsigned int line_number);
void to_stack(stack_t **stack,
				__attribute__ ((unused))unsigned int line_number);

/*process funtions*/
void tokenize(void);
void file_reading(FILE *file, stack_t **stack, instruction_t *instructions);
void instruct_ident(stack_t **stack, unsigned int line_number,
						FILE *file, instruction_t instructions[]);
stack_t *add_nodeat_end(stack_t **stack, stack_t *new_node);

/* to use functions*/
bool is_op_valid(char *op, instruction_t instructions[]);
void free_the_stack(stack_t **stack);
void display(void);
bool is_line_empty(char *line_read);
bool is_it_comment(char *line_read);
bool is_args_valid(char *op, char *args);
void initialize(void);
void free_globals(void);

#endif
