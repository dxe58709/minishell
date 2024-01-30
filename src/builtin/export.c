/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:53:09 by nsakanou          #+#    #+#             */
/*   Updated: 2024/01/20 13:19:33 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../../builtin.h"

static t_env	*export_envcpy(t_env *env)
{
	t_env	*copy;
	t_env	*prev;
	t_env	*head;

	prev = NULL;
	while (env)
	{
		copy = ft_calloc(1, sizeof(t_env));
		ft_memcpy(copy, env, sizeof(t_env));
		if (prev != NULL)
			prev->next = copy;
		else
			head = copy;
		env = env->next;
		copy->next = NULL;
		prev = copy;
	}
	return (head);
}

static t_env	*export_swap(t_env *env)
{
	char	*tmp;

	ft_memcpy(&tmp, &env->name, sizeof(void *));
	ft_memcpy(&env->name, &env->next->name, sizeof(void *));
	ft_memcpy(&env->next->name, &tmp, sizeof(void *));
	ft_memcpy(&tmp, &env->value, sizeof(void *));
	ft_memcpy(&env->value, &env->next->value, sizeof(void *));
	ft_memcpy(&env->next->value, &tmp, sizeof(void *));
	return (env);
}

static t_env	*export_putenv(t_env *env)
{
	if (!ft_memcmp(env->name, "_", 2)
		|| !(ft_isalpha(env->name[0]) || env->name[0] == '_'))
		return (env);
	if (env->value)
		ft_printf("declare -x %s=\"%s\"\n", env->name, env->value);
	else
		ft_printf("declare -x %s\n", env->name);
	return (env);
}

void	export_putenvs(t_env *env)
{
	t_env	*copy;
	t_env	*prev;
	t_env	*head;
	int		i;

	copy = export_envcpy(env);
	head = copy;
	prev = NULL;
	i = 1;
	while (i && ft_memset(&i, 0, sizeof(int)))
	{
		while (copy && copy->next)
		{
			if (ft_strcmp(copy->name, copy->next->name) > 0
				&& export_swap(copy))
				i++;
			copy = copy->next;
		}
		copy = head;
	}
	while (copy && export_putenv(copy))
		copy = copy->next;
	while (copy && ft_memcpy(&prev, &copy, sizeof(void *))
		&& ft_memcpy(&copy, &copy->next, sizeof(void *)))
		free(prev);
}

int	export_command(char **argv)
{
	t_env	*env;
	int		ret;

	ret = 0;
	env = (*env_store())->next;
	if (ft_memcpy(&env, &(*env_store())->next, sizeof(void *)) && !argv[1])
		export_putenvs(env);
	while (env_update("?", ft_itoa(ret)) && *++argv)
		if (export_insert(*argv, env))
			ret = 1;
	return (ret);
}
