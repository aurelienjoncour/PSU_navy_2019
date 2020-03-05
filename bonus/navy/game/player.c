/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** player
*/

#include "navy.h"

static void get_enemy_command(vector_t *v, char **game_map, int socket)
{
    my_putstr("waiting for enemy's attack...\n");
    (*v) = receive_response(game_map, socket);
}

static bool check_end_after_command(char **game_map, char **map_enemy,
int player_id)
{
    char **map_check = NULL;

    if (player_id == 2)
        map_check = game_map;
    else
        map_check = map_enemy;
    if (check_end(map_check)) {
        print_2_map(game_map, map_enemy);
        return true;
    }
    return false;
}

static int send_command(vector_t *v, char **map_enemy, int socket)
{
    if (!write_attack(v))
        return EXIT_ERROR;
    send_response(v, map_enemy, socket);
    return EXIT_SUCCESS;
}

static bool player_print_and_check(char **map_enemy, char **game_map)
{
    print_2_map(game_map, map_enemy);
    if (check_end(game_map) || check_end(map_enemy))
        return true;
    return false;
}

int player(char **map_enemy, char **game_map, int player_id, int socket)
{
    vector_t v = {0};

    while (!check_end(game_map) || check_end(map_enemy)) {
        if (player_print_and_check(map_enemy, game_map))
            break;
        if (player_id == 2)
            get_enemy_command(&v, game_map, socket);
        else if (player_id == 1)
            send_command(&v, map_enemy, socket);
        if (check_end_after_command(game_map, map_enemy, player_id))
            break;
        if (player_id == 2 && send_command(&v, map_enemy, socket) == 84)
            return EXIT_ERROR;
        else if (player_id == 1)
            get_enemy_command(&v, game_map, socket);
    }
    free_2d_array(map_enemy);
    return EXIT_SUCCESS;
}
