/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_str_char.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:43:51 by fbecht            #+#    #+#             */
/*   Updated: 2022/12/21 14:12:00 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../include/ft_printf.h"
#include "ft_printf.h"

int	ft_argtype_c(va_list arg_ptr)
{
	ft_putchar_fd((unsigned char)va_arg(arg_ptr, int), 1);
	return (1);
}

int	ft_argtype_s(va_list arg_ptr)
{
	char	*str;

	str = va_arg(arg_ptr, char *);
	if (!str)
		str = "(null)";
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

// put l characters of src
int	ft_putlstr(const char *src, int len)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && i < len)
	{
		ft_putchar_fd(src[i], 1);
		i++;
	}
	return (i);
}
