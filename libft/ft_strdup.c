/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdobos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 16:16:05 by pdobos            #+#    #+#             */
/*   Updated: 2017/01/23 16:16:13 by pdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	while (s1[i] != '\0')
		i++;
	ret = (char*)malloc(sizeof(char) * i);
	j = -1;
	while (++j < i)
		ret[j] = s1[j];
	ret[j] = '\0';
	return (ret);
}
