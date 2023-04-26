#include "shell.h"
/**
 * _exit_command - this function closes the simple_shell when
 * @ptr: pointer with the direction argument.
 * @lineptr: standar input string
 * @_exit: value of exit
 * Return: None
 */
void _exit_command(char **ptr, char *lineptr, int _exit)
{
	int exit_status = 0;

	if (!ptr[1])
	{
		free(lineptr);
		free(ptr);
		exit(_exit);
	}
	exit_status = atoi(ptr[1]);

	free(lineptr);
	free(ptr);
	exit(exit_status);
}

/**
 *_getenv - function to get all env
 *@env: enviroment
 *Return: 0
 */

void _getenv(char **env)
{
	size_t rtn = 0;

	while (env[rtn])
	{
		write(STDOUT_FILENO, env[rtn], _strnlen(env[rtn]));
		write(STDOUT_FILENO, "\n", 1);
		rtn++;
	}
}
