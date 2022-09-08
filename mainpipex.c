/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainpipex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 03:27:47 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/09/08 23:42:10 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	here_doc(t_info *info, char **argv)
{	
	info->limit = ft_strdup(argv[2]);
	info->temp_fd = open("temp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	info->buf = get_next_line(0);
	while (info->buf != NULL && compare(info))
	{
		write(info->temp_fd, info->buf, ft_strlen(info->buf));
		free(info->buf);
		info->buf = get_next_line(0);
	}
	free(info->buf);
	free(info->limit);
	close(info->temp_fd);
}

int	main(int argc, char **argv, char**envp)
{
	t_info	info;

	error_checks(argc, argv);
	calculate(&info, argc, argv);
	info.pid = malloc(sizeof(pid_t) * info.process);
	info.pipe = malloc(sizeof(int) * 2);
	if (pipe(info.pipe) == -1)
		return (0);
	if (ft_strnstr(argv[1], "here_doc", 8))
		here_doc(&info, argv);
	process(&info, argc, argv, envp);
	close_wait_free(&info);
	return (0);
}
