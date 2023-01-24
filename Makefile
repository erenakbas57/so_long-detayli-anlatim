NAME = so_long
CC = gcc
FLAGS = -Wall -Wextra -Werror
FREAMS = -framework OpenGL -framework AppKit

MLX = ./mlx/libmlx.a
LIBFT = ./libft/libft.a
PRINTF = ./ft_printf/libftprintf.a
GNL = ./gnl/gnl.a

all: $(NAME)

$(NAME): *.o $(MLX) $(LIBFT) $(GNL) $(PRINTF)
	$(CC) $(FLAGS) -o $(NAME) *.o $(MLX) $(LIBFT) $(GNL) $(PRINTF) $(FREAMS)

*.o: *.c
	$(CC) $(FLAGS) -c *.c

$(MLX):
	@make -C ./mlx

$(LIBFT):
	@make -C ./libft

$(PRINTF):
	@make -C ./ft_printf

$(GNL):
	@make -C ./gnl

clean:
	rm -f *.o
	@make clean -C ./ft_printf
	@make clean -C ./mlx
	@make clean -C ./libft
	@make clean -C ./gnl

fclean: clean
	rm -f so_long
	@make fclean -C ./ft_printf
	@make fclean -C ./libft
	@make fclean -C ./gnl

re:fclean all
