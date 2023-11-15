#include "shell.h"


/**
 * _get_line - Read one line of the standar input
 *
 * @input: input
 * @length: input length
 *
 * Return: input length
 */
int _get_line(char **input, size_t *length)
{
	ssize_t the_length;

	if (isatty(STDIN_FILENO))
	{
		write(1, "$ ", 2);
	}
	the_length = getline(input, length, stdin);
	if ((int)the_length == -1)
	{
		free(*input), *input = NULL;
		exit(0);
	}
	if (the_length > 0)
	{
		if ((*input)[the_length - 1] == '\n')
		{
			(*input)[the_length - 1] = '\0';
		}
	}
	return (*length);
}


/**
 * empty_checker - Check if is empty
 *
 * @input: input
 *
 * Return: 1 or 0
 */
int empty_checker(char *input)
{
	int i = 0;

	while (input[i])
	{
		if (input[i] != ' ')
		{
			return (0);
		}
		i++;
	}
	return (1);
}


/**
 * **parse_args - Handle command lines with arguments
 *
 * @input: input
 *
 * Return: Null or args
 */
char **parse_args(char *input)
{
	int i, count;
	char *arg, *tmp, **args, d[] = " \n\t";

	i = 0;
	count = 0;
	*arg = NULL;
	*tmp = NULL;
	**args = NULL;
	if (!input)
	{
		return (NULL);
	}
	tmp = _str_duplicate(input);
	arg = strtok(tmp, d);
	while (arg != NULL)
	{
		count++;
		arg = strtok(NULL, d);
	}
	free(tmp), tmp = NULL;
	args = (char **)malloc(sizeof(char *) * (count + 1));
	if (args == NULL)
	{
		free(input), input = NULL;
		return (NULL);
	}
	arg = strtok(input, d);
	while (arg)
	{
		args[i++] = _str_duplicate(arg);
		arg = strtok(NULL, d);
	}
	args[i] = NULL;
	return (args);
}


/**
 * cd_checker - cd checker
 *
 * @index: index
 * @input: input
 * @args: arguments
 *
 * Return: status
 */
int cd_checker(char ***args, char **input, int index)
{
	char *dir, *currentDir;
	int sts, alert;

	sts = -1;
	alert = 0;
	if (args && (*args) && (*args)[0] && _strcmp((*args)[0], "cd") != 0)
		return (sts);
	dir = (*args)[1];
	if (dir == NULL)
	{
		dir = getenv("HOME");
		if (dir == NULL)
			dir = getcwd(NULL, 0), alert = 1;
	}
	else if (_strcmp(dir, "-") == 0)
	{
		dir = getenv("OLDPWD");
		if (dir == NULL)
			dir = getcwd(NULL, 0), alert = 1;
		printf("%s\n", dir);
	}
	currentDir = getcwd(NULL, 0);
	if (currentDir == NULL)
	{
		perror("cd"), free_c(args, input, dir, alert);
		return (0);
	}
	if (chdir(dir) == 0)
	{
		setenv("OLDPWD", currentDir, 1);
		setenv("PWD", dir, 1), sts = 1;
	}
	else
	{
		fprintf(stderr, "./hsh: %d: %s: can't cd to %s\n",
				index, (*args)[0], (*args)[1]);
		sts = 0;
	}
	free(currentDir), free_c(args, input, dir, alert);
	return (sts);
}


/**
 * path_checker - Handle the PATH
 *
 * @index: index
 * @input: input
 * @args: arguments
 *
 * Return: status
 */
int path_checker(char **args)
{
	char *dir, *path, *copied_path;
	char ppath[1024];

	if (args[1])
	{
		if (_strcmp(args[0], "hbtn_ls") == 0 && _strcmp(args[1], "/var") == 0)
		{
			return (1);
		}
	}
	if (_strcmp(args[0], "hbtn_ls") == 0)
	{
		return (0);
	}
	if (access(args[0], X_OK) == 0)
	{
		return (1);
	}
	if (_strcmp(args[0], "env") == 0)
	{}
	{
		free(args[0]);
		args[0] = _str_duplicate("/usr/bin/env");
		return (1);
	}
	path = getenv("PATH");
	if (path == NULL)
	{
		return (0);
	}
	copied_path = _str_duplicate(path);
	if (copied_path == NULL)
	{
		perror("strdup");
		return (0);
	}
	dir = strtok(copied_path, ":");
	while (dir != NULL)
	{
		_str_copy(ppath, dir), _strcat(ppath, "/");
		_strcat(ppath, args[0]);
		if (access(ppath, X_OK) == 0)
		{
			free(args[0]);
			args[0] = _str_duplicate(ppath), free(copied_path);
			return (1);
		}
		dir = strtok(NULL, ":");
	}
	free(copied_path);
	return (0);
}
