#include "main.h"

/**
 * _strlen- finds the length of a string
 * @str: the string
 * Return: the length
 */

int _strlen(const char *str)
{
	int len;

	len = 0;
	if (str == NULL)
		return (len);
	while (str[len])
		len++;
	return (len);
}

/**
 * _strcpy- copies a string
 * @dest: destination
 * @src: source
 * Return: the copy
 */

char *_strcpy(char *dest, char *src)
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
 * _strcat- concanetes strings
 * @dest: destination
 * @src: source
 * Return: new dest
 */

char *_strcat(char *dest, const char *src)
{
	size_t  len = _strlen(dest);
	size_t index = 0;

	while (src[index] != '\0')
	{
		dest[len + index] = src[index];
		index++;
	}
	dest[len + index] = '\0';
	return (dest);
}

/**
 * _strncat- concantenates n number of bytes to dest
 * @dest: destination
 * @src: source
 * @n: bytes
 * Return: new dest
 */

char *_strncat(char *dest, const char *src, size_t n)
{
	size_t len = _strlen(dest);
	size_t index = 0;

	while (index < n && src[index])
	{
		dest[len + index] = src[index];
		index++;
	}
	dest[len + index] = '\0';
	return (dest);
}

/**
 * _strchr- search for a char
 * @str: the string
 * @c: the char
 * Return: pointer or NULL
 */

char *_strchr(char *str, char c)
{
	int index;

	for (index = 0; str[index]; index++)
	{
		if (str[index] == c)
			return (str + index);
	}
	return (NULL);
}
