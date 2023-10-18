#include "main.h"

/**
 * cmp_env_name- find environment name
 * @nenv: name of variable
 * @name: name passed
 * Return: positive if found, or 0
 */
int cmp_env_name(const char *nenv, const char *name)
{
	int i;

	for (i = 0; nenv[i] != '='; i++)
	{
		if (nenv[i] != name[i])
		{
			return (0);
		}
	}
	return (i + 1);
}

/**
 * _getenv- getenv custom
 * @name: name of variable
 * @_environ: the environment
 * Return: value of environment
 */
char *_getenv(const char *name, char **_environ)
{
	char *ptr_env;
	int i, mov;

	ptr_env = NULL;
	mov = 0;
	for (i = 0; _environ[i]; i++)
	{
		mov = cmp_env_name(_environ[i], name);
		if (mov)
		{
			ptr_env = _environ[i];
			break;
		}
	}
	return (ptr_env + mov);
}

/**
 * _env- prints the environment
 * @data: the datastructure
 * Return: 1 on success
 */
int _env(myshell *data)
{
	int i, j;

	for (i = 0; data->_environ[i]; i++)
	{
		for (j = 0; data->_environ[i][j]; j++)
			;
		write(STDOUT_FILENO, data->_environ[i], j++);
		write(STDOUT_FILENO, "\n", 1);
	}
	data->status = 0;

	return (1);
}
