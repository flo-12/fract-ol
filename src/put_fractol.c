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

int	iterate(double c_val[2], double z_init[2], int iter_max)
{
	double	z_re;
	double	z_re_new;
	double	z_im;
	int		iter;

	z_re = z_init[0];
	z_im = z_init[1];
	iter = 0;
	while (z_re * z_re + z_im * z_im <= 4 && iter < iter_max)
	{
		z_re_new = z_re * z_re - z_im * z_im + c_val[0];
		z_im = 2 * z_re * z_im + c_val[1];
		z_re = z_re_new;
		iter++;
	}
	return (iter);
}

void	set_c_z_iter(double arr[2], double col, double row, t_fractol fract)
{
	arr[0] = fract.r.r_re * (2 * col - WINDOW_WIDTH) / WINDOW_WIDTH
		+ fract.s.s_re;
	arr[1] = fract.r.r_im * (2 * row - WINDOW_HEIGHT) / WINDOW_HEIGHT
		+ fract.s.s_im;
}

int	iter_fractol(double col, double row, t_data *data)
{
	double	z_init[2];

	if (data->fract.fractol == 'M')
	{
		set_c_z_iter(data->fract.c_iter, col, row, data->fract);
		z_init[0] = 0;
		z_init[1] = 0;
	}
	else
		set_c_z_iter(z_init, col, row, data->fract);
	return (iterate(data->fract.c_iter, z_init, data->fract.iter_max));
}

void	put_fractol(t_data *data)
{
	int		iter;
	int		x;
	int		y;

	y = -1;
	while (++y <= WINDOW_HEIGHT)
	{
		x = -1;
		while (++x <= WINDOW_WIDTH)
		{
			iter = iter_fractol(x, y, data);
			img_pixel_put(&data->img, x, y, calc_color(iter,
					data->fract.iter_max, data->fract.color_set, data));
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.image, 0, 0);
}
