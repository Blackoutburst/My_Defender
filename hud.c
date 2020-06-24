/*
** EPITECH PROJECT, 2020
** HUD.c
** File description:
** HUD
*/

#include "include/function.h"

void draw_hud(global_t *g)
{
    top_panel(g);
    upgr_panel(g);
    tower_panel(g);
}
