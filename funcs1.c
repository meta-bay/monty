#include "monty.h"

/**
 * display - displays the elements of the queue
 */
void display(void)
{
	if (glob_vars.opcode)
		printf("opcode: %s\n", glob_vars.opcode);
	if (glob_vars.args)
		printf("args: %s\n", glob_vars.args);
}

/**
 * delet - deletes the only element of the queue
 */
void delet(void)
{
	if (glob_vars.opcode)
	{
		free(glob_vars.opcode);
		glob_vars.opcode = NULL;
	}
	if (glob_vars.args)
	{
		free(glob_vars.args);
		glob_vars.args = NULL;
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
		free_ptr(ptr);
	if (file)
		fclose(file);
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
