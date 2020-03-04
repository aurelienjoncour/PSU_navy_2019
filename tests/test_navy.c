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
    "my positions:\n"
    " |A B C D E F G H\n"
    "-+---------------\n"
    "1|. . 2 . . . . .\n"
    "2|. . 2 . . . . .\n"
    "3|. . . . . . . .\n"
    "4|. . . 3 3 3 . .\n"
    "5|. 4 . . . . . .\n"
    "6|. 4 . . . . . .\n"
    "7|. 4 . 5 5 5 5 5\n"
    "8|. 4 . . . . . .\n\n"
    "enemy's positions:\n"
    " |A B C D E F G H\n"
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

static const char *USAGE =
{
    "USAGE\n"
    "     ./navy [first_player_pid] navy_positions\n"
    "DESCRIPTION\n"
    "     first_player_pid:  only for the 2nd player. pid of the first player"
    ".\n     navy_positions:  file representing the positions of the ships.\n"
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
    free_2d_array(NULL);
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

    print_2_map(map, map);
    cr_assert_stdout_eq_str(DISP_MAP);
    free_2d_array(map);
}

Test(navy, t10, .init = redirect_all_stdout)
{
    usage(0);
    cr_assert_stdout_eq_str(USAGE);
}

Test(navy, t11, .init = redirect_all_stdout)
{
    char **map = game_map_load("map/pos1");
    vector_t pos = {2, 0};

    update_game_map(map, &pos, true);
    cr_assert_str_eq(map[0], "..x.....");
    cr_assert_str_eq(map[1], "..2.....");
    cr_assert_str_eq(map[2], "........");
    cr_assert_str_eq(map[3], "...333..");
    cr_assert_str_eq(map[4], ".4......");
    cr_assert_str_eq(map[5], ".4......");
    cr_assert_str_eq(map[6], ".4.55555");
    cr_assert_str_eq(map[7], ".4......");
    cr_assert_stdout_eq_str("hit\n\n");
    free_2d_array(map);
}

Test(navy, t12, .init = redirect_all_stdout)
{
    char **map = game_map_load("map/pos1");
    vector_t pos = {0, 0};

    update_game_map(map, &pos, false);
    cr_assert_str_eq(map[0], "o.2.....");
    cr_assert_str_eq(map[1], "..2.....");
    cr_assert_str_eq(map[2], "........");
    cr_assert_str_eq(map[3], "...333..");
    cr_assert_str_eq(map[4], ".4......");
    cr_assert_str_eq(map[5], ".4......");
    cr_assert_str_eq(map[6], ".4.55555");
    cr_assert_str_eq(map[7], ".4......");
    cr_assert_stdout_eq_str("missed\n\n");
    free_2d_array(map);
}

Test(navy, t13)
{
    char **map = game_map_load("map/pos_wrong_ship");
    char **ret = game_map_check(map);

    cr_assert_null(ret);
}

Test(navy, t14)
{
    char **data_ship = malloc(sizeof(char *) * 4);

    data_ship[0] = my_strdup("22");
    data_ship[1] = my_strdup("C1");
    data_ship[2] = my_strdup("C2");
    data_ship[3] = NULL;

    cr_assert(error_data(data_ship));
}

Test(navy, t15)
{
    char **data_ship = malloc(sizeof(char *) * 4);

    data_ship[0] = my_strdup("2");
    data_ship[1] = my_strdup("C1");
    data_ship[2] = my_strdup("C20");
    data_ship[3] = NULL;

    cr_assert(error_data(data_ship));
}

Test(navy, t16)
{
    char **data_ship = malloc(sizeof(char *) * 4);

    data_ship[0] = my_strdup("1");
    data_ship[1] = my_strdup("C1");
    data_ship[2] = my_strdup("C2");
    data_ship[3] = NULL;

    cr_assert(error_data(data_ship));
}

Test(navy, t17)
{
    char **data_ship = malloc(sizeof(char *) * 4);

    data_ship[0] = my_strdup("2");
    data_ship[1] = my_strdup("C1");
    data_ship[2] = my_strdup("C3");
    data_ship[3] = NULL;

    cr_assert(error_data(data_ship));
}

Test(navy, t18)
{
    char **data_ship = malloc(sizeof(char *) * 4);

    data_ship[0] = my_strdup("2");
    data_ship[1] = my_strdup("I1");
    data_ship[2] = my_strdup("I2");
    data_ship[3] = NULL;

    cr_assert(error_data(data_ship));
}

Test(navy, t19, .init = redirect_all_stdout)
{
    cr_assert_eq(player_init(3), 84);
    player_init(2);
    cr_assert_stdout_eq_str("successfully connected\n\n");
}

Test(navy, t20)
{
    char **map = malloc(sizeof(char *) * 9);

    map[0] = my_strdup("..x.....");
    map[1] = my_strdup("..x.....");
    map[2] = my_strdup("........");
    map[3] = my_strdup("...xxx..");
    map[4] = my_strdup(".x......");
    map[5] = my_strdup(".x......");
    map[6] = my_strdup(".x.xxxxx");
    map[7] = my_strdup(".x......");
    map[8] = NULL;
    cr_assert(check_end(map));
}
