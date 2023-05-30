/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:37:30 by fbecht            #+#    #+#             */
/*   Updated: 2022/12/08 15:37:33 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

void	ft_itoa_nbr(char *str, unsigned int nbr, int len)
{
	str[len] = '\0';
	len--;
	if (nbr == 0)
		str[len] = '0';
	while (nbr > 0)
	{
		str[len] = (nbr % 10) + '0';
		len--;
		nbr = nbr / 10;
	}
}

int	ft_itoa_len(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		len = 1;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	nbr;
	int				sign;

	if (n < 0)
	{
		sign = 1;
		nbr = n * (-1);
	}
	else
	{
		sign = 0;
		nbr = n;
	}
	str = (char *)malloc(sizeof(char) * (ft_itoa_len(nbr) + sign + 1));
	if (!str)
		return (str);
	if (sign)
		str[0] = '-';
	ft_itoa_nbr((str + sign), nbr, ft_itoa_len(nbr));
	return (str);
}
