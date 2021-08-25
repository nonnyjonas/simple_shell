#include "shell_inc.h"

/**
 * func_cd - Bultin command: change directory.
 * @args: List of args. args[0] is "cd". args[1] is the directory.
 *
 * Return: 1
 */
int func_cd(char **args)
{
    if (args[1] == NULL)
    {
        fprintf(stderr, "error: expected argument to \"cd\"\n");
    }
    else
    {
        if (chdir(args[1]) != 0)
        {
            perror("error");
        }
    }
    return (1);
}

/**
 * func_exit - Builtin command: exit.
 *
 * Return: 0
 */
int func_exit(void)
{
    return (0);
}


