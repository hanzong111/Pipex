/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 21:25:34 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/08/24 21:43:49 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int     main(int ac, char **av, char **envp)
{
	if (ac > 4)
		return(printf("fk u\n"));
	av[0] = "haha";
	char	*cmd_path;
	char	*cmd;

	cmd = ft_strdup(av[1]);
	cmd_path = ft_pathsort(envp, cmd);
	printf("String is %s\n", cmd_path);
	free(cmd);
	return (0);
}
