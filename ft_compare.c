/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 04:16:19 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/09/07 04:49:23 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

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

int	compare(t_info *info)
{
	int	len;

	len = ft_strlen(info->limit);
	if (info->buf == NULL)
		return (0);
	if (*info->buf == *info->limit)
	{
		if (check(info->buf, info->limit, len))
			return (0);
	}
	return (1);
}
