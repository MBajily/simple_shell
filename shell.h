#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/wait.h>

extern char **environ;


/**
 * free_array - Frees the memory for directories
 *
 * @arr: the array
 *
 * Return: Null
 */
void free_array(char **arr);

/**
 * free_c - Frees the memory for com
 *
 * @dir: the directory
 * @input: input
 * @args: arguments
 * @alert: an allert
 *
 * Return: Null
 */
void free_c(char ***args, char **input, char *dir, int alert);

/**
 * *_str_duplicate - copy the string
 *
 * @str: string
 *
 * Return: new_string, Null if the str is null,
 */
char *_str_duplicate(const char *str);

/**
 * _str_length - Frees the memory for com
 *
 * @str: string
 *
 * Return: the length of string
 */
size_t _str_length(const char *str);

/**
 * _str_copy - copy the string
 *
 * @dest: destination direct
 * @src: source direct
 */
void _str_copy(char *dest, const char *src);

/**
 * _strcat - Concatenates two strings
 *
 * @dest: destination
 * @src: source
 */
void _strcat(char *dest, const char *src);

/**
 * _strcmp - Compares two strings
 *
 * @str1: first string
 * @str2: second string
 *
 * Return: return the deffrence number
 */
int _strcmp(const char *str1, const char *str2);

/**
 * _get_line - Read one line of the standar input
 *
 * @input: input
 * @length: input length
 *
 * Return: input length
 */
int _get_line(char **input, size_t *length);

/**
 * **parse_args - Handle command lines with arguments
 *
 * @input: input
 *
 * Return: Null or args
 */
char **parse_args(char *input);

/**
 * empty_checker - Check if is empty
 *
 * @input: input
 *
 * Return: 1 or 0
 */
int empty_checker(char *input);

/**
 * cd_checker - cd checker
 *
 * @index: index
 * @input: input
 * @args: arguments
 *
 * Return: status
 */
int cd_checker(char ***args, char **input, int index);

/**
 * path_checker - Handle the PATH
 *
 * @args: arguments
 *
 * Return: status
 */
int path_checker(char **args);

/**
 * exit_checker - handle arguments
 * for the built-in exit
 *
 * @index: index
 * @input: input
 * @args: arguments
 */
void exit_checker(char ***args, char **input, int index);

/**
 * exit_message - handle arguments
 * for the built-in exit
 *
 * @index: index
 * @input: input
 * @args: arguments
 */
void exit_message(char ***args, char **input, int *index);

/**
 * is_digit - Check if the str is digit
 *
 * @str: the string
 *
 * Return: 0 or 1
 */
int is_digit(char *str);

/**
 * is_letter - Check if the str is a letter
 *
 * @str: the string
 *
 * Return: 0 if Null, 1 if not Null
 */
int is_letter(char *str);

/**
 * execution - Execute a command with
 * its entire path
 *
 * @args: the arguments
 * @input: input
 *
 * Return: status
 */
int execution(char **args, char *input);

#endif

