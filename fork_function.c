#include "shell.h"
/**
 * _fork_fun - function that create a fork
 *@path: command and values path
 *@prog: Has the name of our program
 *@env: environment
 *@lineptr: command line for the user
 *@q: id of process
 *@c: Checker add new test
 *Return: 0 success
 */

int _fork_fun(char **path, char **prog,
		char **env, char *lineptr, int q, int c)
{
	pid_t child;
	int status;
	char *format = "%s: %d: %s: not found\n";

	child = fork();

	if (child == 0)
	{
		if (execve(path[0], path, env) == -1)
		{
			fprintf(stderr, format, prog[0], q, path[0]);
			if (!c)
				free(path[0]);
			free(path);
			free(lineptr);
			exit(errno);
		}
	}
	else
	{
		wait(&status);

		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			return (WEXITSTATUS(status));
	}
	return (0);
}
