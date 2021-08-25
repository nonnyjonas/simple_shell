#include "shell_inc.h"

char *builtin_str[] = {
	"cd",
	"help",
	  "exit"
};

int (*builtin_func[]) (char **) = {
	&func_cd,
	&func_help,
	  &func_exit
};

/**
 * func_num_builtins -Builtin command: print help.
 *
 * Return: ..
 */
int func_num_builtins(void)
{
	return (sizeof(builtin_str) / sizeof(char *));
}

/**
 * func_help -Builtin command: print help.
 *
 * Return: 1
 */
int func_help(void)
{
	int i;

	printf("The following are built in commands for the shell:\n");

	for (i = 0; i < func_num_builtins(); i++)
	{
		printf("  %s\n", builtin_str[i]);
	}

	printf("Use the man command for information on other programs.\n");
	return (1);
}

/**
 * func_execute - Execute shell built-in or launch program.
 * @args: Null terminated list of arguments.
 *
 * Return: 1 if the shell should continue running, 0 if it should terminate
 */
int func_execute(char **args)
{
	int i;

	if (args[0] == NULL)
	{
		return (1);
	}

	for (i = 0; i < func_num_builtins(); i++)
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
		{
			return ((*builtin_func[i])(args));
		}
	}

	return (func_launch(args));
}
