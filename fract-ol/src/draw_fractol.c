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

int	iterate(t_fractol fract, double x_init, double y_init)
{
	double	x;
	double	x_new;
	double	y;
	int		iter;
	int		lim;

	x = x_init;
	y = y_init;
	iter = 0;
	lim = 4;
	while (x * x + y * y <= lim && iter < fract.iter_max)
	{
		x_new = x * x - y * y + fract.c_re;
		y = 2 * x * y + fract.c_im;
		x = x_new;
		iter++;
	}
	return (iter);
}

int	iter_fractol(double col, double row, t_data *data)
{
	if (data->fract.fractol == 'M')
	{
		//data->fract.c_re = -2 + col / WINDOW_WIDTH * (4);
		data->fract.c_re = 4 * col / WINDOW_WIDTH - 2;
		return (iterate(data->fract, 0, 0));
	}
	else
		return (iterate(data->fract,
				(data->fract.r * (2 * col - WINDOW_WIDTH) / WINDOW_WIDTH),
				(data->fract.r * (2 * row - WINDOW_HEIGHT) / WINDOW_HEIGHT)));
		/*return (iterate(data->fract,
				(2 * (2 * col - WINDOW_WIDTH) / WINDOW_WIDTH),
				(2 * (2 * row - WINDOW_HEIGHT) / WINDOW_HEIGHT)));*/
}

void	draw_fractol(t_data *data)
{
	double	row;
	double	col;
	int		iter;
	int		x;
	int		y;

	y = -1;
	row = data->fract.row_min;
	while (++y <= WINDOW_HEIGHT)
	{
		if (data->fract.fractol == 'M')
			/*data->fract.c_im =  (-2 + 4 *WINDOW_HEIGHT / WINDOW_WIDTH)
				+ row * (-2 - (-2 + 4 *WINDOW_HEIGHT / WINDOW_WIDTH)) / WINDOW_HEIGHT;*/
			//data->fract.c_im = (2 * WINDOW_HEIGHT / WINDOW_WIDTH + 2) * row / WINDOW_HEIGHT - 2;
			data->fract.c_im = 4 * row / WINDOW_HEIGHT - 2;
		col = data->fract.col_min;
		x = -1;
		while (++x <= WINDOW_WIDTH)
		{
			iter = iter_fractol(col, row, data);
			img_pixel_put(&data->img, x, y, calc_color(iter,
					data->fract.iter_max, data->fract.color_set, data));
			col += 1 / (double)data->fract.zoom;
		}
		row += 1 / (double)data->fract.zoom;
	}
}
