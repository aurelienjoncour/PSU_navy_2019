/*
** EPITECH PROJECT, 2020
** Unit_Test_Criterion
** File description:
** Test File
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "navy.h"

static const char *DISP_MAP =
{
    "1 |A B C D E F G H\n"
    "-+---------------\n"
    "1|. . 2 . . . . .\n"
    "2|. . 2 . . . . .\n"
    "3|. . . . . . . .\n"
    "4|. . . 3 3 3 . .\n"
    "5|. 4 . . . . . .\n"
    "6|. 4 . . . . . .\n"
    "7|. 4 . 5 5 5 5 5\n"
    "8|. 4 . . . . . .\n\n"
};

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(navy, t01)
{
    char **map = game_map_load("map/pos");

    cr_assert_eq(map, NULL);
}

Test(navy, t02)
{
    char **map = game_map_load("map/pos1");

    cr_assert_str_eq(map[0], "..2.....");
    cr_assert_str_eq(map[1], "..2.....");
    cr_assert_str_eq(map[2], "........");
    cr_assert_str_eq(map[3], "...333..");
    cr_assert_str_eq(map[4], ".4......");
    cr_assert_str_eq(map[5], ".4......");
    cr_assert_str_eq(map[6], ".4.55555");
    cr_assert_str_eq(map[7], ".4......");
    free_2d_array(map);
}

Test(navy, t03)
{
    char **map = game_map_load("map/pos_error");

    cr_assert_eq(map, NULL);
}

Test(navy, t04)
{
    char **map = game_map_load("map/pos_index_null");

    cr_assert_eq(map, NULL);
}

Test(navy, t05)
{
    char **map = game_map_load("map/pos_null");

    cr_assert_eq(map, NULL);
}

Test(navy, t06)
{
    char **map = game_map_load("map/pos1");

    fill_game_board(map);
    for (int i = 0; i < 8; i++)
        cr_assert_str_eq(map[i], "........");
    free_2d_array(map);
}

Test(navy, t07)
{
    char **map = game_map_load("map/pos1");
    bool ret = check_end(map);

    cr_assert_eq(ret, false);
    free_2d_array(map);
}

Test(navy, t08)
{
    char **map = game_map_load("map/pos1");
    bool ret = check_end(map);

    cr_assert_eq(ret, false);
    free_2d_array(map);
}

Test(navy, t09, .init = redirect_all_stdout)
{
    char **map = game_map_load("map/pos1");

    print_map(map, "1");
    cr_assert_stdout_eq_str(DISP_MAP);
    free_2d_array(map);
}
