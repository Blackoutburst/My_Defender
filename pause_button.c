/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "include/function.h"

int update_pause_button(global_t *g, int scene)
{
    scene = update_button(g->pause_button, g->window, 3, scene);
    if (hover_button(g->pause_button, g->window))
        g->pause_button.rect.top = 50;
    else
        g->pause_button.rect.top = 0;
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        scene = 3;
    return (scene);
}
