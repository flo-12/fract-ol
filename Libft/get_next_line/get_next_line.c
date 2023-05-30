/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:51:37 by fbecht            #+#    #+#             */
/*   Updated: 2023/01/02 15:51:40 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_cur_line(char *str, int rbytes)
{
	char	*result;
	int		i;

	if (str == NULL || rbytes < 0)
		return (NULL);
	result = malloc(sizeof(char) * gnl_ft_strlen(str) + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		result[i] = str[i];
		i++;
		if (str[i - 1] == '\n')
			break ;
	}
	result[i] = '\0';
	return (result);
}

char	*get_to_next(char *str, int rbytes)
{
	char	*result;
	int		i;
	int		j;

	if (str == NULL || rbytes < 0)
		return (free(str), NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i] || !str[i + 1])
		return (free(str), NULL);
	i++;
	result = malloc(sizeof(char) * (gnl_ft_strlen(str + i) + 1));
	if (result == NULL)
		return (free(str), NULL);
	j = 0;
	while (str[i])
		result[j++] = str[i++];
	result[j] = '\0';
	free(str);
	return (result);
}

char	*get_next_line(int fd)
{
	char		*tmp;
	char		*cur_line;
	static char	*buffer;
	int			rbytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	rbytes = 0;
	while ((gnl_ft_strchr(buffer, '\n') == NULL))
	{
		rbytes = read(fd, tmp, BUFFER_SIZE);
		if (rbytes <= 0)
			break ;
		tmp[rbytes] = '\0';
		buffer = gnl_ft_strjoin(buffer, tmp);
	}
	free(tmp);
	cur_line = get_cur_line(buffer, rbytes);
	buffer = get_to_next(buffer, rbytes);
	return (cur_line);
}
