/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "include/function.h"

void increase_damage(void *tmp, int i)
{
    global_t *g = tmp;

    g->player.xp -= 100;
    g->tower[i].stat.dmg += 25;
}

void increase_range(void *tmp, int i)
{
    global_t *g = tmp;

    g->player.xp -= 100;
    g->tower[i].stat.range += 200;
}

void increase_attack_speed(void *tmp, int i)
{
    global_t *g = tmp;

    g->player.xp -= 100;
    g->tower[i].stat.AS -= 0.15;
}

void hit_armored_ennemi(void *tmp, int i)
{
    global_t *g = tmp;

    g->player.xp -= 100;
    g->tower[i].armored = 1;
}

void increase_slow(void *tmp, int i)
{
    global_t *g = tmp;

    g->player.xp -= 100;
    g->tower[i].stat.dmg += 5;
}