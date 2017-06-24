/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdobos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:30:06 by pdobos            #+#    #+#             */
/*   Updated: 2017/01/30 20:02:30 by pdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_isneg(int *n, char c)
{
	c = '-';
	(*n == -2147483648) ? (*n = 2147483647) : (*n *= -1);
	return (c);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		isave;
	int		nsave;

	i = ft_length_int(n);
	(n < 0) ? i++ : (0);
	isave = i;
	if (!(str = ft_strnew(i)))
		return (NULL);
	nsave = n;
	(n < 0) ? i-- : (0);
	(n < 0) ? str[0] = ft_isneg(&n, str[0]) : (0);
	(n < 0) ? (0) : (str[i--] = '\0');
	(n == 0) ? str[0] = '0' : (0);
	while (n != 0)
	{
		str[i] = '0' + n % 10;
		n /= 10;
		i--;
	}
	(nsave == -2147483648) ? (str[isave] += 1) : (str[0] = str[0]);
	str[isave] = '\0';
	return (str);
}
