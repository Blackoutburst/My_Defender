/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "include/function.h"

gameobject_t init_ennemi_0(map_t map)
{
    sfVector2f pos;
    gameobject_t ennemi;

    for (int i = 0; i < map.tiles_number; i++) {
        if (my_strcmp(map.tile[i].name, "begin")) {
            pos.x = map.tile[i].pos.x;
            pos.y = map.tile[i].pos.y + 5 + random() % 50;
        }
    }
    ennemi = init_sprite("res/ennemi_1.png", 32, 32, pos);
    ennemi.hp = 100;
    ennemi.stat.AS = 4;
    ennemi.stat.dmg = 1;
    ennemi.armored = 0;
    return (ennemi);
}

gameobject_t init_ennemi_1(map_t map)
{
    sfVector2f pos;
    gameobject_t ennemi;

    for (int i = 0; i < map.tiles_number; i++) {
        if (my_strcmp(map.tile[i].name, "begin")) {
            pos.x = map.tile[i].pos.x;
            pos.y = map.tile[i].pos.y + 5 + random() % 50;
        }
    }
    ennemi = init_sprite("res/ennemi_2.png", 45, 45, pos);
    ennemi.hp = 500;
    ennemi.stat.AS = 3;
    ennemi.stat.dmg = 2;
    ennemi.armored = 0;
    return (ennemi);
}

gameobject_t init_ennemi_2(map_t map)
{
    sfVector2f pos;
    gameobject_t ennemi;

    for (int i = 0; i < map.tiles_number; i++) {
        if (my_strcmp(map.tile[i].name, "begin")) {
            pos.x = map.tile[i].pos.x;
            pos.y = map.tile[i].pos.y + 5 + random() % 50;
        }
    }
    ennemi = init_sprite("res/ennemi_3.png", 38, 38, pos);
    ennemi.hp = 200;
    ennemi.stat.AS = 7;
    ennemi.stat.dmg = 5;
    ennemi.armored = 0;
    return (ennemi);
}

gameobject_t init_ennemi_3(map_t map)
{
    sfVector2f pos;
    gameobject_t ennemi;

    for (int i = 0; i < map.tiles_number; i++) {
        if (my_strcmp(map.tile[i].name, "begin")) {
            pos.x = map.tile[i].pos.x;
            pos.y = map.tile[i].pos.y + 5 + random() % 50;
        }
    }
    ennemi = init_sprite("res/ennemi_4.png", 54, 54, pos);
    ennemi.hp = 20000;
    ennemi.stat.AS = 2;
    ennemi.stat.dmg = 50;
    ennemi.armored = 1;
    return (ennemi);
}