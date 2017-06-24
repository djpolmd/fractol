/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdobos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 20:05:25 by pdobos            #+#    #+#             */
/*   Updated: 2017/01/30 20:05:34 by pdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isint(char *str, int len)
{
	char	*tmp;

	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-' || *str == '+')
		str++;
	tmp = str;
	while (*tmp)
	{
		if (ft_isdigit(*tmp) == 1)
			return (1);
		tmp++;
	}
	if (len == 10)
	{
		if (ft_strcmp(str, "2147483647") > 0)
			return (1);
	}
	else if (len > 10)
	{
		if (ft_strcmp(str, "-2147483648") > 0)
			return (0);
		return (1);
	}
	return (0);
}
