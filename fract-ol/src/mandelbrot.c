/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:04:13 by fbecht            #+#    #+#             */
/*   Updated: 2023/02/21 14:04:17 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_iter(int col, int row, int iter_max)
{
	double	x;
	double	x_new;
	double	y;
	int		iter;

	x = 0;
	y = 0;
	iter = 0;
	while (x * x + y * y <= 4 && iter < iter_max)
	{
		x_new = x * x - y * y + MANDEL_C_RE;
		y = 2 * x * y + MANDEL_C_IM;
		x = x_new;
		iter++;
	}
	return (iter);
}

int	calc_color(int iter, int iter_max)
{
	int	cs;
	int	rgb[3];
	double	div;

	cs = 2;
	div = (double)iter / iter_max;
	if (cs < 3)
	{
		rgb[cs % 3] = 9 * (1 - div) * pow(div, 3) * 255;
		rgb[(cs + 1) % 3] = 15 * pow((1 - div), 2) * pow(div, 2) * 255;
		rgb[(cs + 2) % 3] = 9 * pow((1 - div), 3) * div * 255;
	}
	else
	{
		cs -= 3;
		rgb[cs % 3] = 9 * pow((1 - div), 3) * div * 255;
		rgb[(cs + 1) % 3] = 15 * pow((1 - div), 2) * pow(div, 2) * 255;
		rgb[(cs + 2) % 3] = 9 * (1 - div) * pow(div, 3) * 255;
	}
	return (0 << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

void	mandelbrot(t_data *data, int iter_max)
{
	int	row;
	int	col;
	int	iter;

	row = -1;
	while (++row <= WINDOW_HEIGHT)
	{
		col = -1;
		while (++col <= WINDOW_WIDTH)
		{
			iter = mandelbrot_iter(col, row, iter_max);
			if (iter < iter_max)
				//img_pixel_put(&data->img, col, row, COLOR_YELLOW / iter);
				//img_pixel_put(&data->img, col, row, encode_rgb(0, 200, 255 - (iter % 256), 255 - (iter % 256)));
				img_pixel_put(&data->img, col, row, calc_color(iter, iter_max));
			else
				img_pixel_put(&data->img, col, row, COLOR_BLACK);
		}
	}
}
