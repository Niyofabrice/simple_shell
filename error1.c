#include "main.h"

/**
 * cd_error- concatenates error msg
 * @data: data structure
 * @msg: message
 * @error: output
 * @ver_str: counter
 * Return: the message
 */
char *cd_error(myshell *data, char *msg, char *error, char *ver_str)
{
	char *illegal_flag;

	_strcpy(error, data->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, data->args[0]);
	_strcat(error, msg);
	if (data->args[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = data->args[1][1];
		illegal_flag[2] = '\0';
		_strcat(error, illegal_flag);
		free(illegal_flag);
	}
	else
	{
		_strcat(error, data->args[1]);
	}
	_strcat(error, "\n");
	_strcat(error, "\0");
	return (error);
}

/**
 * cant_cd- error got get cd
 * @data: data structure
 * Return: Error message
 */
char *cant_cd(myshell *data)
{
	int length, len_id;
	char *error, *ver_str, *msg;

	ver_str = rev_atoi(data->counter);
	if (data->args[1][0] == '-')
	{
		msg = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		msg = ": can't cd to ";
		len_id = _strlen(data->args[1]);
	}
	length = _strlen(data->av[0]) + _strlen(data->args[0]);
	length += _strlen(ver_str) + _strlen(msg) + len_id + 5;
	error = malloc(sizeof(char) * (length + 1));

	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}
	error = cderror(data, msg, error, ver_str);
	free(ver_str);
	return (error);
}

/**
 * not_found- command not found
 * @data: data structure
 * Return: message
 */
char *not_found(myshell *data)
{
	int length;
	char *error;
	char *ver_str;

	ver_str = rev_atoi(data->counter);
	length = _strlen(data->av[0]) + _strlen(ver_str);
	length += _strlen(data->args[0]) + 16;
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
	_strcat(error, ": not found\n");
	_strcat(error, "\0");
	free(ver_str);
	return (error);
}

/**
 * cant_exit- error in exit
 * @data: data structure
 * Return: the message
 */
char *cant_exit(myshell *data)
{
	int length;
	char *error;
	char *ver_str;

	ver_str = rev_atoi(data->counter);
	length = _strlen(data->av[0]) + _strlen(ver_str);
	length += _strlen(data->args[0]) + _strlen(data->args[1]) + 23;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, data->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, data->args[0]);
	_strcat(error, ": Illegal number: ");
	_strcat(error, data->args[1]);
	_strcat(error, "\n\0");
	free(ver_str);
	return (error);
}
