/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdobos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:53:08 by pdobos            #+#    #+#             */
/*   Updated: 2017/01/23 15:53:14 by pdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_sstradd(char **s, char *add)
{
	char	**rt;
	int		i;

	i = 0;
	rt = ft_sstrnew(ft_sstrlen(s) + 1);
	while (s[i])
	{
		rt[i] = ft_strdup(s[i]);
		i++;
	}
	rt[i] = ft_strdup(add);
	ft_sstrdel(s);
	s = rt;
	return (rt);
}
