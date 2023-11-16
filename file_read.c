#include "monty.h"

/**
 * file_reading - reads the file and processes it
 * @file: the read file
 * @stack: pointer to struct stack
 * @instructions: and array stuct of opcode and function pointer
*/

void file_reading(FILE *file, stack_t **stack, instruction_t *instructions)
{
	glob_vars.line_read = malloc(1024);
	if (!glob_vars.line_read)
		exit(EXIT_FAILURE);
	while (fgets(glob_vars.line_read, 1024, file))
	{
		glob_vars.line_number++;
		if (is_line_empty(glob_vars.line_read) || is_it_comment(glob_vars.line_read))
			continue;
		tokenize();
		if (!is_op_valid(glob_vars.the_tokens[0], instructions))
		{
			fprintf(stderr, "L%d: unknown instruction %s\n",
			glob_vars.line_number, glob_vars.the_tokens[0]);
			free_the_stack(stack);
			fclose(file);
			exit(EXIT_FAILURE);
		}
		insert(glob_vars.the_tokens, glob_vars.line_number, file);
		instruct_ident(stack, glob_vars.line_number, file, instructions);
		delet();
		glob_vars.line_read = malloc(1024);
		if (!glob_vars.line_read)
			exit(EXIT_FAILURE);
	}
}

/**
 * is_line_empty - checks if the line is empty or not
 * @line_read: pointer to the line
 * Return: true if empty else false
*/

bool is_line_empty(char *line_read)
{
	int i = 0;

	if (glob_vars.line_read[i] == '\n')
		return (true);
	while (glob_vars.line_read[i] != '\n')
	{
		if (glob_vars.line_read[i] != ' ' && glob_vars.line_read[i] != '\t')
			return (false);
		i++;
	}
	return (true);
}

/**
 * is_it_comment - checks if it is comment or not
 * @line_read: pointer to the line
 * Return: true if it is false if not
*/

bool is_it_comment(char *line_read)
{
	int i = 0;

	while (glob_vars.line_read[i] != '\n' &&
	(glob_vars.line_read[i] == ' ' || glob_vars.line_read[i] == '\t'))
		i++;
	if (glob_vars.line_read[i] != '#')
		return (false);
	return (true);
}

/**
 * instruct_ident - identifies the instructions
 * @stack: the stack
 * @line_number: counts number of line
 * @file: the file
 * @instructions: collection of instructions
*/

void instruct_ident(stack_t **stack, unsigned int line_number,
						FILE *file, instruction_t instructions[])
{
	int i = 0;

	while (instructions[i].opcode)
	{
		if (strcmp(glob_vars.the_tokens[0], instructions[i].opcode) == 0)
			(instructions[i].f)(stack, line_number);
		if ((glob_vars.err_stat) < 0)
		{
			delet();
			free_the_stack(stack);
			fclose(file);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
