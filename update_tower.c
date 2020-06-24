/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "include/function.h"

void update_shoot(global_t *g)
{
    for (int i = 0; i < 1000; i++) {
        if (g->tower[i].init) {
            if (g->tower[i].seconde >= g->tower[i].stat.AS)
                g->tower[i].func(g, i);
            g->tower[i].time = sfClock_getElapsedTime(g->tower[i].clock);
            g->tower[i].seconde = g->tower[i].time.microseconds / 1000000.0;
        }
    }
}

void update_tower(global_t *g)
{
    update_shoot(g);
}
