/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:52:50 by nsakanou          #+#    #+#             */
/*   Updated: 2023/12/09 21:54:10 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

bool	option_n(char *str)
{
	if (str && str[0] == '-' && str[1] == 'n' && str[2] == '\0')
		return (true);
	return (false);
}

int	echo_command(char **argv)
{
	size_t	i;

	i = 2;//argv=２から(argv1はecho）
	if (option_n(argv[2]) == true)//オプションありの時argv=3から(argv1はecho, argv2は-n）
		i = 3;
	while (argv[i])
	{
		printf("%s", argv[i]);
		if (argv[i + 1] != NULL)//次の要素があれば
			printf(" ");
	i++;
	}
	if (option_n(argv[2]) == false)//オプション無し
		printf("\n");
	return (EXIT_SUCCESS);
}

/*
オプション無し echo 1 2 3
1 2 3
%
オプションあり echo -n 1 2 3
1 2 3%

終了ステータスは0,1ではなくEXIT_SUCCESS,EXIT_FAILURE
*/

// int main(int argc, char **argv) {
//     if (argc >= 2) {
//         echo_command(argv);
//     } else {
//         printf("Usage: %s <args>\n", argv[0]);
//     }

//     return EXIT_SUCCESS;
// }