#include "monty.h"

/**
 * tokenize - break the line into tokens
*/

void tokenize(void)
{
	glob_vars->the_tokens[0] = strtok(glob_vars->line_read, " \t\n");
	glob_vars->the_tokens[1] = strtok(NULL, "\t\n");
	glob_vars->the_tokens[2] = NULL;
}
