/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:08:58 by fbecht            #+#    #+#             */
/*   Updated: 2022/12/19 15:09:00 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../include/ft_printf.h"
#include "ft_printf.h"

int	ft_ismember(char c, char *str)
{
	while (*str != '\0')
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

// fct findes index of next '%' or end of string ('\0')
int	ft_get_i_del(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '%' && str[i] != '\0')
		i++;
	return (i);
}

// check if input is correct (single % not allowed)
const char	*ft_check_input(const char *str)
{
	char	*conv;
	int		i;

	conv = "cspdiuxX%%";
	i = ft_get_i_del(str);
	while (str[i] != '\0')
	{
		if (!(ft_ismember(str[i + 1], conv)))
			return ("\0");
		i += 2;
		i += ft_get_i_del(str + i);
	}
	return (str);
}
