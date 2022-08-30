/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 01:18:33 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/08/31 01:21:44 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"pipex.h"

int	main(void)
{
	t_info	info;
	char	*str;

	info.infile = malloc(sizeof(char) * 2);
	info.infile[0] = 'a';
	info.infile[1] = '\0';
	str = malloc(sizeof(char) * 2);
	str[0] = 'b';
	str[1] = '\0';
	free(info.infile);
	free(str);
	return (0);
}