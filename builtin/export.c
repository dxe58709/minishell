/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: N <nsakanou@student.42tokyo.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:53:09 by nsakanou          #+#    #+#             */
/*   Updated: 2023/12/19 23:40:35 by N                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int export_command(char **argv)
{
    if (argv[1])
        return (set_env);
    else
        return ();
    return (EXIT_SUCCESS);
}