##
## EPITECH PROJECT, 2020
## PSU_navy_2019
## File description:
## Makefile
##

SRC_DIR		=	src/

NAVY_DIR	= 	../navy/

INC_DIR		= 	include/

LIB_DIR		=	../lib/my/

SRC			=	$(SRC_DIR)server.c					\
				$(SRC_DIR)connexion.c				\
				$(NAVY_DIR)usage.c					\
				$(NAVY_DIR)word_array.c				\
				$(NAVY_DIR)get_next_line.c			\
				$(NAVY_DIR)map/read_entiere_file.c	\
				$(NAVY_DIR)map/error_handling.c		\
				$(NAVY_DIR)map/game_map_check.c		\
				$(NAVY_DIR)map/game_map_load.c		\
				$(NAVY_DIR)map/game_board_fill.c		\
				$(NAVY_DIR)map/parse_map.c			\
				$(NAVY_DIR)map/fill_gameboard_data.c \
				$(NAVY_DIR)game/game_prepare.c		\
				$(NAVY_DIR)game/game_map_update.c	\
				$(NAVY_DIR)game/game_check_end.c		\
				$(NAVY_DIR)game/game_player_input.c	\
				$(NAVY_DIR)game/game_display.c		\
				$(NAVY_DIR)game/communicate.c		\
				$(NAVY_DIR)game/navy.c				\
				$(NAVY_DIR)game/player.c				\

OBJ			=	$(SRC:.c=.o)

NAME		=	navy_server

CFLAGS		+=	-Wall -Wextra -I./$(INC_DIR) -g

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
		gcc -o $(NAME) $(OBJ) -g

.PHONY: all clean fclean re run debugs