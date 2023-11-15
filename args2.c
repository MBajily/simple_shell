#include "shell.h"


/**
 * exit_checker - handle arguments for
 * the built-in exit
 *
 * @index: index
 * @input: input
 * @args: arguments
 */
void exit_checker(char ***args, char **input, int index)
{
	int sts = 128;

	if (args && *args)
	{
		if (_strcmp((*args)[0], "exit") == 0)
		{
			if (index > 1)
			{
				sts = 130;
			}
			if (!(*args)[1])
			{
				free(*input);
				free_array(*args);
				exit(sts % 128);
			}
			if (is_letter((*args)[1]) || atoi((*args)[1]) < 0)
			{
				sts = 130;
				fprintf(stderr, "./hsh: 1: exit: Illegal number: %s\n", (*args)[1]);
			}
			if ((*args)[1] && is_digit((*args)[1]))
			{
				sts = atoi((*args)[1]);
				if (sts == 1000)
				{
					free(*input);
					free_array(*args);
					exit(232);
				}
			}
			free(*input);
			free_array(*args);
			exit(sts % 128);
		}
	}
}


/**
 * exit_message - handle arguments for
 * the built-in exit
 *
 * @index: index
 * @input: input
 * @args: arguments
 */
void exit_message(char ***args, char **input, int *index)
{
	if (*args != NULL)
	{
		fprintf(stderr, "./hsh: %d: %s: not found\n", *index, *args[0]);
	}
	free(*input);
	free_array(*args);
	exit(127);
}


/**
 * is_digit - Check if the str is digit
 *
 * @str: the string
 *
 * Return: 0 or 1
 */
int is_digit(char *str)
{
	int i;

	if (str == NULL)
	{
		return (0);
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			return (0);
		}
	}
	return (1);
}

/**
 * is_letter - Check if the str is a letter
 *
 * @str: the string
 *
 * Return: 0 if Null, 1 if not Null
 */
int is_letter(char *str)
{
	int i;

	if (str == NULL)
	{
		return (0);
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] < '0' || str[i] > '9'))
		{
			return (1);
		}
	}
	return (0);
}
