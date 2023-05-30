/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:43:51 by fbecht            #+#    #+#             */
/*   Updated: 2022/12/21 14:12:00 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../include/ft_printf.h"
#include "ft_printf.h"

int	ft_argtype_si(va_list arg_ptr)
{
	int	nbr;

	nbr = va_arg(arg_ptr, int);
	ft_putnbr_fd(nbr, 1);
	return (ft_getnbr_si_len(nbr));
}

int	ft_argtype_ui(va_list arg_ptr)
{
	unsigned int	nbr;

	nbr = va_arg(arg_ptr, unsigned int);
	ft_putnbr_unsigned_fd(nbr, 1);
	return (ft_getnbr_ui_len(nbr));
}

void	ft_putnbr_unsigned_fd(unsigned int nbr, int fd)
{
	if (nbr >= 10)
		ft_putnbr_unsigned_fd(nbr / 10, fd);
	ft_putchar_fd((nbr % 10) + '0', fd);
}

int	ft_getnbr_si_len(int nbr)
{
	int	len;

	if (nbr < 0)
	{
		len = 1;
		len += ft_getnbr_ui_len(nbr * (-1));
	}
	else
		len = ft_getnbr_ui_len(nbr);
	return (len);
}

int	ft_getnbr_ui_len(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		len = 1;
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}
