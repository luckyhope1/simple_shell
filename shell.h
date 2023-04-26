#ifndef SHELL_H
#define SHELL_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

extern char **environ;

int _strncmp(char *str1, char *str2);
size_t _strcmp(char *str1, char *str2, size_t num);
int _strnlen(char *ptr);
char *_strncpy(char *dest, char *src);
char *_strncat(char *dest, char *ch);
int _putchar(char c);
int main(int count, char **arg, char **env);
char *_get_path(char **env);
int _values_path(char **com, char **env);
char *_getline_command(void);
void _getenv(char **env);
char **_get_token(char *lineptr);
void _exit_command(char **ptr, char *lineptr, int _exit);
int _fork_fun(char **path, char **prog, char **env,
		char *lineptr, int q, int c);
char *_strntok(char *strn, const char *delim);

#endif /* SHELL_H */
