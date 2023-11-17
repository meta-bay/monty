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
		free_the_stack(stack);
		free_globals();
		exit(EXIT_FAILURE);
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
