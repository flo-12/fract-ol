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

void	set_zoom_val(int key, int x, int y, t_fractol *fract)
{
	if (!(key == KEY_DOWN || key == KEY_UP))
		fract->s.s_re += fract->r.r_re * (((double)x - WINDOW_WIDTH / 2)
				/ WINDOW_WIDTH);
	if (!(key == KEY_RIGHT || key == KEY_LEFT))
		fract->s.s_im += fract->r.r_im * (((double)y - WINDOW_HEIGHT / 2)
				/ WINDOW_HEIGHT);
	if (key == MOUSE_WHEEL_UP || key == KEY_M)
	{
		fract->zoom *= ZOOM_FACTOR;
		fract->r.r_re /= ZOOM_FACTOR;
		fract->r.r_im /= ZOOM_FACTOR;
	}
	else if (key == MOUSE_WHEEL_DOWN || key == KEY_N)
	{
		fract->zoom /= ZOOM_FACTOR;
		fract->r.r_re *= ZOOM_FACTOR;
		fract->r.r_im *= ZOOM_FACTOR;
	}
}

int	handle_keypress(int key, t_data *data)
{
	if (key == KEY_ESC)
		return (exit_fractol(data, 0, EXIT_ESC), EXIT_SUCCESS);
	else if (key == KEY_R)
		reset_fractol(data);
	else if (key == KEY_ONE)
		reset_default_fractol('M', data);
	else if (key == KEY_TWO)
		reset_default_fractol('J', data);
	else if (key == KEY_ZERO && ((int)(data->fract.c_mandel[0] * 10000) != 0
		|| (int)(data->fract.c_mandel[1] * 10000) != 0))
		julia_from_mandel(data);
	else if (key == KEY_D || key == KEY_A)
		change_color_set(key, data);
	else if (key == KEY_W || key == KEY_S)
		change_iter_max(key, data);
	else if (key >= KEY_LEFT && key <= KEY_DOWN)
		set_zoom_val(key, WINDOW_WIDTH / 2 + (key - 65362) * WINDOW_WIDTH / 4,
			WINDOW_HEIGHT / 2 + (key - 65363) * WINDOW_HEIGHT / 4,
			&data->fract);
	else if (key == KEY_N || key == KEY_M)
		set_zoom_val(key, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, &data->fract);
	else
		return (EXIT_FAILURE);
	put_fractol(data);
	return (EXIT_SUCCESS);
}

int	handle_destroy(t_data *data)
{
	exit_fractol(data, 0, EXIT_CROSS);
	return (0);
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
