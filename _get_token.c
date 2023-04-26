#include "shell.h"
/**
 * _get_token - get token of string
 * @lineptr: command user
 * Return: To a pointer
 */

char **_get_token(char *lineptr)
{
	char **user_command = NULL;
	char *token = NULL;
	size_t j = 0;
	int size = 0;

	if (lineptr == NULL)
		return (NULL);

	for (j = 0; lineptr[j]; j++)
	{
		if (lineptr[j] == ' ')
			size++;
	}
	if ((size + 1) == _strnlen(lineptr))
		return (NULL);
	user_command = malloc(sizeof(char *) * (size + 2));
	if (user_command == NULL)
		return (NULL);

	token = _strntok(lineptr, " \n\t\r");
	for (j = 0; token != NULL; j++)
	{
		user_command[j] = token;
		token = _strntok(NULL, " \n\t\r");
	}
	user_command[j] = NULL;
	return (user_command);
}
