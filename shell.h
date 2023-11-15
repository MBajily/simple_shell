#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/wait.h>


void free_array(char **arr); /* Done */
void free_c(char ***args, char **input, char *dir, int alert); /* Done */

char *_str_duplicate(const char *str); /* Done */
size_t _str_length(const char *str); /* Done */
void _str_copy(char *dest, const char *src); /* Done */
void _strcat(char *dest, const char *src); /* Done */
int _strcmp(const char *str1, const char *str2); /* Done */

int _get_line(char **input, size_t *length); /* Done */
char **parse_args(char *input); /* Done */
int empty_checker(char *input); /* Done */
int cd_checker(char ***args, char **input, int index); /* Done */
int path_checker(char **args); /* Done */

void exit_checker(char ***args, char **input, int index); /* Done */
void exit_message(char ***args, char **input, int *index); /* Done */

int is_digit(char *str); /* Done */
int is_letter(char *str); /* Done */

int execution(char **args, char *input); /* Done */

#endif
