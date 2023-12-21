/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:42:38 by nsakanou          #+#    #+#             */
/*   Updated: 2023/12/21 21:57:43 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

bool env_name_judge(char *name) // export, unset
{
	size_t i;

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

// 環境変数の削除
void env_del(t_env **env_list, char *name)
{
	t_env *prev;
	t_env *current;

	prev = NULL;
	current = *env_list;
	while (current)
	{
		printf("%s\n", "ccccc");
		printf("%s\n", current->name);
		if (ft_strcmp(current->name, name) == 0)
		{
			printf("dddddd\n");
			if (prev)
				prev->next = current->next;
			else
				*env_list = current->next;
			free(current->name);
			free(current->value);
			free(current);
			return;
		}
		printf("%s\n", "aaaaaaa");
		prev = current;
		current = current->next;
		printf("%s\n", "bbbbb");
	}
	return;
}

// 環境変数の更新
// 指定された名前の環境変数が存在すればその値を更新し、存在しなければ新しい環境変数として追加
void env_update(t_env **env_list, char *name, char *value)
{
	t_env *current;

	current = env_search(*env_list, name);
	if (current)
	{
		free(current->value);
		current->value = ft_strdup(value); // ft_strdupでexit
	}
	else
		env_create((char **)env_list);
}
