/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:53:09 by nsakanou          #+#    #+#             */
/*   Updated: 2023/12/20 14:44:38 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	set_env(char **argv)
{
	
}

int	export_command(char **argv)
{
	if (argv[1])
		return (set_env(argv[1]));
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/*
左辺と右辺のチェック
環境変数を表示
*/