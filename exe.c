#include "shell.h"


/**
 * execution - Concatenates two strings
 *
 * @args: the arguments
 * @input: input
 *
 * Return: status
 */
int execution(char **args, char *input)
{
	pid_t the_pid;
	int sts;

	(void)input;
	the_pid = fork();
	if (the_pid < 0)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (the_pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			free_array(args);
			free(input);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(the_pid, &sts, 0);
		free_array(args);
	}
	return (sts);
}
