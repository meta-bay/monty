#include "monty.h"

/**
 * push - pushes number to the stack
 * @stack: the stack
 * @line_number: count the number of lines
*/

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	if (!is_args_valid(glob_vars->the_tokens[0], glob_vars->the_tokens[1]))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		glob_vars->err_stat = -1;
		return;
	}

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		glob_vars->err_stat = -1;
		return;
	}
	new_node->n = atoi(glob_vars->the_tokens[1]);
	new_node->prev = NULL;
	if (*stack == NULL)
	{
		new_node->next = NULL;
		*stack = new_node;
	}
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;

	}
}

/**
 * pall - prints all the values on the stack
 * @stack: the stack
 * @line_number: count the number of lines
*/

void pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pchar - prints at the top of the stack
 * @stack: the stack
 * @line_number: line in monty bytecode file
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		glob_vars->err_stat = -1;
		return;
	}
	if ((*stack)->n > 127 || (*stack)->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		glob_vars->err_stat = -1;
		return;
	}
	printf("%c\n", (*stack)->n);
}

/**
 * pstr - prints starting at the top of the stack
 * @stack: the stack
 * @line_number: line in monty bytecode file
 */
void pstr(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *tem;

	tem = *stack;
	while (tem)
	{
		if (tem->n <= 0 || tem->n > 127)
			break;
		printf("%c", tem->n);
		tem = tem->next;
	}
	printf("\n");
}
