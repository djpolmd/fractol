/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdobos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 16:18:34 by pdobos            #+#    #+#             */
/*   Updated: 2017/01/23 16:18:37 by pdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *const dest, char const *src, size_t size)
{
	char	*temp_dest;
	char	*temp_src;
	size_t	n;
	size_t	len;

	temp_dest = (char *)dest;
	temp_src = (char *)src;
	n = size;
	while (*temp_dest != '\0' && n-- != 0)
		temp_dest++;
	len = temp_dest - dest;
	n = size - len;
	if (n == 0)
		return (len + ft_strlen(temp_src));
	while (*temp_src != '\0')
	{
		if (n != 1)
		{
			*temp_dest++ = *temp_src;
			n--;
		}
		temp_src++;
	}
	*temp_dest = '\0';
	return (len + (temp_src - src));
}
