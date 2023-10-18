#include "main.h"

/**
 * find_error- find the error
 * @data: the data structure
 * @eval: error value
 * Return: error
 */
int find_error(myshell *data, int eval)
{
	char *error;

	switch (eval)
	{
		case -1:
			error = env_error(data);
			break;
		case 126:
			error = no_permission(data);
			break;
		case 127:
			error = not_found(data);
			break;
		case 2:
			if (_strcmp("exit", data->args[0]) == 0)
				error = cant_exit(data);
			else if (_strcmp("cd", data->args[0]) == 0)
				error = cant_cd(data);
			break;
	}
	if (error)
	{
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
	}
	data->status = eval;
	return (eval);
}
