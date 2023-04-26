#include "shell.h"
/**
 * _get_path - get variable PATH.
 * @env: enviromente local
 * Return: value of PATH.
 */

char *_get_path(char **env)
{
	size_t index = 0, val = 0, count = 5;
	char *path = NULL;

	for (index = 0; _strncmp(env[index], "PATH="); index++)
		;
	if (env[index] == NULL)
		return (NULL);

	for (count = 5; env[index][val]; val++, count++)
		;
	path = malloc(sizeof(char) * (count + 1));

	if (path == NULL)
		return (NULL);

	for (val = 5, count = 0; env[index][val]; val++, count++)
		path[count] = env[index][val];

	path[count] = '\0';
	return (path);
}
