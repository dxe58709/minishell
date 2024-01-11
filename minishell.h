/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:43:26 by yushsato          #+#    #+#             */
/*   Updated: 2024/01/05 15:24:30 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "lib/libft/libft.h"
# include "lib/ft_printf/ft_printf.h"

int	g_signal;

typedef struct s_token
{
	char			*str;
	int				len;	
	char			*type;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

void	dms_putenv(char **chain);
void	dms_putchain(t_token *chain);

char	**ms_envadd(char *new);
char	**ms_envget(void);
char	**ms_envinit(char **envp);
void	ms_setsignal(void);
void	ms_isctrld(char *stdin, char **env);
t_token	*ms_token_add(t_token *chain, t_token *new);
t_token	*ms_token_free(t_token *chain);
t_token	*ms_token_last(t_token *chain);
t_token	*ms_token_new(char *str, int len, const char *type);
t_token	*lxr_lexer(char *str);
int		lxr_pipe(char *str, t_token *chain);
int		lxr_redirect(char *str, t_token *chain);
int		lxr_semicolon(char *str, t_token *chain);
int		lxr_token(char *str, t_token *chain);

#endif
