/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdobos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:31:37 by pdobos            #+#    #+#             */
/*   Updated: 2017/01/23 15:31:43 by pdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*src_temp;
	char	*dst_temp;

	if (n == 0)
		return ((char*)dst);
	i = 0;
	src_temp = (char*)ft_strdup(src);
	dst_temp = (char*)dst;
	while (i < n)
	{
		dst_temp[i] = src_temp[i];
		i++;
	}
	i = n;
	return (dst);
}
