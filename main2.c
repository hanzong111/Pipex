/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 02:17:34 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/08/26 02:29:42 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char**envp)
{
	t_info	info;

	envp[0] = "haha";
	if (argc >= 5)
	{
		info.flag = NULL;
		ft_extract_cmd(argv[2], &info);
		printf("Cmd is %s\n", info.cmd);
		if (info.flag)
		{	
			printf("Cmd flag is %s\n", info.flag);
			free(info.flag);
		}
		free(info.cmd);
		return (0);
	}
	printf("Need at least 4 arguments\n");
	return (0);
}