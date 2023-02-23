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
# define ZOOM_FACTOR 0.2

# define MANDEL_C_RE ((col - (WINDOW_WIDTH * zoom) / 2.0) * 4.0 / (WINDOW_WIDTH * zoom))
# define MANDEL_C_IM ((row - (WINDOW_HEIGHT * zoom) / 2.0) * 4.0 / (WINDOW_HEIGHT * zoom))

typedef struct s_fractol
{
	int		iter_max;
	double	zoom;
	int		row_min;
	int		row_max;
	int		col_min;
	int		col_max;
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

/* UTILS_MLX */
void	img_pixel_put(t_img2 *img, int x, int y, int color);
int		encode_rgb(int t, int red, int green, int blue);

/* EXIT_FRACTOLS */
void	exit_fractol(t_data *data, int failure, char *text);

/* MLX_HOOKS */
int		handle_keypress(int key, t_data *data);
int		handle_destroy(t_data *data);
int		hook_mouse(int key, int x, int y, t_data *data);

/* MANDELBROT */
void	mandelbrot(t_data *data);

#endif
