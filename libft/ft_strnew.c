/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdobos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 16:56:17 by pdobos            #+#    #+#             */
/*   Updated: 2017/01/23 16:56:22 by pdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new_string;
	size_t	i;

	i = 0;
	new_string = (char*)ft_memalloc(size + 1);
	while (i <= size && new_string != NULL)
	{
		new_string[i] = '\0';
		i++;
	}
	return (new_string);
}
