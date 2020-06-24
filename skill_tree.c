/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "include/function.h"

void update_visual_upgrade_buttons(global_t *g)
{
    int i = 0;

    for (i = 0; i < 999; i++)
        if (g->tower[i].solid && g->tower[i].init)
            break;
    g->hud.up_but_l.rect.top = \
    hover_button(g->hud.up_but_l, g->window) ? 200 : 0;
    g->hud.up_but_r.rect.top = \
    hover_button(g->hud.up_but_r, g->window) ? 200 : 0;
    if ((g->tower[i].lupdate == 2 && g->tower[i].max) || \
    g->tower[i].lupdate == 3)
        g->hud.up_but_l.rect.top = 400;
    if ((g->tower[i].rupdate == 2 && g->tower[i].max) || \
    g->tower[i].rupdate == 3)
        g->hud.up_but_r.rect.top = 400;
    g->hud.up_but_l.pos.y = g->hud.p_upgr.pos.y + 25;
    g->hud.up_but_r.pos.y = g->hud.p_upgr.pos.y + 25;
}

void update_upgrade_buttons(global_t *g)
{
    int i = 0;
    static int down = 0;
    int check = 0;
    for (i = 0; i < 1000; i++)
        if (g->tower[i].solid && g->tower[i].init)
            break;
    if (i == 1000)
        return;
    check = upgrade_buttons_event(g, i, check);
    if (g->tower[i].lupdate == 2 && g->tower[i].max)
        g->hud.up_but_l.rect.top = 400;
    else if (g->tower[i].lupdate < 3 && !down && check)
        g->tower[i].lupdate += update_button(g->hud.up_but_l, g->window, 1, 0);
    if (g->tower[i].rupdate == 2 && g->tower[i].max)
        g->hud.up_but_r.rect.top = 400;
    else if (g->tower[i].rupdate < 3 && !down && check)
        g->tower[i].rupdate += update_button(g->hud.up_but_r, g->window, 1, 0);
    if (g->tower[i].lupdate == 3 || g->tower[i].rupdate == 3)
        g->tower[i].max = 1;
    down = sfMouse_isButtonPressed(sfMouseLeft) ? 1 : 0;
}

void upgrade_visual_buttons_event_state(global_t *g, int i)
{
    static int init = 0;
    static text_info_t txt;

    if (!init++) {
        txt = init_text_info(30, (v2f) {0, 1030});
        txt.color = sfBlack;
    }
    txt.pos.x = 630;
    txt.data = my_strcat(my_itostr(g->tower[i].lupdate), "/3");
    draw_text(txt, g->window);
    txt.pos.x = 1035;
    txt.data = my_strcat(my_itostr(g->tower[i].rupdate), "/3");
    draw_text(txt, g->window);
    g->tower[i].rect.left = 32 * (g->tower[i].lupdate + g->tower[i].rupdate);
}

void upgrade_visual_buttons_event(global_t *g, int i)
{
    if (g->tower[i].lupdate < 3)
        g->tower[i].arr[g->tower[i].lupdate].pos.y = g->hud.p_upgr.pos.y + 25;
    if (g->tower[i].rupdate < 3)
        g->tower[i].arr[g->tower[i].rupdate + 3].pos.y = \
        g->hud.p_upgr.pos.y + 25;
    if (g->hud.up_but_l.rect.top != 400)
        draw(g->tower[i].arr[g->tower[i].lupdate], g->window);
    if (g->hud.up_but_r.rect.top != 400)
        draw(g->tower[i].arr[g->tower[i].rupdate + 3], g->window);
    upgrade_visual_buttons_event_state(g, i);
}

int upgrade_buttons_event(global_t *g, int i, int check)
{
    static int down = 0;
    upgrade_visual_buttons_event(g, i);
    if (hover_button(g->hud.up_but_l, g->window) && g->player.xp >= 100 && \
    sfMouse_isButtonPressed(sfMouseLeft) && !down && g->tower[i].lupdate < 3) {
        check = 1;
        if (!g->tower[i].max)
            g->tower[i].arr[g->tower[i].lupdate].func(g, i);
        else if (g->tower[i].lupdate < 2)
            g->tower[i].arr[g->tower[i].lupdate].func(g, i);
    }
    if (hover_button(g->hud.up_but_r, g->window) && g->player.xp >= 100 && \
    sfMouse_isButtonPressed(sfMouseLeft) && !down && g->tower[i].rupdate < 3) {
        check = 1;
        if (!g->tower[i].max)
            g->tower[i].arr[g->tower[i].rupdate + 3].func(g, i);
        else if (g->tower[i].rupdate < 2)
            g->tower[i].arr[g->tower[i].rupdate + 3].func(g, i);
    }
    down = sfMouse_isButtonPressed(sfMouseLeft) ? 1 : 0;
    return (check);
}
