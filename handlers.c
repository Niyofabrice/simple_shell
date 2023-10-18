#include "main.h"

/**
 * execute- handle builtin or command
 * @data: the data structure
 * Return: 1 on success
 */
int execute(myshell *data)
{
	int (*builtin)(myshell *data);

	if (data->args[0] == NULL)
		return (1);
	builtin = findbuiltin(data->args[0]);
	if (builtin != NULL)
		return (builtin(data));
	return (handle_com(data));
}
