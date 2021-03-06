/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_tricorn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdobos2 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 22:24:05 by pdobos2           #+#    #+#             */
/*   Updated: 2017/06/22 22:24:07 by pdobos2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		default_values(t_fractol *f)
{
	f->fname = "Tricorn";
	f->ftype = T_TRC;
	f->finit = 0;
	f->master.x1 = -2.1;
	f->master.x2 = 1.75;
	f->master.y1 = -1.2;
	f->master.y2 = 1.15;
	f->master.imax = F_DIMAX;
	f->master.zoom = (WIN_X / 4) + 12;
	f->master.zfactor = 1;
	f->master.cr = 0;
	f->master.ci = 0;
	f->clr_a = F_DCLR_A;
	f->clr_r = 26;
	f->clr_g = 50;
	f->clr_b = 25;
	f->clr = f->clr_a << 28 | f->clr_r << 18 | f->clr_g << 7 | f->clr_b << 0;
	f->master.clr = f->clr;
}

static void		iteration(t_fractol *f, int x, int y)
{
	int			i;
	double		tmp;
	t_thread	*ptr;

	ptr = &f->thread[f->id];
	i = 0;
	ptr->zr = 0;
	ptr->zi = 0;
	ptr->cr = x / ptr->zoom + ptr->x1;
	ptr->ci = y / ptr->zoom + ptr->y1;
	while (ptr->zr * ptr->zr + ptr->zi * ptr->zi < 4 && i < ptr->imax)
	{
		tmp = ptr->zr;
		ptr->zr = ptr->zr * ptr->zr - ptr->zi * ptr->zi + ptr->cr;
		ptr->zi = -2 * ptr->zi * tmp + ptr->ci;
		i++;
	}
	(i != ptr->imax) ? fractol_mlx_pixel(f, x, y, i * ptr->clr) : (0);
}

void			tricorn(t_fractol *f)
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
