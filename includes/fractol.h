/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdobos2 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 00:51:53 by pdobos2           #+#    #+#             */
/*   Updated: 2017/06/23 00:51:55 by pdobos2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "keys.h"
# include <mlx.h>
# include <math.h>
# include <pthread.h>
# include <unistd.h>

# define DBG_REND	1
# define DBG_MIRE	0

# define WIN_X		1400
# define WIN_Y		900
# define WIN_CX		WIN_X / 2
# define WIN_CY		WIN_Y / 2
# define MAX_MT		4
# define MAX_ZOOM	50
# define MAX_ITER	300

# define F_DZOOM	320
# define F_DMOVE	5
# define F_DIMAX	80
# define F_DCLR_A	0
# define F_DCLR_R	120
# define F_DCLR_G	130
# define F_DCLR_B	40

# define T_MDB		0
# define T_JLA		1
# define T_BRS		2
# define T_TRC		3
# define MLX_LEFT	0
# define MLX_CENTER	1
# define MLX_RIGHT	2

# define ERR_MISS	"Fractol fatal error: cannot find: [ "
# define ERR_PARR	"Wrong parameter!!!"
# define STAT_BG	"\n\t Make rendering ,-) [      ] "
# define STAT_IDLE	"\e[7D\e[1;32mIDLE\e[0m\e[3C"
# define STAT_BUSY	"\e[7D\e[1;31mBUSY\e[0m\e[3C"

typedef struct		s_thread
{
	int				ftype;
	int				imax;
	int				img_x;
	int				img_y;
	unsigned int	clr;
	int				zfactor;
	double			zoom;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			cr;
	double			ci;
	double			zr;
	double			zi;
	int				t_x;
	int				t_mx;
	int				t_y;
	int				t_my;
}					t_thread;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
}					t_mlx;

typedef struct		s_fractol
{
	t_mlx			mlx;
	int				selected;
	int				finit;
	char			*fname;
	int				ftype;
	int				madness;
	int				j_locker;
	unsigned int	clr_a;
	unsigned int	clr_r;
	unsigned int	clr_g;
	unsigned int	clr_b;
	unsigned int	clr;
	t_thread		master;
	t_thread		thread[MAX_MT];
	int				id;
	int				mthread_x;
	int				mthread_mx;
	int				mthread_y;
	int				mthread_my;
	double			tmp_x;
	double			tmp_y;
	double			tmp_x2;
	double			tmp_y2;
}					t_fractol;

/*
** Fractol core function
*/

t_fractol			*fractol_ptr(t_fractol *f, int tag);
int					fractol_selector(t_fractol *f, int off_x, int off_y);

/*
** Fractal algorithm
*/

void				mandelbrot(t_fractol *f);
void				julia(t_fractol *f);
void				burningship(t_fractol *f);
void				tricorn(t_fractol *f);

/*
** MLX events hook
*/

void				fractol_colors(t_fractol *f, int key);
int					fractol_keyhook(int key, t_fractol *f);
int					fractol_mouse(int key, int x, int y, t_fractol *f);
int					fractol_mouse_julia(int x, int y, t_fractol *f);
int					exit_redcross(void);

/*
** MLX Draw and redistribute function
*/

int					fractol_generator(t_fractol *f);
void				fractol_mlx_image(t_fractol *f, char *img, int x, int y);
void				fractol_mlx_pixel(t_fractol *f, int x, int y, int color);
void				fractol_gui_footer(t_fractol *f, int color);
void				fractol_gui_telemetry(t_fractol *f, int off_x, int off_y);

#endif
