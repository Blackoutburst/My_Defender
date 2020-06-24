/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "include/function.h"

void increase_gold(void *tmp, int i)
{
    global_t *g = tmp;

    g->player.xp -= 100;
    g->player.gold += 500;
}