#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int executing(char **argv);


/*String functions*/
int _strlen(const char *s);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);
char *_strcpy(char *dest, const char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(const char *s);
char *_strtok(char s[], const char *delim);
char cmp_char(char s[], const char *delim);

#endif
