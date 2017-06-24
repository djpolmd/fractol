/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdobos2 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 22:24:37 by pdobos2           #+#    #+#             */
/*   Updated: 2017/06/22 22:24:39 by pdobos2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			fractol_mlx_image(t_fractol *f, char *img, int x, int y)
{
	int			tx;
	int			ty;
	int			off_x;
	int			off_y;

	f->mlx.img = mlx_xpm_file_to_image(f->mlx.mlx, img, &tx, &ty);
	if (f->mlx.img == NULL)
	{
		ft_putstr_fd("\e[1;31m", 2);
		ft_putstr_fd(ERR_MISS, 2);
		ft_putstr_fd(img, 2);
		ft_putendl_fd(" ]\e[0m", 2);
		exit_redcross();
	}
	x == MLX_LEFT ? off_x = 0 : (0);
	x == MLX_CENTER ? off_x = (WIN_X - tx) / 2 : (0);
	x == MLX_RIGHT ? off_x = (WIN_X - tx) : (0);
	y == MLX_LEFT ? off_y = 0 : (0);
	y == MLX_CENTER ? off_y = (WIN_Y - ty) / 2 : (0);
	y == MLX_RIGHT ? off_y = (WIN_Y - ty) : (0);
	mlx_put_image_to_window(f->mlx.mlx, f->mlx.win, f->mlx.img, off_x, off_y);
	mlx_destroy_image(f->mlx.mlx, f->mlx.img);
}

int				exit_redcross(void)
{
	ft_putendl_fd("", 2);
	exit(EXIT_SUCCESS);
}

t_fractol		*fractol_ptr(t_fractol *f, int tag)
{
	static t_fractol *tmp;

	(tag) ? (0) : (tmp = f);
	return (tmp);
}

void			fractol_mlx_pixel(t_fractol *f, int x, int y, int color)
{
	char	*px;
	int		bpp;
	int		endian;
	int		len;
	int		*tmp;

	if (x >= WIN_X || y >= WIN_Y || x < 0 || y < 0)
		return ;
	px = mlx_get_data_addr(f->mlx.img, &bpp, &len, &endian);
	tmp = (int *)&px[(y * len) + (x * (bpp / 8))];
	*tmp = color;
}

void			fractol_colors(t_fractol *f, int key)
{
	(key == K_ALPHA_P) ? f->clr_a += 10 : (0);
	(key == K_ALPHA_N) ? f->clr_a -= 10 : (0);
	(key == K_ALPHA_Z) ? f->clr_a = 0 : (0);
	(key == K_RED_P) ? f->clr_r += 10 : (0);
	(key == K_RED_N) ? f->clr_r -= 10 : (0);
	(key == K_RED_Z) ? f->clr_r = 0 : (0);
	(key == K_GREEN_P) ? f->clr_g += 10 : (0);
	(key == K_GREEN_N) ? f->clr_g -= 10 : (0);
	(key == K_GREEN_Z) ? f->clr_g = 0 : (0);
	(key == K_BLUE_P) ? f->clr_b += 10 : (0);
	(key == K_BLUE_N) ? f->clr_b -= 10 : (0);
	(key == K_BLUE_Z) ? f->clr_b = 0 : (0);
	f->clr_a >= 255 ? f->clr_a = 255 : (0);
	f->clr_r >= 255 ? f->clr_r = 255 : (0);
	f->clr_g >= 255 ? f->clr_g = 255 : (0);
	f->clr_b >= 255 ? f->clr_b = 255 : (0);
	f->clr_a <= 0 ? f->clr_a = 0 : (0);
	f->clr_r <= 0 ? f->clr_r = 0 : (0);
	f->clr_g <= 0 ? f->clr_g = 0 : (0);
	f->clr_b <= 0 ? f->clr_b = 0 : (0);
	f->clr = f->clr_a << 24 | f->clr_r << 16 | f->clr_g << 8 | f->clr_b << 0;
	f->master.clr = f->clr;
}
