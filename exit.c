#include "main.h"

/**
 * _exit_- exits the shell
 * @data: the data structure
 * Return: 0 on success
 */
int _exit_(myshell *data)
{
	unsigned int ustatus;
	int is_digit;
	int str_len;
	int big_number;

	if (data->args[1] != NULL)
	{
		ustatus = _atoi(data->args[1]);
		is_digit = _isdigit(data->args[1]);
		str_len = _strlen(data->args[1]);
		big_number = ustatus > (unsigned int)INT_MAX;
		if (!is_digit || str_len > 10 || big_number)
		{
			finderror(data, 2);
			data->status = 2;
			return (1);
		}
		data->status = (ustatus % 256);
	}
	return (0);
}
