#include "main.h"

/**
 * add_separator- add separators to list
 * @head: head of list
 * @sep: separator
 * Return: head address
 */
sep_list *add_separator(sep_list **head, char sep)
{
	sep_list *new, *temp;

	new = malloc(sizeof(sep_list));
	if (new == NULL)
		return (NULL);
	new->separator = sep;
	new->next = NULL;
	temp = *head;
	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
	return (*head);
}

/**
 * free_separator- frees the list
 * @head: head of the list
 */
void free_separator(sep_list **head)
{
	sep_list *temp;
	sep_list *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}

/**
 * add_line- add on the list
 * @head: head of the list
 * @line: the command line
 * Return: head address
 */
line_list *add_line(line_list **head, char *line)
{
	line_list *new, *temp;

	new = malloc(sizeof(line_list));
	if (new == NULL)
		return (NULL);
	new->line = line;
	new->next = NULL;
	temp = *head;
	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
	return (*head);
}

/**
 * free_line- frees the list
 * @head: head of the list
 */
void free_line(line_list **head)
{
	line_list *temp;
	line_list *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}
