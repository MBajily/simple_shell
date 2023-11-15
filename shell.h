#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/wait.h>


/* free_array - Function to free the memory
allocated for an array of strings */
void free_array(char **arr);
/* free_c - Function to free the memory allocated
for various arrays and strings */
void free_c(char ***args, char **input, char *dir, int alert);

/* *_str_duplicate - Function to duplicate
a given string */
char *_str_duplicate(const char *str);
/* _str_length - Function to calculate
the length of a string */
size_t _str_length(const char *str);
/* _str_copy - Function to copy the contents
of one string to another */
void _str_copy(char *dest, const char *src);
/* _strcat - Function to concatenate the contents
of two strings */
void _strcat(char *dest, const char *src);
/* _strcmp - Function to compare two strings */
int _strcmp(const char *str1, const char *str2);

/* _get_line - Function to read a line of input
from the user */
int _get_line(char **input, size_t *length);
/* **parse_args - Function to parse the command-line
arguments from a string */
char **parse_args(char *input);
/* empty_checker - Function to check if a given input
string is empty */
int empty_checker(char *input);
/* cd_checker - Function to check if the input command
is for changing the directory */
int cd_checker(char ***args, char **input, int index);
/* path_checker - Function to check if the input command
requires a path resolution */
int path_checker(char **args);

/* exit_checker - Function to check if the input command
is for exiting the shell */
void exit_checker(char ***args, char **input, int index);
/* exit_message - Function to display an exit message and
clean up resources before exiting the shell */
void exit_message(char ***args, char **input, int *index);

/* is_digit - Function to check if a given string represents
a digit */
int is_digit(char *str);
/* is_letter - Function to check if a given string represents
a letter */
int is_letter(char *str);

/* execution - Function to execute a command with the given
arguments and input */
int execution(char **args, char *input);

#endif

