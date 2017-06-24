/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdobos2 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 22:24:59 by pdobos2           #+#    #+#             */
/*   Updated: 2017/06/22 22:25:01 by pdobos2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		fractol_thread_cutter(t_fractol *f, int thread_id)
{
	t_thread	*ptr;

	f->id = thread_id;
	ptr = &f->thread[f->id];
	(f->id == 0) ? ptr->t_mx = WIN_X / 2 : (0);
	(f->id == 0) ? ptr->t_my = WIN_Y / 2 : (0);
	(f->id == 0) ? ptr->t_x = 0 : (0);
	(f->id == 0) ? ptr->t_y = 0 : (0);
	(f->id == 1) ? ptr->t_mx = WIN_X : (0);
	(f->id == 1) ? ptr->t_my = WIN_Y / 2 : (0);
	(f->id == 1) ? ptr->t_x = WIN_X / 2 : (0);
	(f->id == 1) ? ptr->t_y = 0 : (0);
	(f->id == 2) ? ptr->t_mx = WIN_X / 2 : (0);
	(f->id == 2) ? ptr->t_my = WIN_Y : (0);
	(f->id == 2) ? ptr->t_x = 0 : (0);
	(f->id == 2) ? ptr->t_y = WIN_Y / 2 : (0);
	(f->id == 3) ? ptr->t_mx = WIN_X : (0);
	(f->id == 3) ? ptr->t_my = WIN_Y : (0);
	(f->id == 3) ? ptr->t_x = WIN_X / 2 : (0);
	(f->id == 3) ? ptr->t_y = WIN_Y / 2 : (0);
}

static void		fractol_thread_splitter(t_fractol *f)
{
	int		i;

	i = 0;
	while (i < MAX_MT)
	{
		f->thread[i].ftype = f->ftype;
		f->thread[i].imax = f->master.imax;
		f->thread[i].img_x = f->master.img_x;
		f->thread[i].img_y = f->master.img_y;
		f->thread[i].clr = f->master.clr;
		f->thread[i].zfactor = f->master.zfactor;
		f->thread[i].zoom = f->master.zoom;
		f->thread[i].x1 = f->master.x1;
		f->thread[i].x2 = f->master.x2;
		f->thread[i].y1 = f->master.y1;
		f->thread[i].y2 = f->master.y2;
		f->thread[i].cr = f->master.cr;
		f->thread[i].ci = f->master.ci;
		f->thread[i].zr = f->master.zr;
		f->thread[i].zi = f->master.zi;
		fractol_thread_cutter(f, i);
		i++;
	}
}

void			*fractol_launcher(void *i)
{
	t_fractol	*f;

	f = NULL;
	f = fractol_ptr(f, 1);
	if (f->finit)
	{
		f->ftype == T_MDB ? mandelbrot(f) : (0);
		f->ftype == T_JLA ? julia(f) : (0);
		f->ftype == T_BRS ? burningship(f) : (0);
		f->ftype == T_TRC ? tricorn(f) : (0);
		return (NULL);
	}
	f->id = (int)i;
	f->thread[f->id].ftype == T_MDB ? mandelbrot(f) : (0);
	f->thread[f->id].ftype == T_JLA ? julia(f) : (0);
	f->thread[f->id].ftype == T_BRS ? burningship(f) : (0);
	f->thread[f->id].ftype == T_TRC ? tricorn(f) : (0);
	return (NULL);
}

int				fractol_generator(t_fractol *f)
{
	int			i;
	pthread_t	trd[MAX_MT];

	i = 0;
	(DBG_REND) ? ft_putstr_fd(STAT_BUSY, 2) : (0);
	if (f->finit)
		fractol_launcher((void*)(uintptr_t)f->id);
	fractol_thread_splitter(f);
	f->mlx.img = mlx_new_image(f->mlx.mlx, WIN_X, WIN_Y);
	while (i < MAX_MT)
	{
		pthread_create(&trd[i], NULL, fractol_launcher, (void*)(uintptr_t)(i));
		pthread_join(trd[i], NULL);
		i++;
	}
	i = 0;
	while (i < MAX_MT)
		pthread_join(trd[i++], NULL);
	fractol_gui_footer(f, 0x000000);
	mlx_put_image_to_window(f->mlx.mlx, f->mlx.win, f->mlx.img, 0, 0);
	mlx_destroy_image(f->mlx.mlx, f->mlx.img);
	fractol_gui_telemetry(f, 0, 0);
	(DBG_REND) ? ft_putstr_fd(STAT_IDLE, 2) : (0);
	return (0);
}
