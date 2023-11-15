#include "shell.h"


/**
 * free_array - Frees the memory for directories
 *
 * @arr: the array
 *
 * Return: Null
 */
void free_array(char **arr)
{
	int i, r;

	i = 0;
	r = 0;
	if (arr == NULL)
	{
		return;
	}
	while (arr[r])
	{
		r++;
	}
	for (i = 0; i < r; i++)
	{
		free(arr[i]);
	}
	free(arr);
}


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
void free_c(char ***args, char **input, char *dir, int alert)
{
	(void)input;

	if (alert)
	{
		free(dir);
	}
	free_array(*args);
}


/**
 * _str_length - Frees the memory for com
 *
 * @str: string
 *
 * Return: the length of string
 */
size_t _str_length(const char *str)
{
	size_t len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}


/**
 * _str_copy - copy the string
 *
 * @dest: destination direct
 * @src: source direct
 */
void _str_copy(char *dest, const char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}


/**
 * *_str_duplicate - copy the string
 *
 * @str: string
 *
 * Return: new_string, Null if the str is null,
 */
char *_str_duplicate(const char *str)
{
	size_t len;
	char *new_string;

	len = _str_length(str) + 1;
	new_string = (char *)malloc(len);
	if (new_string == NULL)
	{
		return (NULL);
	}
	_str_copy(new_string, str);
	return (new_string);
}
