/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdobos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:30:23 by pdobos            #+#    #+#             */
/*   Updated: 2017/01/23 15:30:29 by pdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int				i;
	int				len;
	unsigned char	*src_temp;
	unsigned char	*dst_temp;

	i = -1;
	src_temp = (unsigned char*)src;
	dst_temp = (unsigned char*)dst;
	len = (int)n;
	while (i++ < len)
		if (src_temp[i] != (unsigned char)c)
			dst_temp[i] = src_temp[i];
		else
			return (&dst_temp[i + 1]);
	return (NULL);
}
