#include "main.h"
#include "utilities.h"
#include <stdlib.h>

/**
 * cd_builtin - changes the current working directory of the shell
 * @args: Array of command arguments.
 * @argc: Number of arguments in the 'args' array.
 * @command: The built-in command (unused in this function).
 */
void cd_builtin(char **args, int argc, char *command)
{
	char *directory = args[1];
	int ret;
	char *full_path;

	(void)argc;
	(void)command;

	/* If no argument is provided or argument is ~, change to HOME directory */
	if (argc == 1 || _strcmp(args[1], "~") == 0)
	{
		directory = _getenv("HOME");
		if (directory == NULL)
		{
			perror("cd: No HOME directory found\n");
			return;
		}
	}

	ret = chdir(directory);
	if (ret == -1)
	{
		perror("cd");
	}

	full_path = getcwd(NULL, 0);
	if (full_path == NULL)
	{
		perror("getcwd");
		return;
	}
	setenv("PWD", full_path, 1);
	free(full_path);
}

