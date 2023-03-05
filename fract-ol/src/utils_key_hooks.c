/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_key_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:34:24 by fbecht            #+#    #+#             */
/*   Updated: 2023/03/05 18:34:26 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* Key R pressed -> Reset the current fractol */
void	reset_fractol(t_data *data)
{
	ft_printf("Resetting to first Fractal\n");
	if (data->fract.fractol == 'M')
		set_fractol_parameters('M', 0, 0, data);
	else
	{
		set_fractol_parameters('J', data->fract.c_julia[0],
			data->fract.c_julia[1], data);
	}
}

/* Key 0 pressed and values for C from Mandelbrot Set before calculated
	-> draw Julia set with C values calculated from Mandelbrot */
void	julia_from_mandel(t_data *data)
{
	ft_printf("Drawing Julia with new, chosen values\n");
	set_fractol_parameters('J', data->fract.c_mandel[0],
		data->fract.c_mandel[1], data);
	data->fract.c_julia[0] = data->fract.c_mandel[0];
	data->fract.c_julia[1] = data->fract.c_mandel[1];
	ft_bzero(&data->fract.c_mandel, sizeof(data->fract.c_mandel));
}

/* Key Left or Right pressed -> change color set */
void	change_color_set(int key, t_data *data)
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

/* Key Up or Down pressed -> change iter_max factor */
void	change_iter_max(int key, t_data *data)
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

/* Key One or Two pressed
	-> One (fract=='M'): Reset to default Mandelbrot
	-> Two (fract=='J'): Reset to default Julia */
void	reset_default_fractol(char fract, t_data *data)
{
	if (fract == 'M')
	{
		ft_printf("Resetting to default Mandelbrot\n");
		set_fractol_parameters('M', 0, 0, data);
	}
	else if (fract == 'J')
	{
		ft_printf("Resetting to default Julia\n");
		set_fractol_parameters('J', JULIA_C_RE, JULIA_C_IM, data);
	}
}
