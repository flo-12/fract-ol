/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:42:13 by fbecht            #+#    #+#             */
/*   Updated: 2023/02/14 18:42:15 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"
# include "keys.h"
# include "colors.h"
# include "messages.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <math.h>

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 600
# define ZOOM_FACTOR 1.1
# define COLOR_SET 0
# define ITER_MAX 150
# define JULIA_C_RE -0.79
# define JULIA_C_IM 0.15

typedef struct s_fractol
{
	int		iter_max;
	double	zoom;
	int		centre[2];
	int		row_min;
	int		row_max;
	int		col_min;
	int		col_max;
	double	c_re;
	double	c_im;
	double	c_re_var;
	double	c_im_var;
	int		color_set;
	char	fractol;
	double	r;
}			t_fractol;

typedef struct s_img2
{
	void	*image;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}			t_img2;

typedef struct s_data {
	void		*mlx;
	void		*win;
	t_img2		img;
	t_fractol	fract;
}			t_data;

/* INIT_DATA */
void	init_data(t_data *data, int argc, char **argv);
void	get_julia_c(t_data *data, int argc, char **argv);
//int		check_digit(char *str);
void	set_fractol_parameters(char fractol, double c_re, double c_im, t_data *data);

/* UTILS_MLX */
void	img_pixel_put(t_img2 *img, int x, int y, int color);
int		encode_rgb(int t, int red, int green, int blue);

/* EXIT_FRACTOLS */
void	exit_fractol(t_data *data, int failure, char *text);

/* MLX_HOOKS */
int		handle_keypress(int key, t_data *data);
int		handle_destroy(t_data *data);
int		hook_mouse(int key, int x, int y, t_data *data);

/* DRAW_FRACTOL */
void	draw_fractol(t_data *data);

/* CALC_COLOR */
int	calc_color(int iter, int iter_max, int cs, t_data *data);

#endif
