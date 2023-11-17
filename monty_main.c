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

	instruction_t instructions[] = {
		{"push", push}, {"pall", pall},
		{"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add},
		{"nop", nop}, {"sub", sub},
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
	initialize();
	file_reading(file, &stack, instructions);
	free_the_stack(&stack);
	fclose(file);
	free_globals();
	exit(EXIT_SUCCESS);
}
