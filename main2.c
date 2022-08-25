/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 02:17:34 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/08/26 03:21:03 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char**envp)
{
	t_info	info;
	int		fd;

	envp[0] = "haha";
	if (argc >= 5)
	{
		info.infile = ft_strdup(argv[1]);
		fd = open("Test", O_RDONLY);
		dup2(fd, STDIN_FILENO);
		free(info.infile);
		info.flag = NULL;
		info.envp2 = NULL;
		ft_extract(argv[2], &info);
		ft_pathsort(envp, &info);
		ft_options(&info);
		execve(info.path, info.options, info.envp2);
		free(info.options[0]);
		free(info.options[1]);
		free(info.options);
		free(info.path);
		return (0);
	}
	printf("Need at least 4 arguments\n");
	return (0);
}