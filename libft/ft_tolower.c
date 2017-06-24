/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdobos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 16:23:01 by pdobos            #+#    #+#             */
/*   Updated: 2017/01/23 16:23:05 by pdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	unsigned char	t;

	t = (unsigned char)c;
	if (t >= 'A' && t <= 'Z')
		return (t + 32);
	else
		return (c);
}
