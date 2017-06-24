/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onscreen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdobos2 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 22:25:09 by pdobos2           #+#    #+#             */
/*   Updated: 2017/06/22 22:25:10 by pdobos2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		fractol_gui_colors(t_fractol *f, int off_x, int off_y)
{
	char		**tmp;
	char		*rt;

	tmp = ft_sstrnew(8);
	tmp[0] = ft_strdup("Alpfa: ");
	tmp[1] = ft_itoa(f->clr_a);
	tmp[2] = ft_strdup(" Red:");
	tmp[3] = ft_itoa(f->clr_r);
	tmp[4] = ft_strdup(" Green:");
	tmp[5] = ft_itoa(f->clr_g);
	tmp[6] = ft_strdup(" Blue:");
	tmp[7] = ft_itoa(f->clr_b);
	rt = ft_sstrtostr(tmp, "");
	off_x = (WIN_X - (ft_strlen(rt) * 10)) / 2;
	mlx_string_put(f->mlx.mlx, f->mlx.win, off_x, off_y, 0xFFFFFF, rt);
	tmp ? ft_sstrdel(tmp) : (0);
	rt ? ft_memdel((void *)&rt) : (0);
}

void			fractol_gui_telemetry(t_fractol *f, int off_x, int off_y)
{
	char		**tmp;
	char		*rt;

	off_y = WIN_Y - 30;
	mlx_string_put(f->mlx.mlx, f->mlx.win, 25, off_y, 0x3366FF, "Fractal:");
	mlx_string_put(f->mlx.mlx, f->mlx.win, 45, off_y, 0xFF3300, f->fname);
	if (f->ftype == T_JLA && f->j_locker)
		mlx_string_put(f->mlx.mlx, f->mlx.win, 100, off_y, 0xFF0000, "[LOCK]");
	tmp = ft_sstrnew(5);
	tmp[0] = ft_strdup("Zoom:");
	tmp[1] = ft_itoa(f->master.zfactor);
	tmp[2] = ft_strdup("x ");
	tmp[3] = ft_strdup("Iteration:");
	tmp[4] = ft_itoa(f->master.imax);
	rt = ft_sstrtostr(tmp, "");
	off_x = WIN_X - (ft_strlen(rt) * 10 + 5);
	mlx_string_put(f->mlx.mlx, f->mlx.win, off_x, off_y, 0xFFFF45, rt);
	tmp ? ft_sstrdel(tmp) : (0);
	rt ? ft_memdel((void *)&rt) : (0);
	fractol_gui_colors(f, 0, off_y);
}

static void		fractol_mire(t_fractol *f)
{
	int			x;
	int			y;

	x = 0;
	y = WIN_Y / 2;
	while (x < WIN_X)
	{
		fractol_mlx_pixel(f, x, y, 0xFFFFFF);
		x++;
	}
	x = WIN_X / 2;
	y = 0;
	while (y < WIN_Y)
	{
		fractol_mlx_pixel(f, x, y, 0xFFFFFF);
		y++;
	}
}

void			fractol_gui_footer(t_fractol *f, int color)
{
	int			x;
	int			y;

	y = WIN_Y - 35;
	while (y < WIN_Y)
	{
		x = 0;
		while (x < WIN_X)
		{
			fractol_mlx_pixel(f, x, y, color);
			x++;
		}
		y++;
	}
	if (DBG_MIRE)
		fractol_mire(f);
}
