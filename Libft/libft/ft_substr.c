/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:58:19 by fbecht            #+#    #+#             */
/*   Updated: 2022/12/06 16:58:21 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	size;

	if (!s)
		return (0);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	if ((ft_strlen(s) - start) > len)
		size = len + 1;
	else
		size = ft_strlen(s) - start + 1;
	sub_s = (char *)malloc(sizeof(char) * size);
	if (!sub_s)
		return (NULL);
	ft_strlcpy(sub_s, (s + start), size);
	return (sub_s);
}
