#ifndef SHELL_INC_H
#define SHELL_INC_H

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int func_cd(char **args);
int func_help(void);
int func_exit(void);
char *func_read_line(void);
int func_execute(char **args);
char **func_split_line(char *line);
int func_launch(char **args);
int func_num_builtins(void);

#define S_BUFSIZE 1024
#define S_TOK_BUFSIZE 64
#define S_TOK_DELIM " \t\r\n\a"

#endif
