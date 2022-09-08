/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 21:36:26 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/09/08 23:58:01 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_info
{
	pid_t	*pid;

	int		lastpid;
	int		*pipe;
	int		last_pipe;
	int		count;
	int		no;
	int		process;
	int		in_fd;
	int		out_fd;
	int		temp_fd;

	char	*limit;
	char	*buf;
	char	*in;
	char	*out;
	char	*cmd;
	char	*flag;
	char	*path;
	char	**options;
}t_info;

void	ft_pathsort(char **envp, t_info *info);
void	ft_extract(char	*str, t_info *info);
void	ft_execve(char **envp, t_info *info);
void	first_process(t_info *info, char **argv, char **envp);
void	middle_process(t_info *info, int i, char **argv, char **envp);
void	last_process(t_info *info, int argc, char **argv, char **envp);
void	process(t_info *info, int argc, char **argv, char **envp);
void	print_error(char *str);
int		compare(t_info *info);
void	close_wait_free(t_info *info);
void	calculate(t_info *info, int argc, char **argv);
void	error_checks(int argc, char **argv);

#endif