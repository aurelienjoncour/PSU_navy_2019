##
## EPITECH PROJECT, 2020
## PSU_navy_2019
## File description:
## Makefile
##

SRC_DIR		=	src/

INC_DIR		=	include/

LIB_DIR		=	lib/my/

SRC			=	$(SRC_DIR)main.c				\
				$(SRC_DIR)get_next_line.c		\
				$(SRC_DIR)read_entiere_file.c	\
				$(SRC_DIR)usage.c				\
				$(SRC_DIR)word_array.c			\
				$(SRC_DIR)error_handling.c		\
				$(SRC_DIR)game.c				\
				$(SRC_DIR)game_map.c			\
				$(SRC_DIR)parse_map.c			\
				$(SRC_DIR)navy.c				\
				$(SRC_DIR)player.c

OBJ			=	$(SRC:.c=.o)

NAME		=	navy

CFLAGS		+=	-Wall -Wextra -I./include -g

LDLFLAGS	+= -L $(LIB_DIR) -lmy

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C $(LIB_DIR)
		gcc -o $(NAME) $(OBJ) $(LDLFLAGS)

clean:
			@make clean -C $(LIB_DIR) --no-print-directory
			@rm -f $(OBJ)

fclean:		clean
			@make clean -C $(LIB_DIR) --no-print-directory
			@rm -f $(NAME)

re:	fclean all

run:	all
	./$(NAME)

debugs:	fclean all
		gcc -o $(NAME) $(OBJ) $(LDLFLAGS) -g

.PHONY: all clean fclean re run debugs
