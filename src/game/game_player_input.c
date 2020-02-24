/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** game
*/

#include "navy.h"

static int check_content_attack(char *str, vector_t *v)
{
    v->x = POS_X(str[0]);
    v->y = POS_Y(str[1]);
    if (v->y >= MAP_SIZE || v->x >= MAP_SIZE) {
        free(str);
        my_putstr("wrong position\n");
        return EXIT_ERROR;
    }
    return EXIT_SUCCESS;
}

bool write_attack(vector_t *v)
{
    char *str;

    while (1) {
        my_putstr("attack: ");
        str = get_next_line(STDIN_FILENO);
        if (str == NULL)
            break;
        if (my_strlen(str) != 2) {
            free(str);
            my_putstr("wrong position\n");
            continue;
        }
        if (check_content_attack(str, v) == EXIT_ERROR)
            continue;
        free(str);
        return true;
    }
    return false;
}
