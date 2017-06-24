/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdobos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 16:18:07 by pdobos            #+#    #+#             */
/*   Updated: 2017/01/23 16:18:11 by pdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*fresh;
	size_t	len;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	fresh = ft_strnew(len);
	while (*s1)
	{
		fresh[i++] = *s1;
		s1++;
	}
	while (*s2)
	{
		fresh[i++] = *s2;
		s2++;
	}
	fresh[len] = '\0';
	return (fresh);
}
