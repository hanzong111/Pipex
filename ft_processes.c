/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:59:00 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/09/07 05:21:38 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_process(t_info *info, char **argv, char **envp)
{
	info->pid[0] = fork();
	if (info->pid[0] == -1)
		exit(0);
	if (info->pid[0] == 0)
	{	
		if (!ft_strnstr(argv[1], "here_doc", 8))
			info->in = ft_strdup(argv[1]);
		else
			info->in = ft_strdup("temp");
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
		ft_extract(argv[info->no], info);
		ft_pathsort(envp, info);
		ft_execute(envp, info);
	}
}

void	middle_process(t_info *info, int i, char **argv, char **envp)
{
	close(info->pipe[1]);
	info->last_pipe = info->pipe[0];
	if (pipe(info->pipe) == -1)
		exit(0);
	info->pid[i - 1] = fork();
	if (info->pid[i - 1] == -1)
		exit(0);
	if (info->pid[i - 1] == 0)
	{
		dup2(info->last_pipe, STDIN_FILENO);
		close(info->last_pipe);
		dup2(info->pipe[1], STDOUT_FILENO);
		close(info->pipe[0]);
		close(info->pipe[1]);
		info->flag = NULL;
		ft_extract(argv[info->no], info);
		ft_pathsort(envp, info);
		ft_execute(envp, info);
	}
}

void	last_process(t_info *info, int argc, char **argv, char **envp)
{
	info->pid[info->lastpid] = fork();
	if (info->pid[info->lastpid] == -1)
		exit(0);
	if (info->pid[info->lastpid] == 0)
	{
		info->out = ft_strdup(argv[argc - 1]);
		if (ft_strnstr(argv[1], "here_doc", 8))
			info->out_fd = open(info->out, O_WRONLY | O_APPEND | O_CREAT, 0644);
		else
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
		ft_extract(argv[argc - 2], info);
		ft_pathsort(envp, info);
		ft_execute(envp, info);
		unlink("temp");
	}
}
