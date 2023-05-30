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

# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 600
# define ZOOM_FACTOR 2.0
# define COLOR_SET 0
# define ITER_MAX 150
# define JULIA_C_RE -0.79
# define JULIA_C_IM 0.15

/*typedef struct s_c_val
{
	double	c_re;
	double	c_im;
}			t_c_val;*/

typedef struct s_r_val
{
	double	r_re;
	double	r_im;
}			t_r_val;

typedef struct s_shift
{
	double	s_re;
	double	s_im;
}			t_shift;

typedef struct s_fractol
{
	int			iter_max;
	double		zoom;
	double		c_iter[2];
	double		c_julia[2];
	double		c_mandel[2];
	int			color_set;
	char		fractol;
	t_r_val		r;
	t_shift		s;
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
void	set_julia_arg_c(t_data *data, int argc, char **argv);
void	init_fractol(t_data *data, int argc, char **argv);
void	set_fractol_parameters(char fractol, double c_re, double c_im,
			t_data *data);

/* UTILS_MLX */
void	img_pixel_put(t_img2 *img, int x, int y, int color);
int		encode_rgb(int t, int red, int green, int blue);

/* EXIT_FRACTOLS */
void	exit_fractol(t_data *data, int failure, char *text);

/* MLX_HOOKS */
int		handle_keypress(int key, t_data *data);
int		handle_destroy(t_data *data);
int		hook_mouse(int key, int x, int y, t_data *data);

/* UTILS_KEY_HOOKS */
void	reset_fractol(t_data *data);
void	julia_from_mandel(t_data *data);
void	change_color_set(int key, t_data *data);
void	change_iter_max(int key, t_data *data);
void	reset_default_fractol(char fract, t_data *data);

/* DRAW_FRACTOL */
void	put_fractol(t_data *data);
void	set_c_z_iter(double arr[2], double col, double row,
			t_fractol fract);

/* CALC_COLOR */
int		calc_color(int iter, int iter_max, int cs, t_data *data);

#endif
