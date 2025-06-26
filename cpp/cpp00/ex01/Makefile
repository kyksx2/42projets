NAME = phonebook

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC =	main.cpp \
		phonebook.cpp \
		contact.cpp

OBJ = $(SRC:.cpp=.o)

all : ${NAME}

${NAME} : ${OBJ}
	@c++ ${CFLAGS} ${OBJ} -o ${NAME}

%o: %.cpp
	c++ ${CFLAGS} -c $< -o $@

clean :
	rm -f ${OBJ}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re