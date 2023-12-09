/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:53:20 by nsakanou          #+#    #+#             */
/*   Updated: 2023/12/09 22:03:13 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
bashで定義した変数や関数を削除するコマンド [unset 変数名] 環境変数を削除
環境変数の識別子
１ 英字（大文字または小文字）、数字、およびアンダースコア _ 
	ただし、最初の文字は数字ではない.
2 大文字と小文字を区別 ex)PATH と Path は異なる環境変数
*/

#include "builtin.h"

bool	name_judge(char *name)
{
	size_t	i;

	i = 0;
	if (!ft_isalpha(name[i]) && name[i] != '_')
		return (false);
	i++;
	while (name[i])
	{
		if (!ft_isalnum(name[i]) && name[i] != '_')
			return (false);
		i++;
	}
	return (true);
}

int	unset_command(char **argv)
{
	size_t	i;

	i = 1;

	while (argv[i])
	{
		if (name_judge(name[i]) == true)
		//環境変数を削除する関数を作成する
		else
		{
			perror("error");
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}