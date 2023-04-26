#include "shell.h"

char *_strnchr(const char *str, int q);
size_t _strnspn(const char *str1, const char *str2);
size_t _strncspn(const char *str1, const char *str2);

/**
 * _strntok - breaks the string str1 into tokens and null-terminates them.
 * Delimiter-Characters at the beginning and end
 *of string are skipped. On each subsequent call delim may change.
 * @strn: string to tokenize
 * @delim: string with the character that delimit srt.
 * Return: the first/next token if possible, a null-pointer otherwise.
 **/
char *_strntok(char *strn, const char *delim)
{
	static char *ptr;

	if (strn)
		ptr = strn;
	else if (!ptr)
		return (0);
	strn = ptr + _strnspn(ptr, delim);
	ptr = strn + _strncspn(strn, delim);
	if (ptr == strn)
		return (ptr = 0);
	ptr = *ptr ? *ptr = 0, ptr + 1 : 0;
	return (strn);
}
/**
 * _strncspn - computes the length of the maximum initial segment of the string
 * pointed to by str1 which consists entirely of characters not from the
 * string pointed to by str2.
 * @str1: string to check
 * @str2: string useful to compare
 * Return: the length of the segment.
 **/
size_t _strncspn(const char *str1, const char *str2)
{
	size_t ret = 0;

	while (*str1)
	{
		if (_strnchr(str2, *str1))
			return (ret);
		str1++, ret++;
	}
	return (ret);
}
/**
 * _strnspn - computes the length of the maximum initial segment of the string
 * pointed to by str1 which consists entirely of characters from the string
 * pointed to by str2.
 * @str1: strint to compute the lengh
 * @str2: string delimit
 * Return: the length of the segment.
 **/
size_t _strnspn(const char *str1, const char *str2)
{
	size_t ret = 0;

	while (*str1 && _strnchr(str2, *str1++))
		ret++;
	return (ret);
}
/**
 * _strnchr - locates the ﬁrst occurrence of c (converted to a char) in the
 * string pointed to by s. The terminating null character is considered to be
 * part of the string.
 * @s: string
 * @q: character
 * Return: a pointer to the located character, or a null pointer
 * if the character does not occur in the string.
 **/
char *_strnchr(const char *s, int q)
{
	while (*s != (char)q)
		if (!*s++)
			return (0);
	return ((char *)s);
}
