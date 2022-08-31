/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:59:00 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/08/31 17:00:09 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_process(t_info *info, char **argv, char **envp)
{
	if (info->pid[0] == -1)
		exit(0);
	if (info->pid[0] == 0)
	{	
		info->in = ft_strdup(argv[1]);
		info->in_fd = open(info->in, O_RDONLY);
		if (info->in_fd == -1)
		{
			free(info->in);
			perror("Infile Error");
			exit(0);
		}
		dup2(info->in_fd, STDIN_FILENO);
		dup2(info->pipe[1], STDOUT_FILENO);
		close(info->pipe[0]);
		close(info->pipe[1]);
		info->flag = NULL;
		info->envp2 = NULL;
		ft_extract(argv[2], info);
		ft_pathsort(envp, info);
		ft_execute(info);
	}
}

void	last_process(t_info *info, char **argv, char **envp)
{
	if (info->pid[1] == -1)
		exit(0);
	if (info->pid[1] == 0)
	{
		info->out = ft_strdup(argv[4]);
		info->out_fd = open(info->out, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (info->out_fd == -1)
		{
			free(info->out);
			perror("Outfile Error");
			exit(0);
		}
		dup2(info->pipe[0], STDIN_FILENO);
		dup2(info->out_fd, STDOUT_FILENO);
		close(info->pipe[0]);
		close(info->pipe[1]);
		info->flag = NULL;
		info->envp2 = NULL;
		ft_extract(argv[3], info);
		ft_pathsort(envp, info);
		ft_execute(info);
	}
}
