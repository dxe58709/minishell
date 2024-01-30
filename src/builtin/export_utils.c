/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:41:00 by nsakanou          #+#    #+#             */
/*   Updated: 2024/01/18 18:54:39 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../builtin.h"

static char	*export_getname(char *argv)
{
	int		i;
	char	*name;

	i = -1;
	if (!argv[0])
		return (NULL);
	while (argv[++i])
	{
		if ((!env_name_judge(argv) || (argv[i] == ' ' && argv[i + 1] == '='))
			&& ft_eprintf("not a valid identifier\n"))
			return (NULL);
		if (argv[i] == '=' || (argv[i] == '+' && argv[i + 1] == '='))
		{
			name = ft_calloc(i + 1, sizeof(char));
			ft_strlcpy(name, argv, i + 1);
			return (name);
		}
	}
	name = ft_calloc(i + 1, sizeof(char));
	ft_strlcpy(name, argv, i + 1);
	return (name);
}

static char	*export_getvalue(char *argv)
{
	char	*value;
	char	*equal;

	equal = ft_strchr(argv, '=');
	if (equal == NULL)
		return (NULL);
	value = ft_strdup(equal + 1);
	return (value);
}

static void	export_insert_plus(t_env *env, char *value)
{
	char	*temp;

	temp = env->value;
	env->value = ft_strjoin(env->value, value);
	free(temp);
}

int	export_insert(char *arg, t_env *env)
{
	char	*name;
	char	*value;
	int		status;

	name = export_getname(arg);
	value = export_getvalue(arg);
	env = env_search(env, name);
	status = 0;
	if (name == NULL)
		status = 1;
	else if (check_type(arg) == '=' && env == NULL)
		env_list_add(env_store(), name, value);
	else if (check_type(arg) == '=')
		env_search(env, name)->value = value;
	else if (check_type(arg) == '+' && env == NULL)
		env_list_add(env_store(), name, value);
	else if (check_type(arg) == '+')
		export_insert_plus(env, value);
	else if (check_type(arg) == 0 && env == NULL)
		env_list_add(env_store(), name, NULL);
	free(name);
	free(value);
	return (status);
}
