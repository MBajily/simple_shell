#include "shell.h"


int main(void)
{
	size_t length;
	ssize_t input_length;
	char *input, **args;
	int counter, index;

	length = 0;
	*input = NULL;
	counter = 0;
	while (1)
	{
		counter++;
		index = 0;
		while ((input_length = _get_line(&input, &length)) != -1)
		{
			index++;
			if (input_length == 0)
			{
				continue;
			}
			if (empty_checker(input))
			{
				continue;
			}
			args = parse_args(input);
			if (!args)
			{
				continue;
			}
			exit_checker(&args, &input, index);
			if (cd_checker(&args, &input, index) != -1)
			{
				continue;
			}
			if (!path_checker(args))
			{
				exit_message(&args, &input, &counter);
			}
			execution(args, input);
		}
	}
	return (0);
}
