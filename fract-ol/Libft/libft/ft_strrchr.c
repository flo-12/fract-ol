/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:05:08 by fbecht            #+#    #+#             */
/*   Updated: 2022/12/06 11:05:10 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*str;

	str = s + ft_strlen(s);
	while (str >= s)
	{
		if (*str == (char)c)
			return ((char *)str);
		str--;
	}
	return (0);
}
