# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbecht <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 12:11:28 by fbecht            #+#    #+#              #
#    Updated: 2022/11/29 12:11:31 by fbecht           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

PATH_LIBFT = ./libft/
PATH_GNL = ./get_next_line/
PATH_PRINTF = ./ft_printf/

FILE_LIBFT = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
		ft_isprint.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strlcpy.c \
		ft_strlen.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
FILE_GNL = get_next_line_utils.c get_next_line.c
FILE_PRINTF = ft_printf.c ft_printf_utils.c ft_printf_utils_str_char.c \
	ft_printf_utils_nbr.c ft_printf_utils_hex.c ft_printf_utils_float.c

SRC_LIBFT = $(FILE_LIBFT:%=$(PATH_LIBFT)%)
SRC_GNL = $(FILE_GNL:%=$(PATH_GNL)%)
SRC_PRINTF = $(FILE_PRINTF:%=$(PATH_PRINTF)%)

H_FILES = libft.h get_next_line.h ft_printf.h

OBJ_LIBFT = $(FILE_LIBFT:.c=.o)
OBJ_GNL = $(FILE_GNL:.c=.o)
OBJ_PRINTF = $(FILE_PRINTF:.c=.o)

C_FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@cc $(C_FLAGS) -c $(SRC_LIBFT) -I.
	@cc $(C_FLAGS) -c $(SRC_GNL) $(SRC_PRINTF)
	@ar rc $(NAME) $(OBJ_LIBFT) $(OBJ_GNL) $(OBJ_PRINTF)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ_LIBFT) $(OBJ_GNL) $(OBJ_PRINTF)
	@rm -f $(FILE_LIBFT:.c=.o)
	@rm -f $(FILE_GNL:.c=.o)
	@rm -f $(FILE_PRINTF:.c=.o)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re
