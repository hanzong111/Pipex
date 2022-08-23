/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:39:00 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/07/04 18:40:30 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int x)
{
	if (!(x >= 0 && x <= 127))
		return (0);
	if (x >= '0' && x <= '9')
		return (1);
	else if (x >= 'a' && x <= 'z')
		return (1);
	else if (x >= 'A' && x <= 'Z')
		return (1);
	else
		return (0);
}