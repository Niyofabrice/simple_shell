#include "main.h"

/**
 * find_help- find the help function
 * @data: the data structure
 * Return: 1 on success
 */
int find_help(myshell *data)
{
	if (data->args[1] == 0)
		help();
	else if (_strcmp(data->args[1], "setenv") == 0)
		help_Set_env();
	else if (_strcmp(data->args[1], "env") == 0)
		help_env();
	else if (_strcmp(data->args[1], "unsetenv") == 0)
		help_Unset();
	else if (_strcmp(data->args[1], "help") == 0)
		help_Help();
	else if (_strcmp(data->args[1], "exit") == 0)
		help_exit();
	else if (_strcmp(data->args[1], "cd") == 0)
		help_cd();
	else if (_strcmp(data->args[1], "alias") == 0)
		help_alias();
	else
		write(STDERR_FILENO, data->args[0],
				_strlen(data->args[0]));
	data->status = 0;
	return (1);
}
