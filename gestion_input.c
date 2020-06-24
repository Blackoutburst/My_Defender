/*
** EPITECH PROJECT, 2019
** window.c
** File description:
** init and update window
*/

#include "include/function.h"

int isclick(sfVector2f pos, sfVector2f len, sfRenderWindow *window)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (mouse.x < pos.x || mouse.x > len.x)
        return (0);
    if (mouse.y < pos.y || mouse.y > len.y)
        return (0);
    return (1);
}