/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:52:59 by nsakanou          #+#    #+#             */
/*   Updated: 2024/01/20 13:20:40 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../builtin.h"

t_env	*env_search(t_env *env, char *name)
{
	if (name == NULL)
		return (NULL);
	while (env)
	{
		if (env->name && ft_strcmp(env->name, name) == 0)
			return (env);
		env = env->next;
	}
	return (NULL);
}

void	env_list_add(t_env **env_list, char *name, char *value)
{
	t_env	*new_env;
	t_env	*tmp;

	new_env = (t_env *)ft_calloc(1, sizeof(t_env));
	if (!env_list)
		list_error();
	new_env->name = ft_strdup(name);
	if (value == NULL)
		new_env->value = NULL;
	else
		new_env->value = ft_strdup(value);
	new_env->next = NULL;
	if (!*env_list)
		*env_list = new_env;
	else
	{
		tmp = lstlast(*env_list);
		tmp->next = new_env;
	}
}

t_env	*env_create(char **envp)
{
	char	*value;
	char	*name;
	int		i;
	t_env	*env_list;

	env_list = (t_env *)ft_calloc(1, sizeof(t_env));
	i = 0;
	while (envp[i])
	{
		value = ft_strchr(envp[i], '=') + 1;
		name = (char *)ft_calloc(value - envp[i] + 1, 1);
		ft_strlcpy(name, envp[i], value - envp[i]);
		env_list_add(&env_list, name, value);
		free(name);
		name = NULL;
		i++;
	}
	*(env_store()) = env_list;
	return (env_list);
}

int	env_command(void)
{
	t_env	*env;

	env = *(env_store());
	if (env != NULL)
		env = env->next;
	while (env && env->name)
	{
		printf("%s=%s\n", env->name, env->value);
		env = env->next;
	}
	env_update("?", "0");
	return (EXIT_SUCCESS);
}
