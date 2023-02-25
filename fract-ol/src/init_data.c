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

#include <stdio.h>

int	check_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (i);
		i++;
	}
	return (0);
}

int	get_iter_max(int argc, char **argv, int i)
{
	if (argc > i)
	{
		if (!check_digit(argv[i]))
			return (ft_atoi(argv[i]));
		else
		{
			ft_printf("%s%d\n", WRONG_ITER_MAX, ITER_MAX);
			return (ITER_MAX);
		}
	}
	else
	{
		ft_printf("%s%d\n", NO_ITER_MAX, ITER_MAX);
		return (ITER_MAX);
	}
}

void	get_c_value(t_data *data, int argc, char **argv)
{
	int	i_re;
	int	i_re_sign;
	int	i_im;
	int	i_im_sign;

// HANDLE NEGATIVE VALUES!!!!

	if (argc < 4)
	{
		//ft_printf("%s(C_Re=%d | C_Im=%d)\n", WRONG_JULIA_C, JULIA_C_RE, JULIA_C_IM);
		ft_printf("%s(C_Re=-0.79 | C_Im=0.15)\n", NO_JULIA_C);
		data->fract.c_re = JULIA_C_RE;
		data->fract.c_im = JULIA_C_IM;
		return ;
	}
	if (argv[2][0] == '-')
		i_re_sign = 1;
	else
		i_re_sign = 0;
	if (argv[3][0] == '-')
		i_im_sign = 1;
	else
		i_im_sign = 0;
	i_re = check_digit(argv[2] + i_re_sign);
	i_im = check_digit(argv[3] + i_im_sign);
	if ((i_re && (argv[2][i_re + i_re_sign] != '.' || check_digit(argv[2] + i_re + i_re_sign)))
		|| (i_im && (argv[3][i_im + i_im_sign] != '.' || check_digit(argv[3] + i_im + i_im_sign))))
	{
		//ft_printf("%s(C_Re=%d | C_Im=%d)\n", WRONG_JULIA_C, JULIA_C_RE, JULIA_C_IM);
		ft_printf("%s(C_Re=-0.79 | C_Im=0.15)\n", WRONG_JULIA_C);
		data->fract.c_re = JULIA_C_RE;
		data->fract.c_im = JULIA_C_IM;
		return ;
	}
	if (!i_re)
		data->fract.c_re = (double)ft_atoi(argv[2] + i_re_sign);
	else
	{
		argv[2][i_re + i_re_sign] = '\0';
		data->fract.c_re = (double)ft_atoi(argv[2] + i_re_sign);
		data->fract.c_re += (double)ft_atoi(argv[2] + i_re + i_re_sign + 1)
					/ pow(10, ft_strlen(argv[2] + i_re + i_re_sign + 1));
	}
	if (!i_im)
		data->fract.c_im = (double)ft_atoi(argv[3] + i_im_sign);
	else
	{
		argv[3][i_im + i_im_sign] = '\0';
		data->fract.c_im = (double)ft_atoi(argv[3] + i_im_sign);
		data->fract.c_im += (double)ft_atoi(argv[3] + i_re + i_im_sign + 1)
					/ pow(10, ft_strlen(argv[3] + i_im + i_im_sign + 1));
	}
	if (i_re_sign)
		data->fract.c_re *= (-1);
	if (i_im_sign)
		data->fract.c_im *= (-1);
}

void	init_fractol(t_data *data, int argc, char **argv)
{
	data->fract.zoom = 1;
	data->fract.row_min = 0;
	data->fract.row_max = WINDOW_HEIGHT;
	data->fract.col_min = 0;
	data->fract.col_max = WINDOW_WIDTH;
	if (((!ft_strncmp(argv[1], "Mandelbrot", ft_strlen("Mandelbrot"))
		&& (ft_strlen(argv[1]) == ft_strlen("Mandelbrot")))
		|| (!ft_strncmp(argv[1], "M", 1) && (ft_strlen(argv[1]) == 1)))
		&& (argc == 2 || argc == 3))
	{
		data->fract.iter_max = get_iter_max(argc, argv, 2);
		data->fract.fractol = 'M';
	}
	else if ((!ft_strncmp(argv[1], "Julia", ft_strlen("Julia"))
		&& (ft_strlen(argv[1]) == ft_strlen("Julia")))
		|| (!ft_strncmp(argv[1], "J", 1) && (ft_strlen(argv[1]) == 1)))
	{
		get_c_value(data, argc, argv);
		data->fract.iter_max = get_iter_max(argc, argv, 4);
		data->fract.fractol = 'J';
	}
	else
		exit_fractol(data, 0, ARG_WRONG);
}

void	init_data(t_data *data, int argc, char **argv)
{
	if (argc == 1 || argc > 5)
		exit_fractol(data, 0, ARG_WRONG);
	init_fractol(data, argc, argv);
	data->mlx = mlx_init();
	if (!data->mlx)
		exit_fractol(data, 1, INIT_MLX);
	data->win = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Fractol");
	if (!data->win)
	{
		exit_fractol(data, 1, INIT_WIN);
	}
	data->img.image = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!data->img.image)
	{
		exit_fractol(data, 1, INIT_IMG);
	}
	data->img.addr = mlx_get_data_addr(data->img.image, &data->img.bpp, &data->img.size_line, &data->img.endian);
}
