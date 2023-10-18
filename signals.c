#include "main.h"

/**
 * get_sigint- crtl + c
 * @sig: signal
 */
void get_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\nsimpleshell$ ", 13);
}
