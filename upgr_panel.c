/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "include/function.h"

void check_click_on_tower(global_t *g)
{
    static int down = 0;

    if (sfMouse_isButtonPressed(sfMouseLeft) && !down && !g->selec.init) {
        for (int i = 0; i < 1000; i++)
            if (hover_button(g->tower[i], g->window) && \
            g->hud.p_upgr.pos.y == 1080)
                g->tower[i].solid = 1;
            else if (!hover_button(g->hud.p_upgr, g->window))
                g->tower[i].solid = 0;
    }
    g->hud.p_upgr.pos.y = 1080;
    for (int i = 0; i < 1000; i++)
        if (g->tower[i].solid == 1)
            g->hud.p_upgr.pos.y = 850;
    down = sfMouse_isButtonPressed(sfMouseLeft) ? 1 : 0;
}

void sell_tower(global_t *g)
{
    g->hud.sell_button.pos.y = g->hud.p_upgr.pos.y + 150;
    if (hover_button(g->hud.sell_button, g->window))
        g->hud.sell_button.rect.top = 64;
    else
        g->hud.sell_button.rect.top = 0;
    if (sfMouse_isButtonPressed(sfMouseLeft) && \
    hover_button(g->hud.sell_button, g->window)) {
        for (int i = 0; i < 1000; i++) {
            if (g->tower[i].solid == 1) {
                g->player.gold += g->tower[i].stat.cost / 3;
                g->tower[i] = model[0];
            }
        }
    }
}

void upgr_panel(global_t *g)
{
    int check = 0;

    check_click_on_tower(g);
    sell_tower(g);
    draw(g->hud.p_upgr, g->window);
    draw(g->hud.sell_button, g->window);
    for (int i = 0; i < 1000; i++)
        if (g->tower[i].init) {
            check = 1;
            break;
        }
    if (check) {
        draw(g->hud.up_but_l, g->window);
        draw(g->hud.up_but_r, g->window);
        update_visual_upgrade_buttons(g);
        update_upgrade_buttons(g);
    }
}
