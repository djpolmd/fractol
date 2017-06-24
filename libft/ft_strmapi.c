/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdobos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 16:19:35 by pdobos            #+#    #+#             */
/*   Updated: 2017/01/23 16:19:39 by pdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*fstr;

	i = 0;
	fstr = ft_strnew(ft_strlen(s));
	while (s[i])
	{
		fstr[i] = f(i, s[i]);
		i++;
	}
	return (fstr);
}
