/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_julia.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdobos2 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 22:23:21 by pdobos2           #+#    #+#             */
/*   Updated: 2017/06/22 22:23:27 by pdobos2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		default_values(t_fractol *f)
{
	f->fname = "Julia";
	f->ftype = T_JLA;
	f->finit = 0;
	f->master.x1 = -2;
	f->master.x2 = 2;
	f->master.y1 = -1.25;
	f->master.y2 = 1.25;
	f->master.imax = F_DIMAX / 2;
	f->master.zoom = (WIN_X / 4);
	f->master.zfactor = 1;
	f->master.cr = 0.285;
	f->master.ci = 0.01;
	f->clr_a = 0;
	f->clr_r = 40;
	f->clr_g = 20;
	f->clr_b = 30;
	f->clr = f->clr_a << 24 | f->clr_r << 16 | f->clr_g << 8 | f->clr_b << 3;
	f->master.clr = f->clr;
}

static void		iteration(t_fractol *f, int x, int y)
{
	int			i;
	double		tmp;
	t_thread	*ptr;

	ptr = &f->thread[f->id];
	i = 0;
	ptr->zr = x / ptr->zoom + ptr->x1;
	ptr->zi = y / ptr->zoom + ptr->y1;
	while (ptr->zr * ptr->zr + ptr->zi * ptr->zi < 4 && i < ptr->imax)
	{
		tmp = ptr->zr;
		ptr->zr = ptr->zr * ptr->zr - ptr->zi * ptr->zi + ptr->cr;
		ptr->zi = 2 * ptr->zi * tmp + ptr->ci;
		i++;
	}
	(i != ptr->imax) ? fractol_mlx_pixel(f, x, y, i * ptr->clr) : (0);
}

void			julia(t_fractol *f)
{
	int			x;
	t_thread	*ptr;

	if (f->finit)
		return (default_values(f));
	ptr = &f->thread[f->id];
	while (ptr->t_y < ptr->t_my)
	{
		x = ptr->t_x;
		while (x < ptr->t_mx)
		{
			iteration(f, x, ptr->t_y);
			x++;
		}
		ptr->t_y++;
	}
}
