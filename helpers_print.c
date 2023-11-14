#include "main.h"

/**
 * _print - writes array of chars in std output
 * @string: pointer to array of chars
 * Return: num of bytes or .
 * -1 if error, errno is set
 */
int _print(char *string)
{
	return (write(STDOUT_FILENO, string, str_length(string)));
}
/**
 * _prints - writes array of chars in std error
 * @string: pointer to array of chars
 * Return: num of bytes or .
 * -1 if error, errno is set
 */
int _prints(char *string)
{
	return (write(STDERR_FILENO, string, str_length(string)));
}
/**
 * _print_error - writes array of chars in std error
 * @data:  struct for program data
 * @errorcode: error code to print
 * Return: num of bytes or .
 * -1 if error, errno is set
 */
int _print_error(int errorcode, data_of_program *data)
{
	char n_as_string[10] = {'\0'};

	long_to_string((long) data->exec_counter, n_as_string, 10);

	if (errorcode == 2 || errorcode == 3)
	{
		_prints(data->program_name);
		_prints(": ");
		_prints(n_as_string);
		_prints(": ");
		_prints(data->tokens[0]);
		if (errorcode == 2)
			_prints(": Illegal number: ");
		else
			_prints(": can't cd to ");
		_prints(data->tokens[1]);
		_prints("\n");
	}
	else if (errorcode == 127)
	{
		_prints(data->program_name);
		_prints(": ");
		_prints(n_as_string);
		_prints(": ");
		_prints(data->command_name);
		_prints(": not found\n");
	}
	else if (errorcode == 126)
	{
		_prints(data->program_name);
		_prints(": ");
		_prints(n_as_string);
		_prints(": ");
		_prints(data->command_name);
		_prints(": Permission denied\n");
	}
	return (0);
}
