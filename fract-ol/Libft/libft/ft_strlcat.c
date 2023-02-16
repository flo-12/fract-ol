/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:11:51 by fbecht            #+#    #+#             */
/*   Updated: 2022/12/05 16:11:54 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	size_dest;
	size_t	i;

	size_dest = ft_strlen(dest);
	i = size_dest;
	while (src[i - size_dest] != '\0' && (i + 1) < size)
	{
		dest[i] = src[i - size_dest];
		i++;
	}
	if (size_dest < size)
		dest[i] = '\0';
	if (size < size_dest)
		return (size + ft_strlen(src));
	else
		return (size_dest + ft_strlen(src));
}
