#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: the stack
 * @line_number: line where pint is called in the monty bytecode file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		glob_vars->err_stat = -1;
		return;
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: the stack
 * @line_number: line in monty bytecode file where pop is called
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		glob_vars->err_stat = -1;
		return;
	}

	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}
