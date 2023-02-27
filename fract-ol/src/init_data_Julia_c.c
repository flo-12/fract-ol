/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_Julia_c.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:32:52 by fbecht            #+#    #+#             */
/*   Updated: 2023/02/27 10:32:54 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	get_double_c(int i_digit, int sign, char *str)
{
	double	nbr;

	if (!i_digit)
		nbr = (double)ft_atoi(str + sign);
	else
	{
		str[i_digit + sign] = '\0';
		nbr = (double)ft_atoi(str + sign);
		nbr += (double)ft_atoi(str + i_digit + sign + 1)
			/ pow(10, ft_strlen(str + i_digit + sign + 1));
	}
	if (sign)
		nbr *= (-1);
	return (nbr);
}

int	get_sign(char *str)
{
	if (*str == '-')
		return (1);
	else
		return (0);
}

void	init_default_julia_c(t_data *data)
{
	ft_printf("%s(C_Re=%f | C_Im=%f)\n", WRONG_JULIA_C,
		JULIA_C_RE, JULIA_C_IM);
	data->fract.c_re = JULIA_C_RE;
	data->fract.c_im = JULIA_C_IM;
}

void	get_julia_c(t_data *data, int argc, char **argv)
{
	int	i_re;
	int	i_re_sign;
	int	i_im;
	int	i_im_sign;

	if (argc < 4)
	{
		init_default_julia_c(data);
		return ;
	}
	i_re_sign = get_sign(argv[2]);
	i_im_sign = get_sign(argv[3]);
	i_re = check_digit(argv[2] + i_re_sign);
	i_im = check_digit(argv[3] + i_im_sign);
	if ((i_re && (argv[2][i_re + i_re_sign] != '.'
			|| check_digit(argv[2] + i_re + i_re_sign)))
		|| (i_im && (argv[3][i_im + i_im_sign] != '.'
		|| check_digit(argv[3] + i_im + i_im_sign))))
	{
		init_default_julia_c(data);
		return ;
	}
	data->fract.c_re = get_double_c(i_re, i_re_sign, argv[2]);
	data->fract.c_im = get_double_c(i_im, i_im_sign, argv[3]);
}
