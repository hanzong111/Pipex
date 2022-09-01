/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainpipex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 03:27:47 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/09/01 16:57:17 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_wait(t_info *info, int argc)
{
	int	pid_fd;

	pid_fd = argc - 3;
	close(info->pipe[0]);
	close(info->pipe[1]);
	while (pid_fd > 0)
	{
		waitpid(info->pid[pid_fd - 1], NULL, 0);
		pid_fd--;
	}
}

int	main(int argc, char **argv, char**envp)
{
	t_info	info;
	int		process;
	int		i;

	i = 1;
	process = argc - 3;
	info.pid = malloc(sizeof(pid_t) * process);
	info.pipe = malloc(sizeof(int) * 2);
	if (argc >= 5)
	{
		if (pipe(info.pipe) == -1)
			return (0);
		first_process(&info, argv, envp);
		while (++i < process)
			middle_process(&info, i, argv, envp);
		last_process(&info, argc, argv, envp);
		close_wait(&info, argc);
		return (0);
	}
	printf("Need at least 4 arguments\n");
	return (0);
}
