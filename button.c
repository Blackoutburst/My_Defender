/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** parralax function
*/

#include "include/function.h"

int hover_button(gameobject_t obj, sfRenderWindow *win)
{
    sfVector2i m_pos = {0, 0};

    m_pos = sfMouse_getPositionRenderWindow(win);
    if (m_pos.x >= obj.pos.x && m_pos.x <= obj.pos.x + obj.rect.width && \
    m_pos.y >= obj.pos.y && m_pos.y <= obj.pos.y + obj.rect.height)
        return (1);
    return (0);
}

int update_button(gameobject_t obj, sfRenderWindow *win, int cval, int scene)
{
    sfVector2i m_pos = {0, 0};

    m_pos = sfMouse_getPositionRenderWindow(win);
    if (m_pos.x >= obj.pos.x && m_pos.x <= obj.pos.x + obj.rect.width && \
    m_pos.y >= obj.pos.y && m_pos.y <= obj.pos.y + obj.rect.height)
        obj.solid = 1;
    else
        obj.solid = 0;
    if (obj.solid && sfMouse_isButtonPressed(sfMouseLeft) && !obj.rotation)
        scene = cval;
    obj.rotation = sfMouse_isButtonPressed(sfMouseLeft) ? 1 : 0;
    return (scene);
}
