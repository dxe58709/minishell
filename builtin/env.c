/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:52:59 by nsakanou          #+#    #+#             */
/*   Updated: 2023/12/21 22:35:54 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
//指定された名前の環境変数を検索
t_env	*env_search(t_env *env, char *name)
{
	while (env)
	{
		if (ft_strcmp(env->name, name) == 0)
			return (env);
			env = env->next;
	}
	return (NULL);
}

static t_env	*lstlast(t_env *lst)
{
	int	i;

	i = 0;
		printf("ok1\n");
	while (lst && lst->next)
	{
		printf("%p\n", lst->next);
		i++;
		lst = lst->next;
	}
	return (lst);
}

void	env_list_add(t_env **env_list, char *name, char *value)
{
	t_env	*new_env;
	t_env	*tmp;

	new_env = (t_env *)malloc(sizeof(t_env));
	if (!env_list || !new_env)
		ft_error();
	new_env->name = ft_strdup(name);//strdupでexitするか、ここでするか
	new_env->value = ft_strdup(value);
	new_env->next = NULL;
	printf("loli\n");
	if (!*env_list)
		*env_list = new_env;
	else
	{
		printf("kami\n");
		tmp = lstlast(*env_list);
		tmp->next = new_env;
	}
}

//与えられた環境変数リスト全体を出力
void	env_list_print(t_env *env_list)
{
	while (env_list)
	{
		printf("%s=%s\n", env_list->name, env_list->value);
		env_list = env_list->next;
	}
}

int	env_command(void)
{
	t_env	*env_list;

	env_list = NULL;
	env_list_print(env_list);
	return (EXIT_SUCCESS);
}

t_env	*env_create(char **envp)
{
	char	*value;
	char	*name;
	int		i;
	t_env	*env_list;

	env_list = (t_env *)ft_calloc(1, sizeof(t_env));
	if (!env_list)
		ft_error();
	i = 0;
	while (envp[i])
	{
		value = ft_strchr(envp[i], '=') + 1;
		name = (char *)ft_calloc(value - envp[i] + 1, 1);//calloc失敗した時exit
		ft_strlcpy(name, envp[i], value - envp[i]);
		printf("%d:%s=%s,next:%p", i, env_list->name, env_list->value, env_list->next);
		env_list_add(&env_list, name, value);
		free(name);
		name = NULL;
		i++;
	}
	return (env_list);
}

#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	(void)argv;
    // env_command 関数を呼び出して環境変数のリストを出力
	t_env	*env_list;
	
	env_list = env_create(envp);
	unset_command(argv, env_list);
    env_list_print(env_list);

    return 0;
}

//envpをリストに入れる（create_env）
//第三引数でenvpが渡される