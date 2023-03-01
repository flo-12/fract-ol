
NAME = fractol

LIBFT = libft.a
LFT = lft
MINILIBX = libmlx_Linux.a
MINILX = lmlx_Linux

PATH_LIBFT = ./Libft/
PATH_MINILIBX = ./minilibx_linux/
PATH_INC = ./includes/
PATH_SRC = ./src/

FILE_SRC = fractol.c utils_mlx.c exit_fractol.c mlx_hooks.c draw_fractol.c \
		init_data.c init_data_Julia_c.c calc_color.c

SRC_MAIN = $(FILE_SRC:%=$(PATH_SRC)%)

CFLAGS = -Wall -Wextra -Werror
LIBS = -L$(PATH_LIBFT) -$(LFT) -L$(PATH_MINILIBX) -$(MINILX) -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
RM = rm -f

all: $(NAME)

$(NAME): $(PATH_LIBFT)
	@make -C $(PATH_LIBFT) $(LIBFT)
	@make -C $(PATH_LIBFT) $(LIBFT) clean
	@cc $(SRC_MAIN) $(LIBS) $(CFLAGS) -I$(PATH_MINILIBX) -I$(PATH_INC) -I$(PATH_LIBFT) -o $(NAME)

clean:
	@make -C $(PATH_LIBFT) clean

fclean: clean
	@make -C $(PATH_LIBFT) fclean
	@$(RM) $(NAME)

re: fclean all 

.PHONY: all clean fclean re 