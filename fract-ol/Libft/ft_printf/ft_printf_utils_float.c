/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_float.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:43:51 by fbecht            #+#    #+#             */
/*   Updated: 2023/02/26 14:12:00 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../include/ft_printf.h"
#include "ft_printf.h"

int	ft_nbr_dec_places(double nbr)
{
	int	dec;
	int	max_dec;
	int	n;

	max_dec = 15;
	dec = max_dec;
	while (dec > 0)
	{
		nbr *= 10;
		dec--;
	}
	dec = max_dec;
	n = (int)nbr;
	while (dec > 0)
	{
		if ((int)n % 10 > 0)
			return (dec);
		n /= 10;
		dec--;
	}
	return (0);
}

int	ft_conv_float_int(double nbr, int dec)
{
	int	n;

	n = (int)nbr;
	while (dec > 0)
	{
		n *= 10;
		nbr *= 10;
		dec--;
	}
	return ((int)nbr - n);
}

int	ft_argtype_float(va_list arg_ptr)
{
	double	nbr;
	int		len;
	int		dec;

	nbr = va_arg(arg_ptr, double);
	len = ft_getnbr_si_len((int)nbr);
	ft_putnbr_fd((int)nbr, 1);
	dec = ft_nbr_dec_places(nbr - (int)nbr);
	if (dec > 0)
	{
		ft_putchar_fd('.', 1);
		ft_putnbr_fd(ft_conv_float_int(nbr, dec), 1);
		len += dec + 1;
	}
	return (len);
}
