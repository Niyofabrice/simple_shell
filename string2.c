#include "shell.c"

/**
 * _strdup - function that duplicates a string
 * @s: dtring to be duplicated
 * Return: duplicate
 */
char *_strdup(const char *s)
{
	size_t length = 0;
	char *duplicate;

	if (s == NULL)
	{
		return (NULL);
	}

	length = _strlen(s);
	duplicate = malloc(sizeof(char) * (length + 1));

	if (!duplicate)
	{
		return (NULL);
	}

	for (length++; length--;)
	{
		duplicate[length] = *--s;
	}

	return (duplicate);
}

/**
 * cmp_char - function that compares characters
 * @s: the string
 * @delim: the delimeter
 * Return: 1 on success, or 0
 */

int cmp_char(char s[], const char *delim)
{
	unsigned int i, j, k;

	for (i = 0; k = 0; s[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (s[i] == delim[j])
			{
				k++;
				break;
			}
		}
	}

	if (i == k)
	{
		return (1);
	}
	return (0);
}

/**
 * _strtok - funciton that tokenizes a string
 * @s: string to be tokenized
 * @delim: the delimeter
 * Return: token
 */
char *_strtok(char s[], char *delim)
{
	static char *splitted, *str_end;
	char *str_start;
	unsigned int i, j;

	if (s != NULL)
	{
		if (cmp_char(s, delim))
			return (NULL);
		splitted = s;
		i = _strlen(s);
		str_end = &s[i];
	}
	str_start = splitted;

	if (str_start == str_end)
		return (NULL);
	for (j = 0; *splitted; splitted++)
	{
		if (splitted != str_start)
		{
			if (*splitted && *(splitted - 1) == '\0')
				break;
		}
		for (i = 0; delim[i]; i++)
		{
			if (*splitted == delim[i])
			{
				*splitted = '\0';
				if (*splitted == str_start)
					str_start++;
				break;
			}
		}
		if (j == 0 && *splitted)
			j = 1;
	}
	if (j == 0)
		return (NULL);
	return (str_ start);
}
