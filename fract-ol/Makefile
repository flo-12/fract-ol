
NAME = fractol

LIBFT = libft.a

PATH_LIBFT = ./Libft/
PATH_MAIN = ./

FILE_MAIN = push_swap.c

SRC_MAIN = $(FILE_MAIN:%=$(PATH_MAIN)%)

CFLAGS = -Wall -Wextra -Werror
MATH_LIB = -lm
RM = rm -f

all: $(NAME)

$(NAME): $(PATH_LIBFT)
	@make -C $(PATH_LIBFT) $(LIBFT)
	@make -C $(PATH_LIBFT) $(LIBFT) clean
	@cc $(SRC_MAIN) $(MATH_LIB) -L$(PATH_LIBFT) -$(LIBFT) -o push_swap

clean:
	@make -C $(PATH_LIBFT) clean

fclean: clean
	@make -C $(PATH_LIBFT) fclean
	@$(RM) $(NAME)
	
re: fclean all 

.PHONY: all clean fclean re 