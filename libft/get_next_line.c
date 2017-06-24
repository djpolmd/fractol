/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdobos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 20:04:46 by pdobos            #+#    #+#             */
/*   Updated: 2017/01/30 20:04:48 by pdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static int		ft_output(t_rd *r, char **line, t_rd **pr)
{
	if (r->rs < 0 || r->fs <= 0)
		*pr = NULL;
	if (r->rs < 0)
		return (-1);
	if (r->fs <= 0)
	{
		r->now ? ft_memdel((void *)&r->now) : (0);
		free(r);
		return (0);
	}
	*line = ft_strncpy(ft_strnew(r->ri), r->now, r->ri);
	r->fs += (r->now - r->prev) - (*(r->prev) == '\n');
	ft_strncpy(r->now, (r->prev + 1), r->fs);
	r->prev = r->now;
	return (1);
}

static int		ft_detector(t_rd *r)
{
	while (*(r->prev) != '\n' && (r->fs > r->prev - r->now))
		r->prev++;
	r->ri = r->prev - r->now;
	if (*(r->prev) == '\n')
		return (r->fs > (r->prev - r->now));
	return (0);
}

static t_rd		*ft_resizer(t_rd *r)
{
	char		*n_now;

	if (!(n_now = ft_strcpy(ft_strnew(r->len * 2), r->now)))
		return (NULL);
	r->prev = n_now + (r->prev - r->now);
	ft_memdel((void *)&r->now);
	r->now = n_now;
	r->len = r->len * 2;
	return (r);
}

int				get_next_line(int const fd, char **line)
{
	static t_rd	*r[MFD];

	if (!line || fd < 0 || fd > MFD || BUFF_SIZE < 1)
		return (-1);
	if (!r[fd])
	{
		if (!(r[fd] = (t_rd *)malloc(sizeof(t_rd))))
			return (-1);
		r[fd]->now = ft_strnew(BUFF_SIZE);
		r[fd]->prev = r[fd]->now;
		r[fd]->len = BUFF_SIZE;
		r[fd]->fs = 0;
		r[fd]->rs = 1;
	}
	while (r[fd]->rs > 0 && !(ft_detector(r[fd])))
	{
		while (r[fd]->fs + BUFF_SIZE > r[fd]->len)
			if (!(ft_resizer(r[fd])))
				return (-1);
		r[fd]->rs = read(fd, r[fd]->now + r[fd]->fs, BUFF_SIZE);
		r[fd]->fs += r[fd]->rs;
	}
	return (ft_output(r[fd], line, &r[fd]));
}
