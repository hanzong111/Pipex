/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 21:36:26 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/08/26 03:51:36 by ojing-ha         ###   ########.fr       */
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
	char	*infile;
	char	*outfile;
	char	*cmd;
	char	*flag;

	char	*path;
	char	**options;
	char	**envp2;
}t_info;

void	ft_pathsort(char **envp, t_info *info);
void	ft_extract(char	*str, t_info *info);
void	ft_options(t_info *info);

#endif