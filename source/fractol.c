/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdobos2 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 22:58:11 by pdobos2           #+#    #+#             */
/*   Updated: 2017/06/22 22:58:13 by pdobos2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		print_intro(void)
{
	ft_putstr(" Apasam  <  >  pentru rotirea ");
	ft_putstr("\n");
}

static int		fractol_make(t_fractol *f)
{
	(f->ftype == 4) ? exit_redcross() : (0);
	(DBG_REND) ? ft_putstr_fd(STAT_BG, 2) : (0);
	fractol_generator(f);
	mlx_hook(f->mlx.win, 6, (1L << 6), &fractol_mouse_julia, f);
	mlx_hook(f->mlx.win, 2, (1L << 0), &fractol_keyhook, f);
	mlx_hook(f->mlx.win, 17, (1L << 17), &exit_redcross, f);
	mlx_mouse_hook(f->mlx.win, &fractol_mouse, f);
	mlx_loop(f->mlx.mlx);
	return (0);
}

static void		ft_error(void)
{
	ft_putstr(ERR_PARR);
}

static int		ft_check_params(int argc, char **argv)
{
	if (argc != 2)
		ft_error();
	if (ft_strcmp("mandelbrot", argv[1]) == 0)
		return (0);
	if (ft_strcmp("julia", argv[1]) == 0)
		return (1);
	if (ft_strcmp("carpet", argv[1]) == 0)
		return (2);
	if (ft_strcmp("bship", argv[1]) == 0)
		return (3);
	return (4);
}

int				main(int argc, char **argv)
{
	t_fractol	f;

	print_intro();
	f = *fractol_ptr(&f, 0);
	f.finit = 1;
	f.ftype = ft_check_params(argc, argv);
	f.j_locker = 0;
	f.mlx.mlx = mlx_init();
	f.mlx.win = mlx_new_window(f.mlx.mlx, WIN_X, WIN_Y, "Fractol :");
	ft_putstr(ft_itoa(f.ftype));
	fractol_make(&f);
	return (0);
}
