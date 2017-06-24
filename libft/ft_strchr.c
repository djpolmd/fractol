/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdobos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:53:48 by pdobos            #+#    #+#             */
/*   Updated: 2017/01/23 15:53:53 by pdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*buf;
	int		i;
	int		len;

	buf = (char*)s;
	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (*buf == (unsigned char)c)
			return (buf);
		else
		{
			i++;
			buf++;
		}
	}
	return (NULL);
}
