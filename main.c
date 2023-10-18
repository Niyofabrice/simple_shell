#include "main.h"

/**
 * _free- data structure
 * @data: the data structure
 */
void _free(myshell *data)
{
	unsigned int i;

	for (i = 0; data->_environ[i]; i++)
	{
		free(data->_environ[i]);
	}
	free(data->_environ);
	free(data->pid);
}

/**
 * _set- initialization
 * @data: the data structure
 * @av: vector of arguments
 */
void _set(myshell *data, char **av)
{
	unsigned int i;

	data->av = av;
	data->input = NULL;
	data->args = NULL;
	data->status = 0;
	data->counter = 1;

	for (i = 0; environ[i]; i++)
		;
	data->_environ = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		data->_environ[i] = _strdup(environ[i]);
	}

	data->_environ[i] = NULL;
	data->pid = rev_atoi(getpid());
}

/**
 * main- Entry point
 * @ac: number of arguments
 * @av: vector of arguments
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	myshell data;
	(void) ac;

	signal(SIGINT, get_sigint);
	_set(&data, av);
	my_loop(&data);
	_free(&data);
	if (data.status < 0)
		return (255);
	return (data.status);
}
