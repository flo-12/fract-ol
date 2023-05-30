/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:51:44 by fbecht            #+#    #+#             */
/*   Updated: 2023/01/02 15:51:47 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*get_to_next(char *str, int rbytes);
char	*get_cur_line(char *str, int rbytes);

char	*gnl_ft_strdup(const char *s);
char	*gnl_ft_strjoin(char *s1, char const *s2);
size_t	gnl_ft_strlen(const char *s);
char	*gnl_ft_strchr(const char *s, int c);

#endif