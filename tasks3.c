#include "monty.h"

/**
 * _div - divides second element by top element
 * @stack: the stack
 * @line_number: line in monty bytecode file
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if (stack_length(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		glob_vars->err_stat = -1;
		return;
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		glob_vars->err_stat = -1;
		return;
	}
	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_number);
}

/**
 * _mul - multiplies second element with top element
 * @stack: the stack
 * @line_number: line in monty bytecode file
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	if (stack_length(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		glob_vars->err_stat = -1;
		return;
	}
	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}

/**
 * _mod - modulos of the second element by the top element
 * @stack: stack
 * @line_number: line in monty bytecode file
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	if (stack_length(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		glob_vars->err_stat = -1;
		return;
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		glob_vars->err_stat = -1;
		return;
	}
	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}

/**
 * rotl_f - rotates the stack down.
 * @stack: the stack.
 * @line_number: counts line number.
*/
void rotl_f(stack_t **stack, unsigned int line_number)
{
	stack_t *the_tp = *stack;
	stack_t *tmp = *stack;
	(void)line_number;

	if (!stack || !the_tp)
	{
		nop(stack, line_number);
		return;
	}

	if (the_tp->next)
	{
		*stack = (*stack)->next;
		while (the_tp->next)
			the_tp = the_tp->next;

		(*stack)->prev = NULL;
		the_tp->next = tmp;
		tmp->next = NULL;
		tmp->prev = the_tp;
	}
}

/**
 * rotr - rotates the stack to bottom
 * @stack: the stack
 * @line_number: line in monty bytecode file
 */
void rotr(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *the_bot, *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	the_bot = *stack;

	while (the_bot->next->next)
		the_bot = the_bot->next;

	tmp = the_bot->next;
	the_bot->next = NULL;
	(*stack)->prev = tmp;
	tmp->next = *stack;
	*stack = tmp;
	(*stack)->prev = NULL;
}
