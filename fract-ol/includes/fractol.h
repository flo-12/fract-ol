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

# define MANDEL_C_RE ((col - WINDOW_WIDTH / 2.0) * 4.0 / WINDOW_WIDTH)
# define MANDEL_C_IM ((row - WINDOW_HEIGHT / 2.0) * 4.0 / WINDOW_WIDTH)

typedef struct s_img2
{
	void	*image;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}			t_img2;

typedef struct s_data {
	void	*mlx;
	void	*win;
	t_img2	img;
}			t_data;

/* UTILS_MLX */
void	img_pixel_put(t_img2 *img, int x, int y, int color);
int		encode_rgb(int t, int red, int green, int blue);

/* EXIT_FRACTOLS */
void	exit_fractol(t_data *data, int failure, char *text);

/* MLX_HOOKS */
int		handle_keypress(int key, t_data *data);
int		handle_destroy(t_data *data);

/* MANDELBROT */
void	mandelbrot(t_data *data, int max);

#endif
