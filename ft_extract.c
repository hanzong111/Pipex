/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 02:13:20 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/09/08 23:57:55 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* To Extract the commands from the arguments		*/
/*	Example : "ls -la" , need to extract ls and -la	*/
void	ft_extract(char	*str, t_info *info)
{
	char	**cmd_line;

	cmd_line = ft_split(str, ' ');
	info->cmd = ft_strdup(cmd_line[0]);
	free(cmd_line[0]);
	if (cmd_line[1])
	{
		info->flag = ft_strdup(cmd_line[1]);
		free(cmd_line[1]);
	}
	free(cmd_line);
}

/*	To Fill the command and options into an array 	*/
/*	So that it can be passed to execve to be used	*/
void	ft_execve(char **envp, t_info *info)
{
	int	i;

	if (info->flag)
		i = 2;
	else
		i = 1;
	info->options = malloc(sizeof(char *) * (i + 1));
	info->options[i] = NULL;
	info->options[0] = ft_strdup(info->cmd);
	free(info->cmd);
	if (i == 2)
	{
		info->options[1] = ft_strdup(info->flag);
		free(info->flag);
	}
	execve(info->path, info->options, envp);
}
