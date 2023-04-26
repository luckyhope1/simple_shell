#include "shell.h"
/**
 * _values_path - separate the path in new strings.
 * @com: command input of user.
 * @env: enviroment.
 * Return:  a pointer to strings.
 */
int _values_path(char **com, char **env)
{
	char *token = NULL, *path_val = NULL, *path_absol = NULL;
	size_t value_path, command;
	struct stat stat_lineptr;

	if (stat(*com, &stat_lineptr) == 0)
		return (-1);
	path_val = _get_path(env);
	if (!path_val)
		return (-1);
	token = _strntok(path_val, ":");
	command = _strnlen(*com);
	while (token)
	{
		value_path = _strnlen(token);
		path_absol = malloc(sizeof(char) * (value_path + command + 2));
		if (!path_absol)
		{
			free(path_val);
			return (-1);
		}
		path_absol = _strncpy(path_absol, token);
		_strncat(path_absol, "/");
		_strncat(path_absol, *com);

		if (stat(path_absol, &stat_lineptr) == 0)
		{
			*com = path_absol;
			free(path_val);
			return (0);
		}
		free(path_absol);
		token = _strntok(NULL, ":");
	}
	free(path_val);
	return (-1);
}
