/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainpipex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 03:27:47 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/08/31 17:02:39 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close_wait(t_info *info, int argc)
{
	int	pipe_fd;
	int	pid_fd;

	pid_fd = argc - 3;
	pipe_fd = (argc - 4) * 2;
	while (pipe_fd >= 0)
	{
		close(info->pipe[pipe_fd]);
		pipe_fd--;
	}
	while (pid_fd >= 0)
	{
		waitpid(info->pid[pid_fd], NULL, 0);
		pid_fd--;
	}
}

int	main(int argc, char **argv, char**envp)
{
	t_info	info;

	info.pid = malloc(sizeof(pid_t) * (argc - 3));
	info.pipe = malloc(sizeof(int) * ((argc - 4) * 2));
	if (argc >= 5)
	{
		if (pipe(info.pipe) == -1)
			return (1);
		info.pid[0] = fork();
		first_process(&info, argv, envp);
		info.pid[argc - 4] = fork();
		last_process(&info, argv, envp);
		ft_close_wait(&info, argc);
		return (0);
	}
	printf("Need at least 4 arguments\n");
	return (0);
}
