/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdobos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:31:19 by pdobos            #+#    #+#             */
/*   Updated: 2017/01/23 15:31:25 by pdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*s1_t;
	char	*s2_t;

	i = -1;
	s1_t = (char*)s1;
	s2_t = (char*)s2;
	while (++i < n)
		if (s1_t[i] != s2_t[i])
			return (s1_t[i] - s2_t[i]);
	return (0);
}
