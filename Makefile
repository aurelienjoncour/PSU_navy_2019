##
## EPITECH PROJECT, 2020
## PSU_navy_2019
## File description:
## Makefile
##

SRC_DIR		=	src/

INC_DIR		=	include/

LIB_DIR		=	lib/my/

SRC			=	$(SRC_DIR)main.c					\
				$(SRC_DIR)usage.c					\
				$(SRC_DIR)word_array.c				\
				$(SRC_DIR)get_next_line.c			\
				$(SRC_DIR)map/read_entiere_file.c	\
				$(SRC_DIR)map/error_handling.c		\
				$(SRC_DIR)map/game_map_check.c		\
				$(SRC_DIR)map/game_map_load.c		\
				$(SRC_DIR)map/game_board_fill.c		\
				$(SRC_DIR)map/parse_map.c			\
				$(SRC_DIR)map/fill_gameboard_data.c \
				$(SRC_DIR)game/game_prepare.c		\
				$(SRC_DIR)game/game_map_update.c	\
				$(SRC_DIR)game/game_check_end.c		\
				$(SRC_DIR)game/game_player_input.c	\
				$(SRC_DIR)game/game_display.c		\
				$(SRC_DIR)game/communicate.c		\
				$(SRC_DIR)game/navy.c				\
				$(SRC_DIR)game/player.c				\
				$(SRC_DIR)game/player_init.c		\

UTSRC		=	tests/test_navy.c					\
				$(SRC_DIR)usage.c					\
				$(SRC_DIR)word_array.c				\
				$(SRC_DIR)get_next_line.c			\
				$(SRC_DIR)map/read_entiere_file.c	\
				$(SRC_DIR)map/error_handling.c		\
				$(SRC_DIR)map/game_map_check.c		\
				$(SRC_DIR)map/game_map_load.c		\
				$(SRC_DIR)map/game_board_fill.c		\
				$(SRC_DIR)map/parse_map.c			\
				$(SRC_DIR)map/fill_gameboard_data.c \
				$(SRC_DIR)game/game_prepare.c		\
				$(SRC_DIR)game/game_map_update.c	\
				$(SRC_DIR)game/game_check_end.c		\
				$(SRC_DIR)game/game_player_input.c	\
				$(SRC_DIR)game/game_display.c		\
				$(SRC_DIR)game/communicate.c		\
				$(SRC_DIR)game/navy.c				\
				$(SRC_DIR)game/player.c				\
				$(SRC_DIR)game/player_init.c		\

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

tests_run:
	gcc -o $(NAME) $(UTSRC) -I./include -L./lib/my -lmy -lcriterion --coverage && ./$(NAME)

run:	all
	./$(NAME)

debugs:	fclean all
		gcc -o $(NAME) $(OBJ) $(LDLFLAGS) -g

.PHONY: all clean fclean re run debugs
