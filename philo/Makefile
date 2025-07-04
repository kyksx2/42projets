NAME = philo

CFLAGS = -pthread -Wall -Werror -Wextra -g3

SRC =	main.c \
		init.c \
		parsing.c \
		utils.c \
		check.c \
		dining.c \
		solo_philo.c \

OBJ = $(SRC:.c=.o)

all : ${NAME}

${NAME} : ${OBJ}
	@cc ${CFLAGS} ${OBJ} -o ${NAME}

%o: %.c
	cc ${CFLAGS} -c $< -o $@

clean :
	rm -f ${OBJ} ${OBJ_BONUS}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re