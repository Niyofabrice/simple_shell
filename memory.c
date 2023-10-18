#include "main.h"

/**
 * _memcpy- copies memory info
 * @newptr: pointer to new mem
 * @ptr: source
 * @size: size of new pointer
 */
void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
	char *char_ptr = (char *)ptr;
	char *char_newptr = (char *)newptr;
	unsigned int i;

	for (i = 0; i < size; i++)
		char_newptr[i] = char_ptr[i];
}

/**
 * _realloc- reallocates memory
 * @ptr: previous memory
 * @old_size: previous size
 * @new_size: new size
 * Return: pointer to new memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *newptr;

	if (ptr == NULL)
		return (malloc(new_size));
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
		return (ptr);
	newptr = malloc(new_size);
	if (newptr == NULL)
		return (NULL);
	if (new_size < old_size)
		_memcpy(newptr, ptr, new_size);
	else
		_memcpy(newptr, ptr, old_size);
	free(ptr);
	return (newptr);
}

/**
 * _reallocdp- reallocates memory for double pointer
 * @ptr: previous double pointer
 * @old_size: previous size
 * @new_size: new size
 * Return: pointer to new memory
 */
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **newptr;
	unsigned int i;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_size));
	if (new_size == old_size)
		return (ptr);
	newptr = malloc(sizeof(char *) * new_size);
	if (newptr == NULL)
		return (NULL);
	for (i = 0; i < old_size; i++)
		newptr[i] = ptr[i];
	free(ptr);
	return (newptr);
}
