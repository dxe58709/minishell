/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: N <nsakanou@student.42tokyo.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:52:41 by nsakanou          #+#    #+#             */
/*   Updated: 2023/12/11 23:20:52 by N                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
chdir: 作業ディレクトリを変更
cd ..    cd ../  ←移動　　　cd .   cd ./　←何もなし
cd /some/directory　←絶対パス
cd some/directory　←相対パス
*/

bool  sarch_path(char **argv)
{
    int i;

    if (!argv[1] || argv[1][0] == '/')//相対or絶対パスで始まる
        return (true);
    i = 1;
    while (argv[i])
    {
        if (ft_strcmp(argv[i], ".") == 0 || ft_strcmp(argv[i], "..") == 0 ||
            ft_strncmp(argv[i], "./", 2) == 0 || ft_strncmp(argv[i], "../", 3) == 0)
            return (true);
        i++;
    }
    return (false);
}

static void	cd_home(void)
{
	char	*home_dir;

	home_dir = search_env("HOME");
	if (home_dir && chdir(home_dir) == 0)//ディレクトリの移動成功
		exit (EXIT_SUCCESS);
	else
	{
		perror("chdir error");
		exit (EXIT_FAILURE);
	}
}

int cd_command(char **argv)