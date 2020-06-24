/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "include/function.h"

void display_model_panel(global_t *g)
{
    static int init = 0;
    static gameobject_t model_button;

    if (!init++)
        model_button = init_sprite("res/tower_1.pngM", 110, 110, (v2f){0, 0});
    for (int i = 1; i < NB_MODEL; i++) {
        model_button.texture = model[i].texture110;
        model_button.pos.x = g->hud.p_t.pos.x + 200 + (i-1) % 2 * 150;
        model_button.pos.y = 150 + (i-1) / 2 * 150;
        draw(model_button, g->window);
    }
}

void slide_panel_tower(gameobject_t *panel)
{
    if (panel->solid == 1) {
        if (panel->pos.x > 1420) {
            panel->pos.x -= 13;
            if ( panel->pos.x < 1420)
                panel->pos.x = 1420;
        }
    }
    if (panel->solid == 0) {
        if (panel->pos.x < 1820) {
            panel->pos.x += 13;
            if (panel->pos.x > 1820)
                panel->pos.x = 1820;
        }
    }
}

void update_selec(global_t *g)
{
    if (sfMouse_isButtonPressed(sfMouseLeft))
        for (int i = 1; i < NB_MODEL; i++)
            if (isclick((v2f){g->hud.p_t.pos.x+200+(i-1)%2*150, \
            150+(i-1)/2*150}, \
            (v2f){g->hud.p_t.pos.x+200+(i-1)%2*150+110, \
            150+(i-1)/2*150+110}, \
            g->window))
                g->selec = model[i];
    if (sfMouse_isButtonPressed(sfMouseRight))
        g->selec = model[0];
}

void tower_panel(global_t *g)
{
    static int down = 0;

    if (sfMouse_isButtonPressed(sfMouseLeft) && !down)
        if (isclick((v2f){g->hud.p_t.pos.x, 475}, \
        (v2f){g->hud.p_t.pos.x+100, 605}, g->window))
            g->hud.p_t.solid = (g->hud.p_t.solid + 1) % 2;
    slide_panel_tower(&g->hud.p_t);
    down = sfMouse_isButtonPressed(sfMouseLeft) ? 1 : 0;
    update_selec(g);
    draw(g->hud.p_t, g->window);
    display_model_panel(g);
    info_tower_panel(g);
}