#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/wait.h>


extern char **environ;


void free_array(char **arr);
void free_c(char ***args, char **input, char *dir, int alert);


char *_str_duplicate(const char *str);
size_t _str_length(const char *str);
void _str_copy(char *dest, const char *src);
void _strcat(char *dest, const char *src);
int _strcmp(const char *str1, const char *str2);


int _get_line(char **input, size_t *length);
char **parse_args(char *input);
int empty_checker(char *input);
int cd_checker(char ***args, char **input, int index);
int path_checker(char **args);

void exit_checker(char ***args, char **input, int index);
void exit_message(char ***args, char **input, int *index);

int is_digit(char *str);
int is_letter(char *str);


int execution(char **args, char *input);


#endif

