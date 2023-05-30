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
	len = 0;
	if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		len += 1;
		nbr *= (-1);
	}
	len += ft_getnbr_si_len((int)nbr);
	ft_putnbr_fd((int)nbr, 1);
	dec = 7;
	ft_putchar_fd('.', 1);
	ft_putnbr_fd(ft_conv_float_int(nbr, dec), 1);
	len += dec + 1;
	return (len);
}
