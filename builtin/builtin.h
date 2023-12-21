/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:23:20 by nsakanou          #+#    #+#             */
/*   Updated: 2023/12/21 22:33:21 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "libft.h"
# include <stdbool.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <errno.h>
# include <ctype.h>

typedef struct s_env
{
	char			*name;//環境変数の名前
	char			*value;//環境変数の値　"/home/user" 
	struct s_env	*next;
}t_env;


//command
int		echo_command(char **argv);
int		pwd_command(void);
int		unset_command(char **argv, t_env *env);
int		exit_command(char **argv);
int		cd_command(char **argv);
int		export_command(char **argv);
//env
int		env_command(void);
t_env	*env_search(t_env *env, char *name);
void	env_list_add(t_env **env_list, char *name, char *value);
void	env_list_print(t_env *env_list);
t_env	*env_create(char **envp);

//env_utils
bool	env_name_judge(char *name);
void	env_del(t_env **env_list, char *name);
void	env_update(t_env **env_list, char *name, char *value);

//utils
char	*search_env(const char *env_name);
void	ft_error(void);
int		ft_strcmp(char *s1, char *s2);

#endif