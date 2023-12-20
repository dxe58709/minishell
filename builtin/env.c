/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:52:59 by nsakanou          #+#    #+#             */
/*   Updated: 2023/12/20 15:16:21 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static void	print_env(t_env *env)
{
	while (env)
	{
		if (ft_strchr(env->content, '='))
			ft_putendl_fd(env->content, 1);
	}
	env = env->next;
}

int	env_command(void)
{
	if ()
}
