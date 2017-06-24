/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdobos2 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 22:24:48 by pdobos2           #+#    #+#             */
/*   Updated: 2017/06/22 22:24:50 by pdobos2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				fractol_mouse_julia(int x, int y, t_fractol *f)
{
	if (x >= WIN_X || y >= WIN_Y || x <= 0 || y <= 0 || f->ftype != T_JLA)
		return (1);
	if (f->ftype == T_JLA && f->j_locker == 1)
		return (1);
	f->master.cr = (float)(x + WIN_CX) / (WIN_X * 2);
	f->master.ci = (float)(y + WIN_CY) / (WIN_Y * 2);
	fractol_generator(f);
	return (0);
}

void			fractol_zoom(t_fractol *f, int x, int y, int sense)
{
	f->tmp_x = f->master.x1 + x * (f->master.x2 - f->master.x1) / WIN_X;
	f->tmp_y = f->master.y1 + y * (f->master.y2 - f->master.y1) / WIN_Y;
	f->tmp_x2 = f->master.x1;
	f->tmp_y2 = f->master.y1;
	if (sense)
	{
		f->master.zoom *= 2;
		f->master.x1 = f->tmp_x - (f->master.x2 - f->master.x1) / 4;
		f->master.x2 = f->tmp_x + (f->master.x2 - f->tmp_x2) / 4;
		f->master.y1 = f->tmp_y - (f->master.y2 - f->master.y1) / 4;
		f->master.y2 = f->tmp_y + (f->master.y2 - f->tmp_y2) / 4;
		f->master.zfactor++;
	}
	else
	{
		f->master.zoom /= 2;
		f->master.x1 = f->tmp_x - (f->master.x2 - f->master.x1);
		f->master.x2 = f->tmp_x + (f->master.x2 - f->tmp_x2);
		f->master.y1 = f->tmp_y - (f->master.y2 - f->master.y1);
		f->master.y2 = f->tmp_y + (f->master.y2 - f->tmp_y2);
		f->master.zfactor--;
	}
}

static void		fractol_move(t_fractol *f, int key)
{
	int			x;
	int			y;

	x = WIN_CX;
	y = WIN_CY;
	(key == K_AR_U) ? y = WIN_CY - F_DMOVE : (0);
	(key == K_AR_D) ? y = WIN_CY + F_DMOVE : (0);
	(key == K_AR_L) ? x = WIN_CX - F_DMOVE : (0);
	(key == K_AR_R) ? x = WIN_CX + F_DMOVE : (0);
	fractol_zoom(f, x, y, 1);
	fractol_zoom(f, x, y, 0);
}

int				fractol_mouse(int key, int x, int y, t_fractol *f)
{
	if ((key == M_SCROL_P || key == M_CLICK_L) && f->master.zfactor < MAX_ZOOM)
		fractol_zoom(f, x, y, 1);
	if ((key == M_SCROL_N || key == M_CLICK_R) && f->master.zfactor > 0)
		fractol_zoom(f, x, y, 0);
	if (key == M_CLICK_M || f->master.zfactor == 1)
		f->finit = 1;
	return (fractol_generator(f));
}

int				fractol_keyhook(int key, t_fractol *f)
{
	(key == K_ESC) ? exit_redcross() : (0);
	(key == K_ITER_P && f->master.imax < MAX_ITER) ? f->master.imax += 10 : (0);
	(key == K_ITER_N && f->master.imax) ? f->master.imax -= 10 : (0);
	(key == K_1) ? f->ftype = T_MDB : (0);
	(key == K_2) ? f->ftype = T_JLA : (0);
	(key == K_3) ? f->ftype = T_BRS : (0);
	(key == K_4) ? f->ftype = T_TRC : (0);
	if (key == K_1 || key == K_2 || key == K_3 || key == K_4)
	{
		f->finit++;
	}
	if (key == K_AR_U || key == K_AR_D || key == K_AR_L || key == K_AR_R)
		fractol_move(f, key);
	if (key == K_NUM_P && f->master.zfactor < MAX_ZOOM)
		fractol_zoom(f, WIN_CX, WIN_CY, 1);
	if (key == K_NUM_N && f->master.zfactor > 0)
		fractol_zoom(f, WIN_CX, WIN_CY, 0);
	if (key == K_L)
		f->j_locker = (f->j_locker) ? 0 : 1;
	fractol_colors(f, key);
	return (fractol_generator(f));
}
