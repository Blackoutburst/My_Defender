/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "include/function.h"

void top_panel(global_t *g)
{
    static int init = 0;
    static text_info_t info;

    if (!init++)
        info = init_text_info(35, (v2f) {85, 7});
    draw(g->hud.p_top, g->window);
    info.pos.x = 85;
    info.data = my_itostr(g->player.gold);
    draw_text(info, g->window);
    info.pos.x = 430;
    info.data = my_itostr(g->player.hp);
    draw_text(info, g->window);
    info.pos.x = 760;
    info.data = my_itostr(g->player.xp);
    draw_text(info, g->window);
    info.pos.x = 1180;
    info.data = my_itostr(g->round.ID);
    draw_text(info, g->window);
}