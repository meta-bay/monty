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
