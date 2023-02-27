/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:43:51 by fbecht            #+#    #+#             */
/*   Updated: 2022/12/21 14:12:00 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../include/ft_printf.h"
#include "ft_printf.h"

#include <stdio.h>

// get the variadic arg and put it in the required conversion type
int	ft_put_argval(char type, va_list arg_ptr)
{
	if (type == 'c')
		return (ft_argtype_c(arg_ptr));
	else if (type == 's')
		return (ft_argtype_s(arg_ptr));
	else if (type == 'p')
		return (ft_argtype_ptr(arg_ptr));
	else if (type == 'd' || type == 'i')
		return (ft_argtype_si(arg_ptr));
	else if (type == 'u')
		return (ft_argtype_ui(arg_ptr));
	else if (type == 'x' || type == 'X')
		return (ft_argtype_hex(arg_ptr, type));
	else if (type == 'f')
		return (ft_argtype_float(arg_ptr));
	else
		return (0);
}

int	ft_diff_del_str(const char *str, int *len, va_list arg_ptr)
{
	int	i;

	if ((*str == '%' && *(str + 1) == '%') || *str != '%')
	{
		if (*str != '%')
		{
			i = ft_get_i_del(str);
			*len += ft_putlstr(str, i);
		}
		else
		{
			i = 1;
			str = str + 1;
			*len += ft_putlstr(str, i);
			i++;
		}
	}
	else
	{
		i = 2;
		*len += ft_put_argval(*(str + 1), arg_ptr);
	}
	return (i);
}

int	ft_printf(const char *str_in, ...)
{
	va_list		arg_ptr;
	const char	*str;
	int			i;
	int			len;

	str = ft_check_input(str_in);
	len = 0;
	va_start(arg_ptr, str_in);
	while (*str != '\0')
	{
		i = ft_diff_del_str(str, &len, arg_ptr);
		str = str + i;
	}
	va_end(arg_ptr);
	return (len);
}
