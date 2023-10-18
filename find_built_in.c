#include "main.h"

/**
 * findbuiltin- find the builtin
 * @cmd: the command
 * Return: pointer to builtin
 */
int (*findbuiltin(char *cmd))(myshell *)
{
	builtin_t builtin[] = {
		{ "env", _env },
		{ "exit", _exit_ },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv},
		{ "cd", findcd},
		{ "help", find_help},
		{ NULL, NULL}
	};
	int i;

	for (i = 0; builtin[i].name; i++)
	{
		if (_strcmp(builtin[i].name, cmd) == 0)
			break;
	}
	return (builtin[i].f);
}
