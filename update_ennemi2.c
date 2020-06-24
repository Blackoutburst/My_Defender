/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "include/function.h"

gameobject_t choose_ennemi_direction(gameobject_t e, map_t m)
{
    for (int i = 0; i < m.tiles_number; i++) {
        if (e.pos.x + 16 >= m.tile[i].pos.x && \
        e.pos.x + 16 <= m.tile[i].pos.x + 30 && \
        e.pos.y + 16 >= m.tile[i].pos.y && \
        e.pos.y + 16 <= m.tile[i].pos.y + 30 && \
        my_strcmp("droite", m.tile[i].name))
            e.solid = 0;
        if (e.pos.x + 16 >= m.tile[i].pos.x && \
        e.pos.x + 16 <= m.tile[i].pos.x + 30 && \
        e.pos.y + 16 >= m.tile[i].pos.y && \
        e.pos.y + 16 <= m.tile[i].pos.y + 30 && \
        my_strcmp("gauche", m.tile[i].name))
            e.solid = 1;
    }
    return (choose_ennemi_direction_2(e, m));
}

gameobject_t choose_ennemi_direction_2(gameobject_t e, map_t m)
{
    for (int i = 0; i < m.tiles_number; i++) {
        if (e.pos.x + 16 >= m.tile[i].pos.x && \
        e.pos.x + 16 <= m.tile[i].pos.x + 30 && \
        e.pos.y + 16 >= m.tile[i].pos.y && \
        e.pos.y + 16 <= m.tile[i].pos.y + 30 && \
        my_strcmp("haut", m.tile[i].name))
            e.solid = 2;
        if (e.pos.x + 16 >= m.tile[i].pos.x && \
        e.pos.x + 16 <= m.tile[i].pos.x + 30 && \
        e.pos.y + 16 >= m.tile[i].pos.y && \
        e.pos.y + 16 <= m.tile[i].pos.y + 30 && \
        my_strcmp("bas", m.tile[i].name))
            e.solid = 3;
    }
    return (e);
}
