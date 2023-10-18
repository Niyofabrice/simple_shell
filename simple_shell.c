#include "shell.h"

int executing(char **argv);

/**
 * main - function that performes basic shell commands
 * @argc: number of arguments passed to the file
 * @argv: array of arguments passed to the file
 * Return: 0 on success, -1 otherwise
 */

int main(int argc, char **argv)
{
	size_t size = 0;
	ssize_t nchar_read;
	bool from_pipe = true;
	char *line_copy, *line, *token, *delim;
	int count, i, j;
	pid_t process;
	(void)argc;

	line = NULL;

	while (1 && from_pipe)
	{
		if (!isatty(0))
		{
			from_pipe = false;
		}
		else
		{
			write(1, "($) ", 5);
		}

		nchar_read = getline(&line, &size, stdin);

		if (nchar_read == -1)
		{
			if (nchar_read == EOF)
			{
				write(1, "\n", 3);
				return (0);
			}
			perror("Error");
			return (-1);
		}

		line_copy = malloc(sizeof(char *) * nchar_read);
		if (line_copy == NULL)
		{
			perror("Memory Allocation Error");
			return (-1);
		}

		_strcpy(line_copy, line);

		delim = " \n";

		token = strtok(line, delim);

		count = 0;
		while (token != NULL)
		{
			token = strtok(NULL, delim);
			count++;
		}
		count++;

		argv = malloc(sizeof(char *) * count);
		if (argv == NULL)
		{
			perror("Memory Allocation Error");
			return (-1);
		}

		token = strtok(line_copy, delim);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * (strlen(token) * 2));
			if (argv[i] == NULL)
			{
				perror("Memory Allocation Error");
				return (-1);
			}

			_strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		process = fork();

		if (process == -1)
		{
			perror("Error");
			return (-1);
		}
		if (process == 0)
		{
			if (execve(argv[0], argv, NULL))
			{
				perror("./shell");
				exit(0);
			}
		}
		else
		{
			int status;

			wait(&status);
		}


		for (j = 0; j < count; j++)
		{
			free(argv[j]);
		}

		free(argv);
		free(line_copy);

	}
	return (0);
}
