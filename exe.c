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
	pid_t pid_;
	int sts;

	(void)input;
	pid_ = fork();
	if (pid_ < 0)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid_ == 0)
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
		waitpid(pid_, &sts, 0);
		free_array(args);
	}
	return (sts);
}
