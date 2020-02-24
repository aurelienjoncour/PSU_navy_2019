/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** parse_map
*/

#include "navy.h"

void parse_data(ship_t *data, char **data_ship, int i)
{
    data[i].size = my_getnbr(data_ship[0]);
    data[i].start.x = POS_X(data_ship[1][0]);
    data[i].start.y = POS_Y(data_ship[1][1]);
    data[i].end.x = POS_X(data_ship[2][0]);
    data[i].end.y = POS_Y(data_ship[2][1]);
}
