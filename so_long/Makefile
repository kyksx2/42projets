NAME = so_long

GREEN=\033[1;32m

YELLOW=\033[1;33m

RESET=\033[0m

CFLAGS = -Wall -Wextra -Werror -g

SRC = 	main.c \
		check_map.c \
		check_map_utils.c \
		utils.c \
		init_map.c \
		init_moov.c \
		init_moov_utils.c \

MLX = ./mlx_linux/libmlx.a

LIBFT = ./libft/libft.a

HEAD = -I ./libft

OBJ = $(SRC:.c=.o)

all : ${NAME}

${NAME}: ${OBJ} ${MLX} ${LIBFT}
	cc ${CFLAGS} ${OBJ} -lft -L./libft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o ${NAME}
	@echo ""
	@echo ""
	@echo "${YELLOW}                                               WELCOME TO                                                ${RESET}"
	@echo "${GREEN}==========================================================================================================${RESET}"
	@echo "${GREEN}==========================================================================================================${RESET}"
	@echo "${GREEN}==                                                                                                      ==${RESET}"
	@echo "${GREEN}==  ############   ############            ##             ############   #####       ##   ###########   ==${RESET}"
	@echo "${GREEN}==  ##             ##        ##            ##             ##        ##   ##  ##      ##   ##            ==${RESET}"
	@echo "${GREEN}==  ##             ##        ##            ##             ##        ##   ##   ##     ##   ##            ==${RESET}"
	@echo "${GREEN}==  ##             ##        ##            ##             ##        ##   ##    ##    ##   ##   ######   ==${RESET}"
	@echo "${GREEN}==  ############   ##        ##            ##             ##        ##   ##     ##   ##   ##       ##   ==${RESET}"
	@echo "${GREEN}==            ##   ##        ##            ##             ##        ##   ##      ##  ##   ##       ##   ==${RESET}"
	@echo "${GREEN}==            ##   ##        ##            ##             ##        ##   ##       ## ##   ##       ##   ==${RESET}"
	@echo "${GREEN}==  ############   ############            ############   ############   ##        ####   ###########   ==${RESET}"
	@echo "${GREEN}==                                                                                                      ==${RESET}"
	@echo "${GREEN}==========================================================================================================${RESET}"
	@echo "${GREEN}==========================================================================================================${RESET}"
	@echo ""
	@echo ""

%.o: %.c
	cc ${CFLAGS} -I/usr/include -Imlx_linux -O3 -c $< ${HEAD} -o $@

${MLX} :
	@make -C ./mlx_linux

${LIBFT} :
	@make -C ./libft

clean :
	@rm -f ${OBJ}
	@make --silent -C ./mlx_linux clean
	@make --silent -C ./libft clean

fclean : clean
	@rm -f ${NAME}
	@make --silent -C ./libft fclean

re : fclean all

.PHONY : all clean fclean re