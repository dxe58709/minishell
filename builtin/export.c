/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:53:09 by nsakanou          #+#    #+#             */
/*   Updated: 2023/12/22 17:39:45 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	export_command(char **argv, t_env *env)
{
	size_t	i;

	i = 1;
	while (argv[i])
	{
		if (env_name_judge(argv[i]) == true)
			env_update(&env, env->name, env->value);
		else
			strerror(errno);
		i++;
	}
	return (EXIT_SUCCESS);
}

/*
bash-3.2$ export a
bash-3.2$ export 1
bash: export: `1': not a valid identifier
bash-3.2$ export a 1
bash: export: `1': not a valid identifier

bash-3.2$ export TEAT="1"
bash-3.2$ export -p | grep TEAT
declare -x TEAT="1"
*/