NAME = libftprintf.a

CFLAGS	= -Wall -Wextra -Werror

SRC	=	ft_printf.c \
		ft_printchar.c \
		ft_printhex.c \
		ft_printnbr.c \
		ft_printptr.c \
		ft_printstr.c \
		ft_printunsi.c \

OBJ = ${SRC:.c=.o}

${NAME} : ${OBJ}
	gcc -c ${CFLAGS} ${SRC}
	ar -rcs ${NAME} ${OBJ}

all : ${NAME}

clean : 
	rm -f ${OBJ}

fclean :  clean
	rm -f ${NAME} 

re : fclean all

.PHONY : clean fclean re all