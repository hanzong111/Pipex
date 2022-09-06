/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 21:25:25 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/09/06 14:14:27 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_path_extract(char **envp);
char	*ft_path_check(char **paths, char *cmd);
char	**ft_pathcat(char **paths);

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
	while (paths[i])
	{
		cmd_path = ft_strjoin(paths[i], cmd);
		free(paths[i]);
		if (access(cmd_path, F_OK | X_OK) == 0)
		{
			while (paths[++i])
				free(paths[i]);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	return (NULL);
}

/*	To Add a '/' character at the end of each extracted path	*/
char	**ft_pathcat(char **paths)
{
	char	**temp;
	int		x;
	int		count;

	x = 0;
	count = 0;
	while (paths[count])
		count++;
	temp = malloc(sizeof(char *) * (count + 1));
	temp[count] = NULL;
	while (paths[x])
	{
		temp[x] = ft_strjoin(paths[x], "/");
		free(paths[x]);
		x++;
	}
	free(paths);
	return (temp);
}

/*	To find the correct path and return it	*/
void	ft_pathsort(char **envp, t_info *info)
{
	char	**paths;
	char	**temp;
	char	*cmd_path;

	paths = ft_path_extract(envp);
	temp = ft_pathcat(paths);
	cmd_path = ft_path_check(temp, info->cmd);
	if (cmd_path == NULL)
		perror("Command");
	free(temp);
	info->path = cmd_path;
}
