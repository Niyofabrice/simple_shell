#include "shell.h"

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

/**
 * _realloc - function that reallocates memory using malloc and free
 * @ptr: pointer to the memory previously allocated
 * @old_size: size in bytes of the allocated space for ptr
 * @new_size: size in bytes of the newly allocated memory block
 * Return: ptr if new_size = old_size
 * NULL if new_size = 0 and ptr is not = null
 * pointer to newly allocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *mem;
	char *ptr_copy, *filler;
	unsigned int index;

	if (new_size == old_size)
	{
		return (ptr);
	}

	if (ptr == NULL)
	{
		mem = malloc(new_size);
		if (mem == NULL)
		{
			return (NULL);
		}

		return (mem);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	ptr_copy = ptr;
	mem = malloc(sizeof(*ptr_copy) * new_size);
	if (mem == NULL)
	{
		free(ptr);
		return (NULL);
	}
	filler = mem;

	for (index = 0; index < old_size && index < new_size; index++)
	{
		filler[index] = *ptr_copy++;
	}

	free(ptr);
	return (mem);
}

/**
 * assign_lineptr - function that reassignes the lineptr variable for _getline
 * @lineptr: buffer to store an input string
 * @n: the size of lineptr
 * @buffer: the string to assign to lineptr
 * @b: size of buffer
 */
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b)
{
	if (*lineptr == NULL)
	{
		if (b > 120)
		{
			*n = b;
		}
		else
		{
			*n = 120;
		}
		*lineptr = buffer;
	}
	else if (*n < b)
	{
		if (b > 120)
		{
			*n = b;
		}
		else
		{
			*n = 120;
		}
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}

/**
 * _getline - function tha reads input from stream
 * @lineptr: buffer to store the input
 * @n: size of lineptr
 * @stream: stream to read from
 * Return: number of bytes read
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static ssize_t input;
	ssize_t ret;
	char c = 'x', *buffer;
	int r;

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;
	buffer = malloc(sizeof(char) * 120);
	if (!buffer)
		return (-1);

	while (c != '\n')
	{
		r = read(STDIN_FILENO, &c, 1);
		if (r == -1 || (r == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (r == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= 120)
			buffer = _realloc(buffer, input, input + 1);

		buffer[input] = c;
		input++;
	}
	buffer[input] = '\0';
	assign_lineptr(lineptr, n, buffer, input);
	ret = input;
	if (r != 0)
		intput = 0;
	return (ret);
}
