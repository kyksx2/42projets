NAME = Bureaucrat

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC =	main.cpp \
		./src/AForm.cpp \
		./src/Bureaucrat.cpp \
		./src/PresidentialPardonForm.cpp \
		./src/RobotomyRequestForm.cpp \
		./src/ShrubberyCreationForm.cpp \
		./src/Intern.cpp \

OBJ = $(SRC:.cpp=.o)

all : ${NAME}

${NAME} : ${OBJ}
	@c++ ${CXXFLAGS} ${OBJ} -o ${NAME}

%.o: %.cpp
	c++ ${CXXFLAGS} -c $< -o $@

clean :
	rm -f ${OBJ}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re