NAME = push_swap

CFLAGS = -Wall -Werror -Wextra -g

SRC = 	check_args_utils.c \
		check_args.c \
		ft_atol.c \
		push_cmd.c \
		reverse_cmd.c \
		rotate_cmd.c \
		hard_sort.c \
		hard_sort_utils.c \
		simple_sort.c \
		simple_sort_utils.c \
		sort_cmd.c \
		swap_cmd.c \
		utils.c \
		main.c \
		print_stack.c \

HEAD = -I ./libft

LIBFT = ./libft/libft.a

OBJ = $(SRC:.c=.o)

all : ${NAME}

${NAME} : ${OBJ} ${LIBFT}
	@cc ${CFLAGS} ${OBJ} -lft -L./libft -o ${NAME}

%.o: %.c
	cc ${CFLAGS} -c $< ${HEAD} -o $@

${LIBFT} :
	@make --silent -C ./libft

clean :
	@rm -f ${OBJ}
	@make --silent -C ./libft clean

fclean : clean
	@rm -f ${NAME}
	@make --silent -C ./libft fclean

re : fclean all

.PHONY : all clean fclean re