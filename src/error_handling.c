/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** error_handling
*/

#include "navy.h"

static bool check_data_len(char **data_ship)
{
    if (my_strlen(data_ship[0]) != 1)
        return true;
    if (my_strlen(data_ship[1]) != 2 || my_strlen(data_ship[2]) != 2)
        return true;
    return false;
}

static bool check_interval(char **data_ship)
{
    for (size_t i = 1; i < 3; i++)
        if (data_ship[i][0] < 'A' || data_ship[i][0] > 'H')
            return true;
    for (size_t i = 1; i < 3; i++)
        if (data_ship[i][1] < '1' || data_ship[i][1] > '8')
            return true;
    return false;
}

static bool check_length(char **data_ship, int length)
{
    if (data_ship[1][0] != data_ship[2][0]  &&
        data_ship[1][1] == data_ship[2][1])
        if ((data_ship[2][0] - data_ship[1][0]) == length - 1)
            return false;
    if (data_ship[1][0] == data_ship[2][0] &&
        data_ship[1][1] != data_ship[2][1])
        if ((data_ship[2][1] - data_ship[1][1]) == length - 1)
            return false;
    return true;
}

bool error_data(char **data_ship)
{
    int length;

    if (word_array_len(data_ship) != 3)
        return true;
    if (check_data_len(data_ship))
        return true;
    length = my_getnbr(data_ship[0]);
    if (length < 2 || length > 5)
        return true;
    if (check_interval(data_ship))
        return true;
    if (check_length(data_ship, length))
        return true;
    return false;
}

bool wrong_number(ship_t *ship)
{
    bool ship_len[NB_SHIP] = {0};

    for (size_t i = 0; i < NB_SHIP; i++)
        ship_len[ship[i].size - 2] = true;
    for (size_t i = 0; i < NB_SHIP; i++)
        if (!ship_len[i])
            return true;
    return false;
}