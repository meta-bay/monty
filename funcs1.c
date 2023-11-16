#include "monty.h"

/**
 * display - displays the elements of the queue
 */
void display(void)
{
	if (glob_vars->the_tokens[0])
		printf("opcode: %s\n", glob_vars->the_tokens[0]);
	if (glob_vars->the_tokens[1])
		printf("args: %s\n", glob_vars->the_tokens[1]);
}

/**
 * delet - deletes the only element of the queue
 */
void delet(void)
{
	if (glob_vars->the_tokens[0])
	{
		free(glob_vars->the_tokens[0]);
		glob_vars->the_tokens[0] = NULL;
	}
	if (glob_vars->the_tokens[1])
	{
		free(glob_vars->the_tokens[1]);
		glob_vars->the_tokens[1] = NULL;
	}
}

/**
 * handle_malloc_err - does necessary memory deallocation, handles malloc error
 * @ptr: pointer to pointer to char to be freed
 * @file: the file
 */
void handle_malloc_err(char **ptr, FILE *file)
{
	if (ptr)
		free_mem(ptr);
	if (file)
		fclose(file);
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * free_mem - frees by iterating through
 * @mem: mem to be freed
 */
void free_mem(char **mem)
{
	int i = 0;

	if (mem == NULL)
		return;
	while (mem[i])
	{
		free(mem[i]);
		i++;
	}
	free(mem);
	mem = NULL;
}

/**
 * initialize - initializes
*/

void initialize(void)
{
	glob_vars = malloc(sizeof(glo_vars));
	glob_vars->opcode = NULL;
	glob_vars->args = NULL;
	glob_vars->line_read = NULL;
	glob_vars->the_tokens[0] = NULL;
	glob_vars->the_tokens[1] = NULL;
	glob_vars->the_tokens[2] = NULL;
	glob_vars->line_number = 0;
	glob_vars->err_stat = 0;
	glob_vars->SQ = 0;
}