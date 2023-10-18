#include "main.h"

/**
 * copy_info- copies args passed
 * @name: the name
 * @value: the value
 * Return: new environment or alias
 */

char *copy_info(char *name, char *value)
{
	char *new;
	int len_name, len_value, len;

	len_name = _strlen(name);
	len_value = _strlen(value);
	len = len_name + len_value + 2;
	new = malloc(sizeof(char) * len);
	_strcpy(new, name);
	_strcat(new, "=");
	_strcat(new, value);
	_strcat(new, "\0");

	return (new);
}

/**
 * set_env- setenv custom
 * @name: name of variable
 * @value: the value
 * @data: the data structure
 */
void set_env(char *name, char *value, myshell *data)
{
	int i;
	char *var_env, *name_env;

	for (i = 0; data->_environ[i]; i++)
	{
		var_env = _strdup(data->_environ[i]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, name) == 0)
		{
			free(data->_environ[i]);
			data->_environ[i] = copy_info(name_env, value);
			free(var_env);
			return;
		}
		free(var_env);
	}
	data->_environ = _reallocdp(data->_environ, i, sizeof(char *) * (i + 2));
	data->_environ[i] = copy_info(name, value);
	data->_environ[i + 1] = NULL;
}

/**
 * _setenv- setenv builtin
 * @data: the data structure
 * Return: 1 on success
 */
int _setenv(myshell *data)
{
	if (data->args[1] == NULL || data->args[2] == NULL)
	{
		find_error(data, -1);
		return (1);
	}
	set_env(data->args[1], data->args[2], data);
	return (1);
}

/**
 * _unsetenv- unsetenv builtin
 * @data: the data structure
 * Return: 1 on success
 */
int _unsetenv(myshell *data)
{
	char **realloc_environ;
	char *var_env, *name_env;
	int i, j, k;

	if (data->args[1] == NULL)
	{
		find_error(data, -1);
		return (1);
	}
	k = -1;
	for (i = 0; data->_environ[i]; i++)
	{
		var_env = _strdup(data->_environ[i]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, data->args[1]) == 0)
		{
			k = i;
		}
		free(var_env);
	}
	if (k == -1)
	{
		find_error(data, -1);
		return (1);
	}
	realloc_environ = malloc(sizeof(char *) * i);
	for (i = j = 0; data->_environ[i]; i++)
	{
		if (i != k)
		{
			realloc_environ[j] = data->_environ[i];
			j++;
		}
	}
	realloc_environ[j] = NULL;
	free(data->_environ[k]);
	free(data->_environ);
	data->_environ = realloc_environ;
	return (1);
}
