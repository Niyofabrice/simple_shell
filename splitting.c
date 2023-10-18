#include "main.h"

/**
 * dont_print- to not print | and &
 * @input: input
 * @bool: type of swap
 * Return: new string
 */
char *dont_print(char *input, int bool)
{
	int i;

	if (bool == 0)
	{
		for (i = 0; input[i]; i++)
		{
			if (input[i] == '|')
			{
				if (input[i + 1] != '|')
					input[i] = 16;
				else
					i++;
			}
			if (input[i] == '&')
			{
				if (input[i + 1] != '&')
					input[i] = 12;
				else
					i++;
			}
		}
	}
	else
	{
		for (i = 0; input[i]; i++)
		{
			input[i] = (input[i] == 16 ? '|' : input[i]);
			input[i] = (input[i] == 12 ? '&' : input[i]);
		}
	}
	return (input);
}

/**
 * add_nodes- separators and command lines
 * @head_s: head of sep
 * @head_l: head of command lines
 * @input: input
 * Return: void
 */
void add_nodes(sep_list **head_s, line_list **head_l, char *input)
{
	int i;
	char *line;

	input = dont_print(input, 0);

	for (i = 0; input[i]; i++)
	{
		if (input[i] == ';')
			add_separator(head_s, input[i]);
		if (input[i] == '|' || input[i] == '&')
		{
			add_separator(head_s, input[i]);
			i++;
		}
	}
	line = _strtok(input, ";|&");
	do {
		line = dont_print(line, 1);
		add_line(head_l, line);
		line = _strtok(NULL, ";|&");
	} while (line != NULL);
}

/**
 * go_next- the next command
 * @list_s: separator list
 * @list_l: line list
 * @data: the data structure
 * Return: void
 */
void go_next(sep_list **list_s, line_list **list_l, myshell *data)
{
	int loop_sep;
	sep_list *ls_s;
	line_list *ls_l;

	loop_sep = 1;
	ls_s = *list_s;
	ls_l = *list_l;

	while (ls_s != NULL && loop_sep)
	{
		if (data->status == 0)
		{
			if (ls_s->separator == '&' || ls_s->separator == ';')
				loop_sep = 0;
			if (ls_s->separator == '|')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		else
		{
			if (ls_s->separator == '|' || ls_s->separator == ';')
				loop_sep = 0;
			if (ls_s->separator == '&')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		if (ls_s != NULL && !loop_sep)
			ls_s = ls_s->next;
	}
	*list_s = ls_s;
	*list_l = ls_l;
}

/**
 * split_commands- split the commands
 * @data: the data structure
 * @input: input string
 * Return: 1 on success, 0 to exit
 */
int split_commands(myshell *data, char *input)
{
	sep_list *head_s, *list_s;
	line_list *head_l, *list_l;
	int loop;

	head_s = NULL;
	head_l = NULL;

	add_nodes(&head_s, &head_l, input);
	list_s = head_s;
	list_l = head_l;

	while (list_l != NULL)
	{
		data->input = list_l->line;
		data->args = split_line(data->input);
		loop = execute(data);
		free(data->args);
		if (loop == 0)
			break;
		go_next(&list_s, &list_l, data);
		if (list_l != NULL)
			list_l = list_l->next;
	}

	free_separator(&head_s);
	free_line(&head_l);
	if (loop == 0)
		return (0);
	return (1);
}

/**
 * split_line- split the line into args
 * @input: input
 * Return: pointer to args
 */
char **split_line(char *input)
{
	size_t bsize;
	size_t i;
	char **tokens;
	char *token;

	bsize = TOK_BUFSIZE;
	tokens = malloc(sizeof(char *) * (bsize));
	if (tokens == NULL)
	{
		write(STDERR_FILENO, ": allocation error\n", 18);
		exit(EXIT_FAILURE);
	}
	token = _strtok(input, TOK_DELIM);
	tokens[0] = token;

	for (i = 1; token != NULL; i++)
	{
		if (i == bsize)
		{
			bsize += TOK_BUFSIZE;
			tokens = _reallocdp(tokens, i, sizeof(char *) * bsize);
			if (tokens == NULL)
			{
				write(STDERR_FILENO, ": allocation error\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		token = _strtok(NULL, TOK_DELIM);
		tokens[i] = token;
	}
	return (tokens);
}
