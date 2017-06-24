/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdobos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 16:23:56 by pdobos            #+#    #+#             */
/*   Updated: 2017/01/30 20:04:24 by pdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"

# define BUFF_SIZE	1
# define MFD		1000

typedef struct		s_rd
{
	char			*now;
	char			*prev;
	long int		len;
	long int		ri;
	long int		rs;
	long int		fs;
}					t_rd;

int					get_next_line(const int fd, char **line);

#endif
