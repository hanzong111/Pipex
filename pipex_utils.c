/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 04:16:19 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/09/08 23:46:57 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check(char *buf, char *limit, int len)
{
	while (--len >= 0 && (*buf != '\0' || *buf != '\n'))
	{
		if (!(*buf == *limit))
			return (0);
		buf++;
		limit++;
	}
	if (*buf == '\0' || *buf == '\n')
		return (1);
	else
		return (0);
}

/*	To compare the Line with the LIMITER	*/
int	compare(t_info *info)
{
	int	len;

	len = ft_strlen(info->limit);
	if (info->buf == NULL)
		return (1);
	if (*info->buf == *info->limit)
	{
		if (check(info->buf, info->limit, len))
			return (0);
	}
	return (1);
}

/*	to calculate number of total processes & Start of first cmd	*/
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
}

void	error_checks(int argc, char **argv)
{
	if (argc <= 1)
	{
		ft_printf("Needs more argument\n");
		exit (0);
	}
	if (ft_strnstr(argv[1], "here_doc", 8))
	{
		if (argc < 6)
		{
			ft_printf("Needs more argument\n");
			exit (0);
		}
	}
	if (argc < 5)
	{
		ft_printf("Needs more argument\n");
		exit (0);
	}
}

void	close_wait_free(t_info *info)
{
	close(info->pipe[0]);
	close(info->pipe[1]);
	while (info->process > 0)
	{
		waitpid(info->pid[info->process - 1], NULL, 0);
		info->process--;
	}
	free(info->pid);
	free(info->pipe);
}
