/*
** EPITECH PROJECT, 2020
** My Runner
** File description:
** Map loader function
*/

#include "include/function.h"

void fill_map(gameobject_t *tile, int line, char **arg)
{
    tile[line].pos.x = my_atoi(arg[1]);
    tile[line].pos.y = my_atoi(arg[2]);
    tile[line].scale.x = my_atoi(arg[3]);
    tile[line].scale.y = my_atoi(arg[4]);
    tile[line].solid = arg[5][0] == 'f' ? 0 : 1;
    tile[line].rotation = my_atoi(arg[6]);
    tile[line].texture = NULL;
    tile[line].sprite = sfSprite_create();
    tile[line].name = arg[7];
    tile[line].rect = (sfIntRect) {0, 0, 64, 64};
    tile[line].init = 1;
}

void clean_args(char **arg)
{
    for (int p = 0; p < 8; p++) {
        arg[p] = malloc(sizeof(char) * 30);
        for (int k = 0; k < 30; k++) {
            arg[p][k] = 0;
        }
    }
}

map_t fill_arg(char **arg, char c, map_t offset)
{
    if (c == ' ') {
        offset.pos++;
        offset.x = 0;
    }
    if (c != ' ') {
        arg[offset.pos][offset.x] = c;
        offset.x++;
    }
    return (offset);
}

gameobject_t *generate_map(char *buffer, int tiles_number)
{
    int line = 0;
    gameobject_t *tile = malloc(sizeof(*tile) * tiles_number);
    char **arg;
    map_t offset;

    for (int i = 0; buffer[i]; i++) {
        offset.x = 0;
        offset.pos = 0;
        arg = malloc(sizeof(char *) * 8);
        clean_args(arg);
        while (buffer[i] != '\n') {
            offset = fill_arg(arg, buffer[i], offset);
            i++;
        }
        fill_map(tile, line, arg);
        line++;
    }
    return (tile);
}
