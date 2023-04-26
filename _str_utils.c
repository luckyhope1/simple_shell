#include "shell.h"
/**
 *_strncat - copy string to another string.
 *@dest: char
 *@ch: char
 *Return: dest
 *
 */

char *_strncat(char *dest, char *ch)
{
	int d = 0;
	int j = 0;

	while (dest[d] != '\0')
	{
		d++;
	}
	while (ch[j] != '\0')
	{
		dest[d] = ch[j];
		d++;
		j++;
	}
	dest[d] = '\0';
	return (dest);
}

/**
 * _strncmp - compare the values of a string
 * @str1: character
 * @str2: character
 * Return: 0
 */

int _strncmp(char *str1, char *str2)
{
	int i;

	for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
	{
		if (str1[i] != str2[i])
			return ((int)str1[i] - str2[i]);
	}
	return (0);
}

/**
 * _strnlen - copies the string pointed to by src into dest
 * @ptr: A pointer
 * Return: char pointer to dest
 */

int _strnlen(char *ptr)
{
	int i = 0;

	while (*(ptr + i) != '\0')
	{
		i++;
	}

	return (i);
}

/**
 *_strcmp -  function that compares two strings.
 *@str1: string one
 *@str2: string two
 *@num: number of characters
 *
 * Return: diference
 */

size_t  _strcmp(char *str1, char *str2, size_t num)
{
	size_t i, j;

	for (j = 0; str1[j] != '\0' && j < num; j++)
	{
		i = str1[j] - str2[j];

		if (i != 0)
		{
			return (i);
		}
	}
	return (0);
}

/**
 * _strncpy - copies the string pointed to by src into dest
 * @dest: destination of the copy
 * @src: source of the copy
 *
 * Return: char pointer to dest
 */

char *_strncpy(char *dest, char *src)
{
	int k = 0;

	while (*(src + k) != '\0')
	{
		*(dest + k) = *(src + k);
		++k;
	}
	*(dest + k) = *(src + k);

	return (dest);
}
