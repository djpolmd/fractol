/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdobos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 14:59:41 by pdobos            #+#    #+#             */
/*   Updated: 2017/01/23 15:28:34 by pdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int result;
	int pos;

	result = 0;
	pos = 1;
	while ((*str > 8 && *str < 14) || (*str == ' '))
		str++;
	if ((*str == '-') || (*str == '+'))
		if ((pos = ((*str == '-') ? -pos : pos)))
			str++;
	while (*str == '0')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + ((char)*str - 48);
		str++;
	}
	return (result * pos);
}
