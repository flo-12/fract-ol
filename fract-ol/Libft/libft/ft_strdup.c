/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:24:25 by fbecht            #+#    #+#             */
/*   Updated: 2022/12/06 16:24:27 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	const char	*str;

	str = (const char *)malloc(sizeof(const char) * (ft_strlen(s) + 1));
	if (!str)
		return (0);
	ft_strlcpy((char *)str, s, (ft_strlen(s) + 1));
	return ((char *)str);
}
