/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 02:13:20 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/08/26 02:31:13 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* To Extract the commands from the arguments		*/
/*	Example : "ls -la" , need to extract ls and -la	*/
void	ft_extract_cmd(char	*str, t_info *info)
{
	char	**cmd_line;

	cmd_line = ft_split(str, ' ');
	info->cmd = ft_strdup(cmd_line[0]);
	free(cmd_line[0]);
	if (cmd_line[1])
	{
		info->flag = ft_strdup(cmd_line[1]);
		free(cmd_line[1]);
	}
	free(cmd_line);
}