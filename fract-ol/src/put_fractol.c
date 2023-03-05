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

int	iterate(t_c_val c_val, double z_re_init, double z_im_init, int iter_max)
{
	double	z_re;
	double	z_re_new;
	double	z_im;
	int		iter;

	z_re = z_re_init;
	z_im = z_im_init;
	iter = 0;
	while (z_re * z_re + z_im * z_im <= 4 && iter < iter_max)
	{
		z_re_new = z_re * z_re - z_im * z_im + c_val.c_re;
		z_im = 2 * z_re * z_im + c_val.c_im;
		z_re = z_re_new;
		iter++;
	}
	return (iter);
}

void	set_c_mandel(t_c_val *c_val, double col, double row, t_fractol fract)// t_r_val r, t_shift s)
{
	c_val->c_re = fract.r.r_re * (2 * col - WINDOW_WIDTH) / WINDOW_WIDTH + fract.s.s_re;
	c_val->c_im = fract.r.r_im * (2 * row - WINDOW_HEIGHT) / WINDOW_HEIGHT + fract.s.s_im;
}

int	iter_fractol(double col, double row, t_data *data)
{
	double	z_re_init;
	double	z_im_init;

	if (data->fract.fractol == 'M')
	{
		set_c_mandel(&data->fract.c_iter, col, row, data->fract);
		z_re_init = 0;
		z_im_init = 0;
	}
	else
	{
		z_re_init = data->fract.r.r_re * (2 * col - WINDOW_WIDTH) / WINDOW_WIDTH + data->fract.s.s_re;
		z_im_init = data->fract.r.r_im * (2 * row - WINDOW_HEIGHT) / WINDOW_HEIGHT + data->fract.s.s_im;
	}
	return (iterate(data->fract.c_iter, z_re_init, z_im_init, data->fract.iter_max));
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
