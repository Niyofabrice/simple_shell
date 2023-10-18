#include "main.h"

/**
 * env_error- env error
 * @data: data structure
 * Return: the message
 */
char *env_error(myshell *data)
{
	int length;
	char *error;
	char *ver_str;
	char *msg;

	ver_str = rev_atoi(data->counter);
	msg = ": Unable to add/remove from environment\n";
	length = _strlen(data->av[0]) + _strlen(ver_str);
	length += _strlen(data->args[0]) + _strlen(msg) + 4;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}

	_strcpy(error, data->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, data->args[0]);
	_strcat(error, msg);
	_strcat(error, "\0");
	free(ver_str);

	return (error);
}

/**
 * no_permission- no permission
 * @data: the data structure
 * Return: the message
 */
char *no_permission(myshell *data)
{
	int length;
	char *ver_str;
	char *error;

	ver_str = rev_atoi(data->counter);
	length = _strlen(data->av[0]) + _strlen(ver_str);
	length += _strlen(data->args[0]) + 24;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, data->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, data->args[0]);
	_strcat(error, ": Permission denied\n");
	_strcat(error, "\0");
	free(ver_str);
	return (error);
}
