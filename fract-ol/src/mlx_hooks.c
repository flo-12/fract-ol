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
		reset_fractol(data);
	else if (key == KEY_ONE)
		reset_default_fractol('M', data);
	else if (key == KEY_TWO)
		reset_default_fractol('J', data);
	else if (key == KEY_ZERO && ((int)(data->fract.c_mandel[0] * 10000) != 0
		|| (int)(data->fract.c_mandel[1] * 10000) != 0))
		julia_from_mandel(data);
	else if (key == KEY_RIGHT || key == KEY_LEFT)
		change_color_set(key, data);
	else if (key == KEY_DOWN || key == KEY_UP)
		change_iter_max(key, data);
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
	fract->s.s_re += fract->r.r_re * (((double)x - WINDOW_WIDTH / 2)
			/ WINDOW_WIDTH);
	fract->s.s_im += fract->r.r_im * (((double)y - WINDOW_HEIGHT / 2)
			/ WINDOW_HEIGHT);
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
		set_c_z_iter(data->fract.c_mandel, x, y, data->fract);
		ft_printf("Values for C at %d/%d are C_Re=%f, C_Im=%f", x, y,
			data->fract.c_mandel[0], data->fract.c_mandel[1]);
		ft_printf(" - Press 0 to print Julia Set with those values\n");
	}
	return (0);
}
