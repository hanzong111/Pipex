/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainpipex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 03:27:47 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/09/08 16:16:23 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_wait(t_info *info)
{
	close(info->pipe[0]);
	close(info->pipe[1]);
	while (info->process > 0)
	{
		waitpid(info->pid[info->process - 1], NULL, 0);
		info->process--;
	}
}

void	here_doc(t_info *info, char **argv)
{	
	info->limit = ft_strdup(argv[2]);
	info->temp_fd = open("temp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	info->here_fd = open("here_doc", O_RDONLY);
	info->buf = get_next_line(info->here_fd);
	while (compare(info))
	{
		if (info->buf != NULL)
		{
			write(info->temp_fd, info->buf, ft_strlen(info->buf));
			free(info->buf);
		}
		info->buf = get_next_line(info->here_fd);
	}
	free(info->buf);
	free(info->limit);
	close(info->temp_fd);
	close(info->here_fd);
}

void	calculate(t_info *info, int argc, char **argv)
{
	if (!ft_strnstr(argv[1], "here_doc", 8))
	{
		info->process = argc - 3;
		info->no = 2;
		info->lastpid = argc - 4;
	}
	else
	{
		info->process = argc - 4;
		info->no = 3;
		info->lastpid = argc - 5;
	}
	info->pid = malloc(sizeof(pid_t) * info->process);
	info->pipe = malloc(sizeof(int) * 2);
}

int	main(int argc, char **argv, char**envp)
{
	int		i;
	t_info	info;

	if (argc >= 5)
	{
		i = 1;
		calculate(&info, argc, argv);
		if (pipe(info.pipe) == -1)
			return (0);
		if (ft_strnstr(argv[1], "here_doc", 8))
			here_doc(&info, argv);
		first_process(&info, argv, envp);
		while (++i < info.process)
		{
			info.no++;
			middle_process(&info, i, argv, envp);
		}
		last_process(&info, argc, argv, envp);
		close_wait(&info);
		free(info.pid);
		free(info.pipe);
		return (0);
	}
	printf("Need at least 4 arguments\n");
	return (0);
}
