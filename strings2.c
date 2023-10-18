#include "main.h"

/**
 * _strspn- length of substring
 * @str: the string
 * @sub: the substring
 * Return: the len
 */

int _strspn(char *str, char *sub)
{
	int len = 0;
	int index;

	while (*str)
	{
		for (index = 0; sub[index]; index++)
		{
			if (*str == sub[index])
			{
				len++;
				break;
			}
		}
		str++;
	}
	return (len);
}

/**
 * _strcmp- compares two strings
 * @str1: the first strings
 * @str2: the second string
 * Return: 0 on succ, or the difference
 */

int _strcmp(char *str1, char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	if (*str1 != *str2)
		return (*str1 - *str2);
	return (0);
}

/**
 * _strncmp- compares n bytes of 2 strings
 * @str1: the first string
 * @str2: the second string
 * @n: n bytes
 * Return: 0 if equal, or the difference
 */

int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t index;

	for (index = 0; str1[index] && str2[index] && n > index; index++)
	{
		if (str1[index] > str2[index])
			return (str1[index] - str2[index]);
		else if (str2[index] > str1[index])
			return (str1[index] - str2[index]);
	}
	if (index == n)
		return (0);
	else
		return (-1);
}

/**
 * _strdup- duplicates a strings
 * @str: string to duplicate
 * Return: duplicate
 */

char *_strdup(const char *str)
{
	char *dup;
	size_t len;

	len = _strlen(str);
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	_memcpy(dup, str, len + 1);
	return (dup);
}
