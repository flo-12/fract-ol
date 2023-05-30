/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:18:52 by fbecht            #+#    #+#             */
/*   Updated: 2022/12/21 13:18:55 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft.h"
# include <stdarg.h>

int			ft_printf(const char *str_in, ...);
int			ft_put_argval(char type, va_list arg_ptr);
int			ft_diff_del_str(const char *str, int *len, va_list arg_ptr);
int			ft_get_i_del(const char *str);
const char	*ft_check_input(const char *str_in);
int			ft_ismember(char c, char *str);
int			ft_argtype_c(va_list arg_ptr);
int			ft_argtype_s(va_list arg_ptr);
int			ft_putlstr(const char *src, int len);
int			ft_argtype_hex(va_list arg_ptr, char type);
int			ft_argtype_ptr(va_list arg_ptr);
int			ft_gethex_len(size_t nbr);
void		ft_puthex(size_t nbr, char type);
void		ft_putpointer(size_t nbr);
int			ft_argtype_si(va_list arg_ptr);
int			ft_argtype_ui(va_list arg_ptr);
int			ft_getnbr_si_len(int nbr);
int			ft_getnbr_ui_len(unsigned int nbr);
void		ft_putnbr_unsigned_fd(unsigned int nbr, int fd);
int			ft_argtype_float(va_list arg_ptr);

#endif
