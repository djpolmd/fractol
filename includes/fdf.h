/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdobos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 22:00:28 by pdobos            #+#    #+#             */
/*   Updated: 2017/01/30 22:00:30 by pdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft1/includes/libft.h"
# include "ft_cod_key.h"
# include <math.h>
# include <mlx.h>
# include "fcntl.h"

# define MYNAME		"FDF -  Fil de Fer - pdobos"
# define CLINE 		"\t\e[90m—————————————————————————————\e[0m"
# define COLOR_L		"\033[1;36m"
# define DEBUG			0
# define ERR_ARG		" Numar gresit de argumente -  ./test maps.fdf"
# define ERR_NO_OPEN	"File error: nu pot dischide fisieru!"
# define ERR_MALLOC		"Malloc Erroare."
# define ERR_NOT_NUM	"Map error: numere nu au fost de gasit."
# define ERR_NOT_EQU	"Map error:  Linii nu sunt egale."
# define ERR_ASCII		"Map error:  ascii charactere nu au fost de gasit."

typedef struct	s_line
{
	float		a;
	float		b;
	float		c;
}				t_line;

typedef struct	s_pxl
{
	int			x;
	int			y;
	int			h;
	int			x1;
	int			y1;
	int			h1;
}				t_pxl;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
}				t_mlx;

typedef struct	s_fdf
{
	char		*name;
	t_mlx		mlx;
	int			win_x;
	int			win_y;
	t_pxl		**map;
	int			map_x;
	int			map_y;
	int			map_max;
	int			height;
	int			zoom;
	int			speed;
	int			clr;
	float		pos_x;
	float		pos_y;
	float		pos_z;
}				t_fdf;

t_fdf			*hook_drow(t_fdf *f);
void			fdf_parser(t_fdf *f);
void			fdf_recalc(t_fdf *f, int x, int y);
void			fdf_img_gen(t_fdf *f);
int				fdf_mlx_img(t_fdf *f, t_pxl a);
void			fdf_screeninfo(t_fdf *f);
void			fdf_error(char *reason);
static void		fractol_background(t_fractol *f, int x, int y);
static void		print_intro(void);

#endif
