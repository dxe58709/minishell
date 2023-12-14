/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:53:04 by nsakanou          #+#    #+#             */
/*   Updated: 2023/12/14 16:24:30 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

bool	check_exit_args(char **argv)
{
	int	argc;
	int	i;

	argc = 0;
	i = 0;
	while (argv[argc])
		argc++;
	while (i < argc)
	{
		if (i == 0 && (argv[i][0] == '-' || ft_isalpha(argv[i][0])))
		{
			if (!ft_isdigit(argv[i][0]))
				return (false);
		}
		else if (!ft_isdigit(argv[i][0]))
			return (false);
		i++;
	}
	return (true);
}

int	exit_command(char **argv)
{
	int	i;
	int	status;

	i = 0;
	if (!check_exit_args(argv))
	{
		status = ft_atoi(argv[0]) % 256;
		if (status < 0 || status > 255)
			status = 255;
		exit(status);
	}
	return (EXIT_FAILURE);
}

/*
exit 255
echo $?
255

exit 256
echo $?
0

exit a 1 2とか, exit a 1 s d 2とかexitの最初の引数が数字じゃなかったらすぐexit
echo $?
255

bash-3.2$ exit -1
exit
c1r19s7% echo $?
255
c1r19s7% bash
bash-3.2$ exit --1
exit
bash: exit: --1: numeric argument required
c1r19s7% echo $?
255


----exit 1 aはexitできない----
bash-3.2$ exit 1 a s
exit
bash: exit: too many arguments
bash-3.2$ echo $?
1


----exit &はexitできない----
bash-3.2$ exit &
[1] 71847
bash-3.2$ echo $?
0
[1]+  Done                    exit

bash-3.2$ exit 1 &
[1] 71741
bash-3.2$ echo $?
0
[1]+  Exit 1                  exit 1

bash-3.2$ exit a &
[1] 71994
bash-3.2$ bash: exit: a: numeric argument required <-ここで固まる。enterを押したら下のようになる。

[1]+  Exit 255                exit a

----exitされない----
bash-3.2$ exit >
bash: syntax error near unexpected token `newline'
bash-3.2$ echo $?
258
*/

int main(int argc, char **argv) {
    int status;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <exit status>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // exit_command 関数を呼び出して終了ステータスを取得
    status = exit_command(&argv[1]);

    // 取得した終了ステータスを表示
    printf("Exit status: %d\n", status);

    return EXIT_SUCCESS;
}