/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:34:27 by fbecht            #+#    #+#             */
/*   Updated: 2023/02/25 13:34:29 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_iter_max(int argc, char **argv, int i)
{
	int	j;

	if (argc > i)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				ft_printf("%s%d\n", WRONG_ITER_MAX, ITER_MAX);
				return (ITER_MAX);
			}
		}
		return (ft_atoi(argv[i]));
	}
	else
	{
		ft_printf("%s%d\n", NO_ITER_MAX, ITER_MAX);
		return (ITER_MAX);
	}
}

int	get_color_set(int argc, char **argv, int i)
{
	if (argc > i)
	{
		if (ft_strlen(argv[i]) == 1 && (argv[i][0] >= '0' && argv[i][0] <= '5'))
			return (ft_atoi(argv[i]));
		else
		{
			ft_printf("%s%d\n", WRONG_COLOR_SET, COLOR_SET);
			return (COLOR_SET);
		}
	}
	else
	{
		ft_printf("%s%d\n", NO_COLOR_SET, COLOR_SET);
		return (COLOR_SET);
	}
}

void	set_fractol_parameters(char fractol, double c_re,
	double c_im, t_data *data)
{
	data->fract.zoom = 1;
	data->fract.fractol = fractol;
	data->fract.c_iter[0] = c_re;
	data->fract.c_iter[1] = c_im;
	data->fract.iter_max = ITER_MAX;
	data->fract.r.r_re = 2 * WINDOW_WIDTH / WINDOW_HEIGHT;
	data->fract.r.r_im = 2;
	data->fract.s.s_re = 0;
	data->fract.s.s_im = 0;
}

void	init_fractol(t_data *data, int argc, char **argv)
{
	if (((!ft_strncmp(argv[1], "Mandelbrot", ft_strlen("Mandelbrot"))
				&& (ft_strlen(argv[1]) == ft_strlen("Mandelbrot")))
			|| (!ft_strncmp(argv[1], "M", 1) && (ft_strlen(argv[1]) == 1)))
		&& (argc >= 2 && argc <= 4))
	{
		data->fract.color_set = get_color_set(argc, argv, 3);
		set_fractol_parameters('M', 0, 0, data);
		data->fract.iter_max = get_iter_max(argc, argv, 2);
	}
	else if ((!ft_strncmp(argv[1], "Julia", ft_strlen("Julia"))
			&& (ft_strlen(argv[1]) == ft_strlen("Julia")))
		|| (!ft_strncmp(argv[1], "J", 1) && (ft_strlen(argv[1]) == 1)))
	{
		data->fract.color_set = get_color_set(argc, argv, 5);
		set_julia_arg_c(data, argc, argv);
		set_fractol_parameters('J', data->fract.c_julia[0],
			data->fract.c_julia[1], data);
		data->fract.iter_max = get_iter_max(argc, argv, 4);
	}
	else
		exit_fractol(data, 0, ARG_WRONG);
}
