#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/wait.h>


// Function to free the memory allocated for an array of strings
void free_array(char **arr);
// Function to free the memory allocated for various arrays and strings
void free_c(char ***args, char **input, char *dir, int alert);

// Function to duplicate a given string
char *_str_duplicate(const char *str);
// Function to calculate the length of a string
size_t _str_length(const char *str);
// Function to copy the contents of one string to another
void _str_copy(char *dest, const char *src);
// Function to concatenate the contents of two strings
void _strcat(char *dest, const char *src);
// Function to compare two strings
int _strcmp(const char *str1, const char *str2);

// Function to read a line of input from the user
int _get_line(char **input, size_t *length);
// Function to parse the command-line arguments from a string
char **parse_args(char *input);
// Function to check if a given input string is empty
int empty_checker(char *input);
// Function to check if the input command is for changing the directory
int cd_checker(char ***args, char **input, int index);
// Function to check if the input command requires a path resolution
int path_checker(char **args);

// Function to check if the input command is for exiting the shell
void exit_checker(char ***args, char **input, int index);
// Function to display an exit message and clean up resources before exiting the shell
void exit_message(char ***args, char **input, int *index);

// Function to check if a given string represents a digit
int is_digit(char *str);
// Function to check if a given string represents a letter
int is_letter(char *str);

// Function to execute a command with the given arguments and input
int execution(char **args, char *input);

#endif

