#include "shell_inc.h"

/**
 * func_read_line - Read a line of input from stdin.
 *
 * Return: The line from stdin.
 */
char *func_read_line(void)
{
	int bufsize = S_BUFSIZE;
	int position = 0;
	char *buffer = malloc(sizeof(char) * bufsize);
	int c;

	if (!buffer)
	{
		fprintf(stderr, "error: allocation error\n");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		c = getchar();

		if (c == EOF || c == '\n')
		{
			buffer[position] = '\0';
			return (buffer);
		}
		else
		{
			buffer[position] = c;
		}
		position++;

		if (position >= bufsize)
		{
			bufsize += S_BUFSIZE;
			buffer = realloc(buffer, bufsize);
			if (!buffer)
			{
				fprintf(stderr, "error: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}

/**
 * func_split_line - Split a line into tokens.
 * @line: The line.
 *
 * Return: Null-terminated array of tokens.
 */
char **func_split_line(char *line)
{
	int bufsize = S_TOK_BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "error: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, S_TOK_DELIM);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += S_TOK_BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "error: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, S_TOK_DELIM);
	}
	tokens[position] = NULL;
	return (tokens);
}
