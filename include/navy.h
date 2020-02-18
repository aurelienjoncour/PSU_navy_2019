/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** navy
*/

#ifndef NAVY_H_
#define NAVY_H_

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include "word_array.h"
#include "my.h"
#include "ship_t.h"
#include "signal_info_t.h"
#include "get_next_line.h"

#define EXIT_ERROR 84
#define NB_SHIP 4
#define MAP_SIZE 8

#define POS_X(LETTER) ((LETTER - 'A'))
#define POS_Y(NUMBER) (NUMBER - '1')

#define ME    "my positions:\n"
#define ENEMY "enemy's positions:\n"
#define WIN "I won\n"
#define LOOSE "Enemy won\n"

extern signal_info_t s;

int usage(int status);

bool error_data(char **data_ship);

bool wrong_number(ship_t *ship);

void print_map(char **game, char *player);

char **read_entiere_file(const char *filepath);

char **game_map(char **str);

int fill_game_board(char **game_board);

void parse_data(ship_t *data, char **data_ship, int i);

char **fill_gameboard_data(ship_t *data);

int navy(char **game_map, pid_t enemy_pid);

bool check_end(char **game_map);

bool write_attack(vector_t *v);

int kill_with_delay(pid_t pid, int signal, __useconds_t delay);

void print_2_map(char **game_map, char **map_enemy);

void update_game_map(char **map, vector_t *v, bool hit);

vector_t receive_response(char **game_map);

void send_response(vector_t v, char **map_enemy);

int player_1(char **map_enemy, char **game_map);

int player_2(char **map_enemy, char **game_map);

void wait_connection(void);

#endif /* !NAVY_H_ */
