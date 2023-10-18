#include "main.h"

/**
 * uncomment- removes comments
 * @in: input string
 * Return: new string
 */
char *uncomment(char *in)
{
	int i, up_to;

	up_to = 0;
	for (i = 0; in[i]; i++)
	{
		if (in[i] == '#')
		{
			if (i == 0)
			{
				free(in);
				return (NULL);
			}
			if (in[i - 1] == ' ' || in[i - 1] == '\t' || in[i - 1] == ';')
				up_to = i;
		}
	}
	if (up_to != 0)
	{
		in = _realloc(in, i, up_to + 1);
		in[up_to] = '\0';
	}
	return (in);
}

/**
 * my_loop- loops the shell
 * @data: the data structure
 * Return: void
 */
void my_loop(myshell *data)
{
	int loop, i_eof;
	char *input;

	loop = 1;
	while (loop == 1)
	{
		write(STDIN_FILENO, "simpleshell$ ", 13);
		input = read_line(&i_eof);
		if (i_eof != -1)
		{
			input = uncomment(input);
			if (input == NULL)
				continue;
			if (syntax_error(data, input) == 1)
			{
				data->status = 2;
				free(input);
				continue;
			}
			input = rep_var(input, data);
			loop = split_commands(data, input);
			data->counter += 1;
			free(input);
		}
		else
		{
			loop = 0;
			free(input);
		}
	}
}
