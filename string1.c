#include "shell.h"

/**
 * _strcmp - function that compares two strings
 * @s1: first string
 * @s2: second string
 * Return: 0 on success, or difference
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
	{
		return (*s1 - *s2);
	}

	return (0);
}

/**
 * _strlen - function that returns the length of a string
 * @s: the string
 * Return: the length of the string
 */
int _strlen(const char *s)
{
	int length = 0;

	if (!s)
	{
		return (length);
	}

	while (s[length])
	{
		length++;
	}

	return (length);
}

/**
 * _strcpy - function that copies a string
 * @dest: destination variable
 * @src: source of the string
 * Return: the copy
 */
char *_strcpy(char *dest, const char *src)
{
	size_t index = 0;

	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';

	return (dest);
}

/**
 * _strcat - function that concatenate strings
 * @dest: destination variable
 * @src: source string
 * Return: concatenated string
 */
char *_strcat(char *dest, const char *src)
{
	size_t length = _strlen(dest);
	size_t index = 0;

	while (src[index] != '\0')
	{
		dest[length + index] = src[index]
		index++;
	}
	dest[length + index] = '\0';

	return (dest);
}

/**
 * _strncat - function that concatenates n number of byte
 * @dest: destination variable
 * @src: source string
 * @n: number of bytes
 * Return: concatenated string
 */
char *_strncat(char *dest, const char *src, size_t n)
{
	size_t length = _strlen(dest);
	size_t index = 0;

	while (index < n && src[index])
	{
		dest[length + index] = src[index];
		index++;
	}
	dest[length + index] = '\0';

	return (dest);
}
