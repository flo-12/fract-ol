/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:51:52 by fbecht            #+#    #+#             */
/*   Updated: 2023/01/02 15:51:55 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_ft_strlen(const char *s)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*gnl_ft_strdup(const char *s)
{
	char	*new;
	int		len;
	int		i;

	len = (int)gnl_ft_strlen(s);
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = 0;
	return (new);
}

char	*gnl_ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = malloc(sizeof(char) * (gnl_ft_strlen(s1) + gnl_ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if (!s1)
		s1 = gnl_ft_strdup("\0");
	if (s1)
	{
		while (s1[i])
			str[j++] = s1[i++];
	}
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	free(s1);
	return (str);
}

char	*gnl_ft_strchr(const char *s, int c)
{
	int		i;
	char	*s_c;

	i = 0;
	s_c = NULL;
	if (!s)
		return (NULL);
	if (c == 0)
		return ((char *)&s[gnl_ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			s_c = (char *)&s[i];
			break ;
		}
		i++;
	}
	return (s_c);
}
