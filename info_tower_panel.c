/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "include/function.h"

void display_info(global_t *g, gameobject_t mousehover, int x, int y)
{
    static int init = 0;
    static text_info_t txt;

    if (!init++)
        txt = init_text_info(30, (v2f) {0, 0});
    txt.pos.x = x+10;
    txt.pos.y = y+10;
    txt.data = mousehover.info;
    draw_text(txt, g->window);
}

void info_tower_panel(global_t *g)
{
    static int init = 0;
    static gameobject_t mousehover;
    static gameobject_t info;
    sfVector2f pos = {0, 0};

    if (!init++)
        info = init_sprite("res/info.png", 450, 250, (v2f) {0, 0});
    mousehover = model[0];
    for (int i = 1; i < NB_MODEL; i++) {
        pos = (v2f) {g->hud.p_t.pos.x+200+(i-1)%2*150, 150+(i-1)/2*150};
        if (isclick((v2f){pos.x, pos.y}, (v2f){pos.x+110, pos.y+110}, \
        g->window)) {
            mousehover = model[i];
            info.pos = (v2f) {pos.x - 460, pos.y - 70};
        }
    }
    if (mousehover.init) {
        draw(info, g->window);
        display_info(g, mousehover, info.pos.x, info.pos.y);
    }
}