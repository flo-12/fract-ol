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

int	mandelbrot_iter(t_fractol fract)
{
	double	x;
	double	x_new;
	double	y;
	int		iter;

	x = 0;
	y = 0;
	iter = 0;
	while (x * x + y * y <= 4 && iter < fract.iter_max)
	{
		x_new = x * x - y * y + fract.c_re;
		y = 2 * x * y + fract.c_im;
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
		rgb[cs % 3] = 9 * (1 - div) * div * div * div * 255;
		rgb[(cs + 1) % 3] = 15 * ((1 - div) * (1 - div)) * (div * div) * 255;
		rgb[(cs + 2) % 3] = 9 * ((1 - div) * (1 - div) * (1 - div)) * div * 255;
	}
	else
	{
		cs -= 3;
		rgb[cs % 3] = 9 * ((1 - div) * (1 - div) * (1 - div)) * div * 255;
		rgb[(cs + 1) % 3] = 15 * ((1 - div) * (1 - div)) * (div * div) * 255;
		rgb[(cs + 2) % 3] = 9 * (1 - div) * (div * div * div) * 255;
	}
	return (0 << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

void	mandelbrot(t_data *data)
{
	double	row;
	double	col;
	int	iter;
	int	x;
	int	y;

	y = -1;
	row = data->fract.row_min;
	while (++y <= WINDOW_HEIGHT)
	{
		data->fract.c_im = 4 * row / WINDOW_HEIGHT - 2;
		col = data->fract.col_min;
		x = -1;
		while (++x <= WINDOW_WIDTH)
		{
			data->fract.c_re = 4 * col / WINDOW_WIDTH - 2;
			iter = mandelbrot_iter(data->fract);
			if (iter < data->fract.iter_max)
				img_pixel_put(&data->img, x, y,
					calc_color(iter, data->fract.iter_max));
			else
				img_pixel_put(&data->img, x, y, COLOR_BLACK);
			//col++;
			col += 1 / (double)data->fract.zoom;
		}
		//row++;
		row += 1 / (double)data->fract.zoom;
	}
}
