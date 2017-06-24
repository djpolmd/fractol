/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdobos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 16:19:21 by pdobos            #+#    #+#             */
/*   Updated: 2017/01/23 16:19:25 by pdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*fstr;

	i = 0;
	fstr = ft_strnew(ft_strlen(s));
	while (s[i])
	{
		fstr[i] = f(s[i]);
		i++;
	}
	return (fstr);
}
