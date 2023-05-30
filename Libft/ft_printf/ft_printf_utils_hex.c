/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:43:51 by fbecht            #+#    #+#             */
/*   Updated: 2022/12/21 14:12:00 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../include/ft_printf.h"
#include "ft_printf.h"

int	ft_argtype_ptr(va_list arg_ptr)
{
	size_t	nbr;

	nbr = va_arg(arg_ptr, size_t);
	if (nbr)
	{
		ft_putpointer(nbr);
		return (2 + ft_gethex_len(nbr));
	}
	else
	{
		ft_putstr_fd("(nil)", 1);
		return (ft_strlen("(nil)"));
	}
}

int	ft_argtype_hex(va_list arg_ptr, char type)
{
	unsigned int	nbr;

	nbr = va_arg(arg_ptr, long int);
	ft_puthex(nbr, type);
	return (ft_gethex_len(nbr));
}

void	ft_puthex(size_t nbr, char type)
{
	char	*hex;

	if (type == 'X')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (nbr >= 16)
		ft_puthex(nbr / 16, type);
	ft_putchar_fd(hex[nbr % 16], 1);
}

int	ft_gethex_len(size_t nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		len = 1;
	while (nbr > 0)
	{
		nbr = nbr / 16;
		len++;
	}
	return (len);
}

void	ft_putpointer(size_t nbr)
{
	ft_putstr_fd("0x", 1);
	ft_puthex(nbr, 'x');
}
