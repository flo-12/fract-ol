# Program Name
NAME = fractol

# Libft
LIBFT = libft.a
LFT = lft
PATH_LIBFT = ./Libft/

# MiniLibX
MINILIBX = libmlx_Linux.a
MINILX = lmlx_Linux
PATH_MINILIBX = ./minilibx_linux/
MLX	= $(PATH_MINILIBX)$(MINILIBX)

# Includes
PATH_INC = ./includes/

# Sources
FILE_SRC = main.c utils_mlx.c exit_fractol.c mlx_hooks.c put_fractol.c \
		init_fractol.c set_julia_arg_c.c calc_color.c utils_key_hooks.c
PATH_SRC = ./src/
SRC_MAIN = $(FILE_SRC:%=$(PATH_SRC)%)

# Compiler
CFLAGS = -Wall -Wextra -Werror

# Libraries
LIBS = -L$(PATH_LIBFT) -$(LFT) -L$(PATH_MINILIBX) -$(MINILX) -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

RM = rm -f

# Built process
all: $(MLX) $(NAME)

$(NAME): $(PATH_LIBFT)
	@make -C $(PATH_LIBFT) $(LIBFT)
	@make -C $(PATH_LIBFT) $(LIBFT) clean
	@cc $(SRC_MAIN) $(LIBS) $(CFLAGS) -I$(PATH_MINILIBX) -I$(PATH_INC) -I$(PATH_LIBFT) -o $(NAME)

$(MLX):
	@make -C $(MLX_PATH)

clean:
	@make -C $(PATH_LIBFT) clean

fclean: clean
	@make -C $(PATH_LIBFT) fclean
	@$(RM) $(NAME)

re: fclean all 

.PHONY: all clean fclean re 