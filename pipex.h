/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 21:36:26 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/09/05 19:32:48 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_info
{
	pid_t	*pid;
	int		*pipe;
	int		last_pipe;
	int		count;

	char	*in;
	char	*out;
	char	*cmd;
	char	*flag;

	int		in_fd;
	int		out_fd;

	char	*path;
	char	**options;
}t_info;

void	ft_pathsort(char **envp, t_info *info);
void	ft_extract(char	*str, t_info *info);
void	ft_execute(char **envp, t_info *info);
void	first_process(t_info *info, char **argv, char **envp);
void	middle_process(t_info *info, int i, char **argv, char **envp);
void	last_process(t_info *info, int argc, char **argv, char **envp);

#endif