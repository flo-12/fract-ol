/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:55:45 by fbecht            #+#    #+#             */
/*   Updated: 2022/12/08 12:55:47 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_split_len_arr(char const *s, char c)
{
	int	nbr;
	int	unique;

	nbr = 0;
	unique = 0;
	while (*s)
	{
		if (*s != c)
			unique = 1;
		if (*s == c && unique)
		{
			nbr++;
			unique = 0;
		}
		s++;
	}
	if (*(s - 1) != c && unique)
		nbr++;
	return (nbr);
}

static void	ft_split_free_if(char **tab, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_split_allocate(char **tab, char const *s, char c, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (s[j] && s[j] != c)
			j++;
		tab[i] = (char *)malloc(sizeof(char) * (j + 1));
		if (!tab[i])
		{
			ft_split_free_if(tab, i);
			return ;
		}
		tab[i] = ft_memcpy(tab[i], s, j);
		tab[i][j] = '\0';
		while (*s != c && *s)
			s++;
		while (*s == c && *s)
			s++;
		i++;
	}
	tab[size] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**addr;
	int		l_addr;

	l_addr = ft_split_len_arr(s, c);
	addr = (char **)malloc(sizeof(char *) * (l_addr + 1));
	if (!addr)
		return (addr);
	while (*s == c && *s)
		s++;
	ft_split_allocate(addr, s, c, l_addr);
	return (addr);
}
