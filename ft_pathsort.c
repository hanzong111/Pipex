/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 21:25:25 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/08/24 21:40:07 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_path_extract(char **envp);
char	*ft_path_check(char **paths, char *cmd);

/*	Extract the whole PATH= from envp	*/
char	**ft_path_extract(char **envp)
{
	char	**paths;
	int		x;
	int		y;

	x = 0;
	y = 0;
	paths = NULL;
	while (envp[x++])
	{
		if (ft_strnstr(envp[x], "PATH=", 5))
		{
			while (envp[x][y++])
			{
				if (envp[x][y] == '=')
				{
					y++;
					paths = ft_split(&envp[x][y], ':');
					return (paths);
				}
			}
		}
	}
	return (paths);
}

/*	To Check which Path is the correct path for the OS	*/
/*	Returning The required path as "cmd_path"			*/
char	*ft_path_check(char **paths, char *cmd)
{
	char	*cmd_path;
	int		i;

	i = 0;
	while (paths[i++])
	{
		cmd_path = ft_strjoin(paths[i], cmd);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
	}
	return (cmd_path);
}

/*	To find the correct path and return it	*/
char	*ft_pathsort(char **envp, char	*cmd)
{
	char	**paths;
	char	*temp;
	int		x;

	paths = ft_path_extract(envp);
	x = 0;
	while (paths[x++])
	{
		temp = paths[x];
		paths[x] = ft_strjoin(paths[x], "/");
		free(temp);
	}
	temp = ft_path_check(paths, cmd);
	free(paths);
	return (temp);
}
