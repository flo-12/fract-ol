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

int	mandelbrot_iter(int col, int row, double zoom, int iter_max)
{
	double	x;
	double	x_new;
	double	y;
	int		iter;

	x = 0;
	y = 0;
	iter = 0;
	while (pow(x, 2) + pow(y, 2) <= 4 && iter < iter_max)
	{
		x_new = pow(x, 2) - pow(y, 2) + MANDEL_C_RE;
		y = 2 * x * y + MANDEL_C_IM;
		x = x_new;
		iter++;
	}
	return (iter);
}

static int	calc_color(int iter, int iter_max)
{
	int		cs;
	int		rgb[3];
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

void	mandelbrot(t_data *data)
{
	int	row;
	int	col;
	int	iter;
	int	x;
	int	y;

	y = -1;
	row = data->fract.row_min;
	while (++y <= WINDOW_HEIGHT)
	{
		col = data->fract.col_min;
		x = -1;
		while (++x <= WINDOW_WIDTH)
		{
			iter = mandelbrot_iter(col, row, data->fract.zoom,
					data->fract.iter_max);
			if (iter < data->fract.iter_max)
				img_pixel_put(&data->img, x, y,
					calc_color(iter, data->fract.iter_max));
			else
				img_pixel_put(&data->img, x, y, COLOR_BLACK);
			col++;
		}
		row++;
	}
}
