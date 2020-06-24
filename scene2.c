/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "include/function.h"

int scene_6(global_t *global)
{
    draw(global->htp.htp0, global->window);
    if (sfMouse_isButtonPressed(sfMouseLeft) && !global->htp.down) {
        global->htp.down = 1;
        return (7);
    }
    global->htp.down = sfMouse_isButtonPressed(sfMouseLeft) ? 1 : 0;
    return (6);
}

int scene_7(global_t *global)
{
    draw(global->htp.htp1, global->window);
    if (sfMouse_isButtonPressed(sfMouseLeft) && !global->htp.down) {
        global->htp.down = 1;
        return (8);
    }
    global->htp.down = sfMouse_isButtonPressed(sfMouseLeft) ? 1 : 0;
    return (7);
}

int scene_8(global_t *global)
{
    draw(global->htp.htp2, global->window);
    if (sfMouse_isButtonPressed(sfMouseLeft) && !global->htp.down) {
        global->htp.down = 1;
        return (9);
    }
    global->htp.down = sfMouse_isButtonPressed(sfMouseLeft) ? 1 : 0;
    return (8);
}

int scene_9(global_t *global)
{
    draw(global->htp.htp3, global->window);
    if (sfMouse_isButtonPressed(sfMouseLeft) && !global->htp.down) {
        global->htp.down = 1;
        return (1);
    }
    global->htp.down = sfMouse_isButtonPressed(sfMouseLeft) ? 1 : 0;
    return (9);
}
