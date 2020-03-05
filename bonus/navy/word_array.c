/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** word_array
*/

#include "navy.h"

void free_2d_array(char **array)
{
    if (array == NULL)
        return;
    for (size_t i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}

size_t word_array_len(char **array)
{
    size_t i = 0;

    for (i = 0; array[i] != NULL; i++);
    return i;
}
