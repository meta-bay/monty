#include "monty.h"

/**
 * is_op_valid - checks if it is valid opcode
 * @op: the opcode
 * @instructions: collection of instructions
 * Return: true if valid, false if not
*/

bool is_op_valid(char *op, instruction_t instructions[])
{
	int i = 0;

	while (instructions[i].opcode)
	{
		if (strcmp(op, instructions[i].opcode) == 0)
			return (true);
		i++;
	}
	return (false);
}

/**
 * is_args_valid - check if it is the right data type for an argument
 * @op: the opcode
 * @args: the argument
 * Return: true if valid else false
*/

bool is_args_valid(char *op, char *args)
{
	size_t i;

	if (strncmp(op, "push", strlen("push")) == 0)
	{
		if (args)
		{
			for (i = 0; i < strlen(args); i++)
			{
				if (i == 0 && args[0] == '-')
					continue;
				if (!isdigit(args[i]))
					return (false);
			}
			return (true);
		}
		return (false);
	}
	return (true);
}

/**
 * free_the_stack - frees the stack
 * @stack: the stack
*/

void free_the_stack(stack_t **stack)
{
	stack_t *temp;

	if (!(*stack))
		return;
	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	free(*stack);
}

/**
 * free_globals - frees the global variables
 */
void free_globals(void)
{
	if (glob_vars)
	{
		free(glob_vars->line_read);
		free(glob_vars);
		glob_vars = NULL;
	}
}
