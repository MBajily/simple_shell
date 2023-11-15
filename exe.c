#include "shell.h"



int execution(char **args, char *input)
{
	pid_t _pid;
	int sts;

	(void)input;
	_pid = fork();
	if (_pid < 0)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (_pid == 0)
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
		waitpid(_pid, &sts, 0);
		free_array(args);
	}
	return (sts);
}
