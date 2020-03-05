/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** communicate : signal
*/

#include "navy.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include "my.h"
#include "navy.h"
#include "get_next_line.h"
#include "my_printf.h"
#include "ship_t.h"
#include "signal_info_t.h"
#include "word_array.h"

void send_response(vector_t *v, char **map_enemy, int socket)
{
    int hit = 0;

    send(socket, v, sizeof(*v), 0);
    my_printf("%c%c: ", v->x + 'A', v->y + '1');
    read(socket, &hit, sizeof(int));
    update_game_map(map_enemy, v, hit);
}

vector_t receive_response(char **game_map, int socket)
{
    vector_t v = {0};
    int hit = 0;

    read(socket, &v, sizeof(v));
    my_printf("%c%c: ", v.x + 'A', v.y + '1');
    if (game_map[v.y][v.x] == '.' || game_map[v.y][v.x] == 'o'
        || game_map[v.y][v.x] == 'x') {
        update_game_map(game_map, &v, false);
    }
    else {
        update_game_map(game_map, &v, true);
        hit = 1;
    }
    send(socket, &hit, sizeof(int), 0);
    return v;
}
