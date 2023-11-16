#include "monty.h"

glo_vars *glob_vars = NULL;
/**
 * main - entry of the program
 * @ac: number of arguments
 * @av: array of arguments
 * Return: (0)
*/

int main(int ac, char *av[])
{
	FILE *file;
	stack_t *stack = NULL;

	void initialize(void);
	instruction_t instructions[] = {
		{"push", push},	{"pall", pall},
		{NULL, NULL}};
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	file_reading(file, &stack, instructions);
	free_the_stack(&stack);
	fclose(file);
	free(glob_vars->line_read);
	exit(EXIT_SUCCESS);
}
