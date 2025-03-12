NAME = pipex

CFLAGS = -Wall -Werror -Wextra -g

SRC =	main.c \
		pipex_utils.c \
		pipex_utils_2.c \

SRC_BONUS = ./bonus/main_bonus.c \
			pipex_utils.c \
			./bonus/utils_bonus.c \
			./bonus/cmd_bonus.c \
			./bonus/redir_bonus.c \
			./bonus/here_doc.c \

HEAD = -I ./libft

LIBFT = ./libft/libft.a

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : ${NAME}

${NAME} : ${OBJ} ${LIBFT}
	@cc ${CFLAGS} ${OBJ} -lft -L./libft -o ${NAME}

bonus : ${OBJ_BONUS} ${LIBFT}
	@cc ${CFLAGS} ${OBJ_BONUS} -lft -L./libft -o ${NAME}

%o: %.c
	cc ${CFLAGS} -c $< ${HEAD} -o $@

${LIBFT} :
	@make --silent -C ./libft

clean :
	rm -f ${OBJ} ${OBJ_BONUS}
	@make --silent -C ./libft clean

fclean : clean
	rm -f ${NAME}
	@make --silent -C ./libft fclean

re : fclean all

.PHONY : all bonus clean fclean re