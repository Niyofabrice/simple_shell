#include "main.h"

/**
 * is_cdir- current directory
 * @path: the path
 * @i: pointer to index
 * Return: 1 if foud or 0
 */
int is_cdir(char *path, int *i)
{
	if (path[*i] == ':')
		return (1);
	while (path[*i] != ':' && path[*i])
	{
		*i += 1;
	}
	if (path[*i])
		*i += 1;
	return (0);
}

/**
 * _which- which implementation
 * @cmd: command
 * @_environ: environment
 * Return: location of com
 */
char *_which(char *cmd, char **_environ)
{
	char *path, *ptr_path, *token_path, *dir;
	int len_dir, len_cmd, i;
	struct stat st;

	path = _getenv("PATH", _environ);
	if (path)
	{
		ptr_path = _strdup(path);
		len_cmd = _strlen(cmd);
		token_path = _strtok(ptr_path, ":");
		i = 0;
		while (token_path != NULL)
		{
			if (is_cdir(path, &i))
				if (stat(cmd, &st) == 0)
					return (cmd);
			len_dir = _strlen(token_path);
			dir = malloc(len_dir + len_cmd + 2);
			_strcpy(dir, token_path);
			_strcat(dir, "/");
			_strcat(dir, cmd);
			_strcat(dir, "\0");
			if (stat(dir, &st) == 0)
			{
				free(ptr_path);
				return (dir);
			}
			free(dir);
			token_path = _strtok(NULL, ":");
		}
		free(ptr_path);
		if (stat(cmd, &st) == 0)
			return (cmd);
		return (NULL);
	}
	if (cmd[0] == '/')
		if (stat(cmd, &st) == 0)
			return (cmd);
	return (NULL);
}

/**
 * is_executable- is the path executable
 * @data: the data structure
 * Return: positive if yes, or 0
 */
int is_executable(myshell *data)
{
	struct stat st;
	int i;
	char *input;

	input = data->args[0];
	for (i = 0; input[i]; i++)
	{
		if (input[i] == '.')
		{
			if (input[i + 1] == '.')
				return (0);
			if (input[i + 1] == '/')
				continue;
			else
				break;
		}
		else if (input[i] == '/' && i != 0)
		{
			if (input[i + 1] == '.')
				continue;
			i++;
			break;
		}
		else
			break;
	}
	if (i == 0)
		return (0);
	if (stat(input + i, &st) == 0)
	{
		return (i);
	}
	find_error(data, 127);
	return (-1);
}

/**
 * com_error-  for permission
 * @dir: directory
 * @data: the data structure
 * Return: 1 if error, or 0
 */
int com_error(char *dir, myshell *data)
{
	if (dir == NULL)
	{
		find_error(data, 127);
		return (1);
	}
	if (_strcmp(data->args[0], dir) != 0)
	{
		if (access(dir, X_OK) == -1)
		{
			find_error(data, 126);
			free(dir);
			return (1);
		}
		free(dir);
	}
	else
	{
		if (access(data->args[0], X_OK) == -1)
		{
			find_error(data, 126);
			return (1);
		}
	}
	return (0);
}

/**
 * handle_com- cmd executtion
 * @data: the data structure
 * Return: 1 on success
 */
int handle_com(myshell *data)
{
	pid_t pd;
	pid_t wpd;
	int state;
	int exec;
	char *dir;
	(void) wpd;

	exec = is_executable(data);
	if (exec == -1)
		return (1);
	if (exec == 0)
	{
		dir = _which(data->args[0], data->_environ);
		if (com_error(dir, data) == 1)
			return (1);
	}

	pd = fork();
	if (pd == 0)
	{
		if (exec == 0)
			dir = _which(data->args[0], data->_environ);
		else
			dir = data->args[0];
		execve(dir + exec, data->args, data->_environ);
	}
	else if (pd < 0)
	{
		perror(data->av[0]);
		return (1);
	}
	else
	{
		do {
			wpd = waitpid(pd, &state, WUNTRACED);
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));
	}

	data->status = state / 256;
	return (1);
}
