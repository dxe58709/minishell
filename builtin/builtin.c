#include "builtin.h"

int exec_builtin(char **argv)
{
	if (ft_strcmp(argv[0], "echo") == 0)
		return (echo_command(argv));
	else if (ft_strcmp(argv[0], "cd") == 0)
		return (cd_command(argv));
	else if (ft_strcmp(argv[0], "pwd") == 0)
		return (pwd_command());
	else if (ft_strcmp(argv[0], "export") == 0)
		return (export_command(argv));
	else if (ft_strcmp(argv[0], "unset") == 0)
		return (unset_command(argv));
	else if (ft_strcmp(argv[0], "env") == 0)
		return (env_command());
    else if (ft_strcmp(argv[0], "exit") == 0)
		return (exit_command(argv));
	return (EXIT_FAILURE);
}