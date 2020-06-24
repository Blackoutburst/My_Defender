/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "include/function.h"

gameobject_t create_tower(sfVector2i mouse_pos, gameobject_t selec)
{
    gameobject_t tower = selec;

    tower.pos.x = (float) mouse_pos.x - selec.rect.width/2;
    tower.pos.y = (float) mouse_pos.y - selec.rect.width/2;
    tower.clock = sfClock_create();
    tower.seconde = 100;
    return (tower);
}

gameobject_t set_tower(global_t *g)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(g->window);

    for (int i = 0; i < g->map.tiles_number; i++)
        if (!g->map.tile[i].solid && \
        mouse_pos.x - g->selec.rect.width/2 < g->map.tile[i].pos.x + \
        g->map.tile[i].scale.x && \
        mouse_pos.x + g->selec.rect.width/2 > g->map.tile[i].pos.x && \
        mouse_pos.y - g->selec.rect.width/2 < g->map.tile[i].pos.y + \
        g->map.tile[i].scale.y && \
        mouse_pos.y + g->selec.rect.width/2 > g->map.tile[i].pos.y)
            return (model[0]);
    for (int i = 0; i < 1000; i++)
        if (g->tower[i].init && mouse_pos.x - g->selec.rect.width/2 < \
        g->tower[i].pos.x + g->tower[i].rect.width && \
        mouse_pos.x + g->selec.rect.width/2 > g->tower[i].pos.x && \
        mouse_pos.y - g->selec.rect.width/2 < \
        g->tower[i].pos.y + g->tower[i].rect.width && \
        mouse_pos.y + g->selec.rect.width/2 > g->tower[i].pos.y)
            return (model[0]);
    return (create_tower(mouse_pos, g->selec));
}

void place_tower(global_t *g)
{
    static int down = 0;
    int price = 0;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(g->window);

    for (int i = 0; i < 1000; i++) {
        if (g->selec.stat.cost > g->player.gold)
            break;
        if (!g->tower[i].init && g->selec.init && \
        sfMouse_isButtonPressed(sfMouseLeft) && !down && \
        mouse_pos.x < g->hud.p_t.pos.x) {
            g->tower[i] = set_tower(g);
            if (g->tower[i].init)
                price = g->selec.stat.cost;
            break;
        }
    }
    down = sfMouse_isButtonPressed(sfMouseLeft) ? 1 : 0;
    g->player.gold -= price;
}
