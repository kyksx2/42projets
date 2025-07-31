NAME = Materia

CXX = c++

CXXFLAGS = -Wshadow -Wall -Werror -Wextra -std=c++98

SRC =	main.cpp \
		./src/Cure.cpp \
		./src/Ice.cpp \
		./src/Character.cpp \
		./src/Materia.cpp \
		./src/MateriaSource.cpp \
		

OBJ = $(SRC:.cpp=.o)

all : ${NAME}

${NAME} : ${OBJ}
	@c++ ${CXXFLAGS} ${OBJ} -o ${NAME}

%o: %.cpp
	c++ ${CXXFLAGS} -c $< -o $@

clean :
	rm -f ${OBJ}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re