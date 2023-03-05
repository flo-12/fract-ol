/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:45:47 by fbecht            #+#    #+#             */
/*   Updated: 2023/02/21 11:45:49 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_keypress(int key, t_data *data)
{
	if (key == KEY_ESC)
	{
		exit_fractol(data, 0, EXIT_ESC);
		return (0);
	}
	else if (key == KEY_R)
	{
		ft_printf("Resetting to first Fractal\n");
		if (data->fract.fractol == 'M')
			set_fractol_parameters('M', 0, 0, data);
		else
		{
			set_fractol_parameters('J', data->fract.c_julia.c_re,
				data->fract.c_julia.c_im, data);
		}
	}
	else if (key == KEY_ONE)
	{
		ft_printf("Resetting to default Mandelbrot\n");
		set_fractol_parameters('M', 0, 0, data);
	}
	else if (key == KEY_TWO)
	{
		ft_printf("Resetting to default Julia\n");
		set_fractol_parameters('J', JULIA_C_RE, JULIA_C_IM, data);
	}
	else if (key == KEY_ZERO && ((int)(data->fract.c_mandel.c_re * 10000) != 0
		|| (int)(data->fract.c_mandel.c_im * 10000) != 0))
	{
		ft_printf("Drawing Julia with new, chosen values\n");
		set_fractol_parameters('J', data->fract.c_mandel.c_re, data->fract.c_mandel.c_im,
			data);
		data->fract.c_julia.c_re = data->fract.c_mandel.c_re;
		data->fract.c_julia.c_im = data->fract.c_mandel.c_im;
		ft_bzero(&data->fract.c_mandel, sizeof(data->fract.c_mandel));
	}
	else if (key == KEY_RIGHT || key == KEY_LEFT)
	{
		ft_printf("Changing color set\n");
		if (key == KEY_RIGHT)
		{
			data->fract.color_set++;
			if (data->fract.color_set > 5)
				data->fract.color_set = 0;
		}
		else
		{
			data->fract.color_set--;
			if (data->fract.color_set < 0)
				data->fract.color_set = 5;
		}
	}
	else if (key == KEY_DOWN || key == KEY_UP)
	{
		ft_printf("Changing iter max value to ");
		if (key == KEY_UP)
		{
			data->fract.iter_max += 50;
			ft_printf("%d\n", data->fract.iter_max);
		}
		else
		{
			if (data->fract.iter_max >= 100)
			{
				data->fract.iter_max -= 50;
				ft_printf("%d\n", data->fract.iter_max);
			}
		}
	}
	else
		return (1);
	put_fractol(data);
	return (0);
}

int	handle_destroy(t_data *data)
{
	exit_fractol(data, 0, EXIT_CROSS);
	return (0);
}

void	set_zoom_val(int key, int x, int y, t_fractol *fract)
{
	fract->s.s_re += fract->r.r_re * (((double)x - WINDOW_WIDTH / 2) / WINDOW_WIDTH);
	fract->s.s_im += fract->r.r_im * (((double)y - WINDOW_HEIGHT / 2) / WINDOW_HEIGHT);
	if (key == MOUSE_WHEEL_UP)
	{
		fract->zoom *= ZOOM_FACTOR;
		fract->r.r_re /= ZOOM_FACTOR;
		fract->r.r_im /= ZOOM_FACTOR;
	}
	else if (key == MOUSE_WHEEL_DOWN)
	{
		fract->zoom /= ZOOM_FACTOR;
		fract->r.r_re *= ZOOM_FACTOR;
		fract->r.r_im *= ZOOM_FACTOR;
	}
}

int	hook_mouse(int key, int x, int y, t_data *data)
{
	if (key == MOUSE_WHEEL_UP || key == MOUSE_WHEEL_DOWN)
	{
		set_zoom_val(key, x, y, &data->fract);
		put_fractol(data);
	}
	if (key == MOUSE_BTN_LEFT && data->fract.fractol == 'M')
	{
		set_c_mandel(&data->fract.c_mandel, x, y, data->fract);
		ft_printf("Values for C at %d/%d are C_Re=%f, C_Im=%f", x, y,
			data->fract.c_mandel.c_re, data->fract.c_mandel.c_im);
		ft_printf(" - Press 0 to print Julia Set with those values\n");
	}
	return (0);
}
