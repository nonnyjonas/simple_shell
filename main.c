#include "shell_inc.h"

/**
 * func_loop - Split a line into tokens.
 *
 * Return: Null-terminated array of tokens.
 */
void func_loop(void)
{
	char *line;
	char **args;
	int status;

	do {
		line = func_read_line();
		args = func_split_line(line);
		status = func_execute(args);

		free(line);
		free(args);
	} while (status);
}

/**
 * main - Entry point.
 *
 * Return: status code
 */
int main(void)
{
	func_loop();

	return (EXIT_SUCCESS);
}
