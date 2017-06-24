/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdobos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 16:21:35 by pdobos            #+#    #+#             */
/*   Updated: 2017/01/23 16:21:38 by pdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*buf;
	int		i;

	i = ft_strlen(s);
	buf = (char*)s + i;
	while (i >= 0)
	{
		if (*buf == (unsigned char)c)
			return (buf);
		else
		{
			i--;
			buf--;
		}
	}
	return (NULL);
}
