/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainpipex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 03:27:47 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/08/29 23:50:27 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(t_info *info)
{
	if (info->outfile)
		free(info->outfile);
	if (info->infile)
		free(info->infile);
	free(info->cmd);
	free(info->options[0]);
	free(info->options[1]);
	free(info->options);
	free(info->path);
}

int	main(int argc, char **argv, char**envp)
{
	t_info	info;
	pid_t	pid1;
	pid_t	pid2;
	int		infile_fd;
	int		outfile_fd;
	int		pipe_fd[2];

	infile_fd = 0;
	outfile_fd = 0;
	if (argc >= 5)
	{
		if (pipe(pipe_fd) == -1)
			return (1);
		pid1 = fork();
		if (pid1 == -1)
			return (2);
		if (pid1 == 0)
		{	
			info.infile = ft_strdup(argv[1]);
			infile_fd = open(info.infile, O_RDONLY);
			if (infile_fd == -1)
			{
				free(info.infile);
				perror("Infile Error");
				return (0);
			}
			dup2(infile_fd, STDIN_FILENO);
			dup2(pipe_fd[1], STDOUT_FILENO);
			close(pipe_fd[0]);
			close(pipe_fd[1]);
			info.flag = NULL;
			info.envp2 = NULL;
			ft_extract(argv[2], &info);
			ft_pathsort(envp, &info);
			ft_options(&info);
			execve(info.path, info.options, info.envp2);
			ft_free(&info);
		}
		pid2 = fork();
		if (pid2 == -1)
			return (3);
		if (pid2 == 0)
		{
			info.outfile = ft_strdup(argv[4]);
			outfile_fd = open(info.outfile, O_RDWR | O_TRUNC | O_CREAT);
			dup2(pipe_fd[0], STDIN_FILENO);
			dup2(outfile_fd, STDOUT_FILENO);
			close(pipe_fd[0]);
			close(pipe_fd[1]);
			info.flag = NULL;
			info.envp2 = NULL;
			ft_extract(argv[3], &info);
			ft_pathsort(envp, &info);
			ft_options(&info);
			execve(info.path, info.options, info.envp2);
			ft_free(&info);
		}
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		close(infile_fd);
		close(outfile_fd);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
		return (0);
	}
	printf("Need at least 4 arguments\n");
	return (0);
}