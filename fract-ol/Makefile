
NAME = fractol

LIBFT = libft.a
MINILIBX = libmlx_Linux.a

PATH_LIBFT = ./Libft/
PATH_MINILIBX = ./minilibx_linux
PATH_INC = ./includes
PATH_SRC = ./src

FILE_SRC = fractol.c utils_mlx.c

SRC_MAIN = $(FILE_SRC:%=$(PATH_SRC)%)

CFLAGS = -Wall -Wextra -Werror
LIBS = -L$(PATH_LIBFT) -$(LIBFT) -L$(PATH_MINILIBX) -$(MINILIBX) -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
RM = rm -f

all: $(NAME)

$(NAME): $(PATH_LIBFT)
	@make -C $(PATH_LIBFT) $(LIBFT)
	@make -C $(PATH_LIBFT) $(LIBFT) clean
	@cc $(SRC_MAIN) $(LIBS) $(CFLAGS) -I$(PATH_INC)

clean:
	@make -C $(PATH_LIBFT) clean

fclean: clean
	@make -C $(PATH_LIBFT) fclean
	@$(RM) $(NAME)

re: fclean all 

.PHONY: all clean fclean re 