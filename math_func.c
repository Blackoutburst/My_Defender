/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "include/function.h"

float square(float a)
{
    return (a*a);
}

float pythagore(float a, float b)
{
    return (square(a) + square(b));
}

void draw_line(sfRenderWindow *window, sfVector2f pos1, sfVector2f pos2)
{
    sfVertexArray *lines = sfVertexArray_create();
    pos1.x += 24;
    pos1.y += 16;
    pos2.x += 24;
    pos2.y += 16;
    sfVertex vertex1 = {.position = pos1, .color = sfBlue};
    pos1.x -= 16;
    sfVertex vertex2 = {.position = pos1, .color = sfBlue};
    sfVertex vertex3 = {.position = pos2, .color = sfBlue};
    pos2.x -= 16;
    sfVertex vertex4 = {.position = pos2, .color = sfBlue};

    sfVertexArray_append(lines, vertex1);
    sfVertexArray_append(lines, vertex2);
    sfVertexArray_append(lines, vertex3);
    sfVertexArray_append(lines, vertex4);
    sfVertexArray_setPrimitiveType(lines, sfQuads);
    sfRenderWindow_drawVertexArray(window, lines, NULL);
    sfVertexArray_destroy(lines);
}