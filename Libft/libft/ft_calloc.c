/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:00:24 by fbecht            #+#    #+#             */
/*   Updated: 2022/12/06 15:00:26 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (!nmemb || !size)
		return (malloc(0));
	if (nmemb >= __SIZE_MAX__ / size)
		return (0);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (0);
	return (ft_memset(ptr, 0, (nmemb * size)));
}
