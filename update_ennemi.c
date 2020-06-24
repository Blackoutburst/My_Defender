/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "include/function.h"

void move_ennemi(gameobject_t *ennemi, map_t map)
{
    for (int i = 0; i < 1000; i++) {
        ennemi[i] = choose_ennemi_direction(ennemi[i], map);
        if (ennemi[i].init && ennemi[i].solid == 0)
            ennemi[i].pos.x += ennemi[i].stat.AS;
        if (ennemi[i].init && ennemi[i].solid == 1)
            ennemi[i].pos.x -= ennemi[i].stat.AS;
        if (ennemi[i].init && ennemi[i].solid == 2)
            ennemi[i].pos.y -= ennemi[i].stat.AS;
        if (ennemi[i].init && ennemi[i].solid == 3)
            ennemi[i].pos.y += ennemi[i].stat.AS;
        if ((int) (ennemi[i].stat.AS * 10.0) % 10 != 0)
            ennemi[i].rect.left = ennemi[i].rect.width;
    }
}

void draw_ennemi(global_t *g)
{
    for (int i = 0; i < 1000; i++) {
        draw(g->ennemi[i], g->window);
    }
}

void check_ennemi(global_t *g, int e)
{
    if (g->ennemi[e].hp <= 0 && g->ennemi[e].init) {
        g->player.gold += 4;
        g->player.xp += g->ennemi[e].stat.dmg;
        g->ennemi[e] = model[0];
    }
}

void update_ennemi(global_t *g)
{
    int check = 0;

    move_ennemi(g->ennemi, g->map);
    for (int i = 0; i < 1000; i++) {
        if (g->ennemi[i].init)
            check = 1;
        if (g->ennemi[i].init && g->ennemi[i].pos.x > 1920) {
            g->player.hp -= g->ennemi[i].stat.dmg;
            g->ennemi[i] = model[0];
        }
        check_ennemi(g, i);
        draw(g->ennemi[i], g->window);
    }
    if (check == 0 && g->round.spawn == -1) {
        draw(g->next_button, g->window);
        g->round.ID += update_button(g->next_button, g->window, 1, 0);
        g->next_button.rect.top = \
        hover_button(g->next_button, g->window) ? 64 : 0;
    }
}
