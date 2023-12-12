/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:23:20 by nsakanou          #+#    #+#             */
/*   Updated: 2023/12/12 20:28:52 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

// # include "libft.h"
# include <stdbool.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <errno.h>

int		echo_command(char **argv);
int		pwd_command(void);
int		unset_command(char **argv);

int		cd_command(char **argv);

char	*search_env(const char *env_name);
void	ft_error(void);
int		ft_strcmp(char *s1, char *s2);
#endif