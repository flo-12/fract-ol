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
		ft_printf("Resetting to default\n");
		if (data->fract.fractol == 'M')
			set_fractol_parameters(data->fract.fractol, 0, 0, data);
		else
			set_fractol_parameters(data->fract.fractol, data->fract.c_re, data->fract.c_im, data);
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
	else if (key == KEY_ZERO && ((int)(data->fract.c_re_var * 10000) != 0
		|| (int)(data->fract.c_im_var * 10000) != 0))
	{
		ft_printf("Printing Julia with new, chosen values\n");
		set_fractol_parameters('J', data->fract.c_re_var, data->fract.c_im_var,
			data);
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
		ft_printf("Changing iter max value (before: %d)\n", data->fract.iter_max);
		if (key == KEY_UP)
			data->fract.iter_max += 50;
		else
		{
			if (data->fract.iter_max >= 100)
				data->fract.iter_max -= 50;
		}
	}
	else
		return (1);
	draw_fractol(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.image, 0, 0);
	return (0);
}

int	handle_destroy(t_data *data)
{
	exit_fractol(data, 0, EXIT_CROSS);
	return (0);
}

void	set_zoom_val(int key, int x, int y, t_fractol *fract)
{
	// chanege here so that mouse pointer is still at the same point and
	// not at the center of the screen
	fract->centre[0] = fract->centre[0] + (x - WINDOW_WIDTH / 2) / fract->zoom / 10;
	fract->centre[1] = fract->centre[1] + (y - WINDOW_HEIGHT / 2) / fract->zoom / 10;
	if (key == MOUSE_WHEEL_UP)
		fract->zoom *= ZOOM_FACTOR;
	else if (key == MOUSE_WHEEL_DOWN)
		fract->zoom *= 1 / ZOOM_FACTOR;
	fract->col_min = fract->centre[0] - (WINDOW_WIDTH / 2) / fract->zoom;
	fract->col_max = fract->col_min + WINDOW_WIDTH / fract->zoom;
	fract->row_min = fract->centre[1] - (WINDOW_HEIGHT / 2) / fract->zoom;
	fract->row_max = fract->row_min + WINDOW_HEIGHT / fract->zoom;
}

int	hook_mouse(int key, int x, int y, t_data *data)
{
	if (key == MOUSE_WHEEL_UP || key == MOUSE_WHEEL_DOWN)
	{
		if (key == MOUSE_WHEEL_DOWN
			&& !((int)(data->fract.zoom * 10) > 10))
		{
			ft_printf("%s\n", MAX_ZOOM_OUT);
			return (0);
		}
		set_zoom_val(key, x, y, &data->fract);
		draw_fractol(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img.image, 0, 0);
	}
	if (key == MOUSE_BTN_LEFT && data->fract.fractol == 'M')
	{
		data->fract.c_re_var = 4 * (data->fract.col_min + x / data->fract.zoom)
			/ WINDOW_WIDTH - 2;
		data->fract.c_im_var = 4 * (data->fract.row_min + y / data->fract.zoom)
			/ WINDOW_HEIGHT - 2;
		ft_printf("Values for C at %d/%d are C_Re=%f, C_Im=%f", x, y,
			data->fract.c_re_var, data->fract.c_im_var);
		ft_printf(" - Press 0 to print Julia Set with those values\n");
	}
	return (0);
}
