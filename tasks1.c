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

/**
 * to_stack - switches the mode to stack
 * @stack: stack
 * @line_number: the line number
 */

void to_stack(__attribute__ ((unused))stack_t **stack,
				__attribute__ ((unused))unsigned int line_number)
{
	glob_vars->SQ = 0;
}

/**
 * to_queue - switches to queue
 * @stack: stack
 * @line_number: the line number
 */

void to_queue(__attribute__ ((unused))stack_t **stack,
		__attribute__ ((unused))unsigned int line_number)
{
	glob_vars->SQ = 1;
}

/**
 * add_nodeat_end - adds node at the end
 * @stack: the stack
 * @new_node: the data
 * Return: he address of the new element, or NULL if it failed
*/

stack_t *add_nodeat_end(stack_t **stack, stack_t *new_node)
{
	stack_t *ptr_to_last;

	if (new_node == NULL)
		return (NULL);
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*stack == NULL)
	{
		(*stack) = new_node;
		return (*stack);
	}
	ptr_to_last = (*stack);
	while (ptr_to_last->next != NULL)
	{
		ptr_to_last = ptr_to_last->next;
	}
	ptr_to_last->next = new_node;
	new_node->prev = ptr_to_last;
	return (*stack);
}
