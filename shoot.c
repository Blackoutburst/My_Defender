/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "include/function.h"

void shoot_straight(void *tmp, int i)
{
    global_t *g = tmp;

    for (int e = 0; e < 1000; e++) {
        if (!g->tower[i].init)
            g->tower[i].init = 0;
        else if (!g->ennemi[e].init)
            g->ennemi[e].init = 0;
        else if (pythagore(g->tower[i].pos.x + g->tower[i].rect.width/2 - \
        (g->ennemi[e].pos.x + g->ennemi[e].rect.width/2), \
        g->tower[i].pos.y + g->tower[i].rect.width/2 - \
        (g->ennemi[e].pos.y + g->ennemi[e].rect.width/2)) <= \
        square(g->tower[i].stat.range / 2)) {
            if (g->tower[i].armored - g->ennemi[e].armored >= 0)
                g->ennemi[e].hp -= g->tower[i].stat.dmg;
            draw_line(g->window, g->tower[i].pos, g->ennemi[e].pos);
            run_song(g->tower[i].sound, g);
            sfClock_restart(g->tower[i].clock);
            break;
        }
    }
}

void shoot_money(void *tmp, int i)
{
    global_t *g = tmp;
    int check = 0;

    for (int i = 0; i < 1000; i++)
        if (g->ennemi[i].init)
            check = 1;
    if (!check && g->round.spawn == -1) {
        check = 0;
    } else {
        g->player.gold += g->tower[i].stat.dmg;
        run_song(g->tower[i].sound, g);
        sfClock_restart(g->tower[i].clock);
    }
}

void shoot_slow_aoe(void *tmp, int i)
{
    global_t *g = tmp;

    for (int e = 0; e < 1000; e++) {
        if (!g->tower[i].init)
            g->tower[i].init = 0;
        else if (!g->ennemi[e].init)
            g->ennemi[e].init = 0;
        else if (pythagore(g->tower[i].pos.x + g->tower[i].rect.width/2 - \
        (g->ennemi[e].pos.x + g->ennemi[e].rect.width/2), \
        g->tower[i].pos.y + g->tower[i].rect.width/2 - \
        (g->ennemi[e].pos.y + g->ennemi[e].rect.width/2)) <= \
        square(g->tower[i].stat.range / 2)) {
            if ((int) (g->ennemi[e].stat.AS * 10.0) % 10 == 0)
                g->ennemi[e].stat.AS -= \
                g->ennemi[e].stat.AS * g->tower[i].stat.dmg / 100;
            draw_line(g->window, g->tower[i].pos, g->ennemi[e].pos);
            run_song(g->tower[i].sound, g);
            sfClock_restart(g->tower[i].clock);
        }
    }
}
