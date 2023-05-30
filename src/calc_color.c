/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:08:18 by fbecht            #+#    #+#             */
/*   Updated: 2023/03/01 16:08:20 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	encode_rgb(int t, int red, int green, int blue)
{
	return (t << 24 | red << 16 | green << 8 | blue);
}

int	calc_color(int iter, int iter_max, int cs, t_data *data)
{
	int		rgb[3];
	double	div;

	if (iter < data->fract.iter_max)
	{
		div = (double)iter / iter_max;
		if (cs < 3)
		{
			rgb[cs % 3] = 9 * (1 - div) * div * div * div * 255;
			rgb[(cs + 1) % 3] = 9 * ((1 - div) * (1 - div))
				* (div * div) * 255;
			rgb[(cs + 2) % 3] = 9 * ((1 - div) * (1 - div) * (1 - div))
				* div * 255;
		}
		else
		{
			rgb[cs % 3] = 9 * ((1 - div) * (1 - div) * (1 - div)) * div * 255;
			rgb[(cs + 1) % 3] = 9 * ((1 - div) * (1 - div))
				* (div * div) * 255;
			rgb[(cs + 2) % 3] = 9 * (1 - div) * (div * div * div) * 255;
		}
		return (0 << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
	}
	else
		return (COLOR_LIGHT_GREY);
}
