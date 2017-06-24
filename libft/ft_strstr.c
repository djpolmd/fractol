/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdobos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 16:22:10 by pdobos            #+#    #+#             */
/*   Updated: 2017/01/23 16:22:13 by pdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;
	int		l_len;

	i = 0;
	l_len = ft_strlen(little);
	if (ft_strlen(big) >= ft_strlen(little) && little != NULL)
	{
		while (*big)
		{
			j = 0;
			while (big[i] == little[j] && big[i] && little[i])
			{
				j++;
				i++;
			}
			if (j == l_len)
				return ((char*)big);
			big++;
		}
	}
	return (NULL);
}
