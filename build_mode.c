/*
** EPITECH PROJECT, 2020
** My Runner
** File description:
** All function prototype
*/

#include "include/function.h"

sfColor is_placable(sfRenderWindow *window, map_t m, gameobject_t *towers, \
gameobject_t sp)
{
    sfVector2i m_p = sfMouse_getPositionRenderWindow(window);

    for (int i = 0; i < m.tiles_number; i++)
        if (!m.tile[i].solid \
        && m_p.x - sp.rect.width/2 < m.tile[i].pos.x + m.tile[i].scale.x && \
        m_p.x + sp.rect.width/2 > m.tile[i].pos.x && \
        m_p.y - sp.rect.width/2 < m.tile[i].pos.y + m.tile[i].scale.y && \
        m_p.y + sp.rect.width/2 > m.tile[i].pos.y)
            return ((sfColor) {255, 0, 0, 255});
    for (int i = 0; i < 1000; i++)
        if (towers[i].init && \
        m_p.x - sp.rect.width/2 < \
        towers[i].pos.x + towers[i].rect.width && \
        m_p.x + sp.rect.width/2 > towers[i].pos.x && \
        m_p.y - sp.rect.width/2 < \
        towers[i].pos.y + towers[i].rect.width && \
        m_p.y + sp.rect.width/2 > towers[i].pos.y)
            return ((sfColor) {255, 0, 0, 255});
    return ((sfColor) {0, 255, 0, 255});
}

void render_all_range(gameobject_t *towers, sfRenderWindow *win, sfSprite *sp)
{
    sfVector2f pos;
    sfColor color = (sfColor) {255, 255, 255, 100};

    for (int i = 0; i < 1000; i++)
        if (towers[i].init && towers[i].solid) {
            sfSprite_setScale(sp, (sfVector2f) {towers[i].stat.range/256.0, \
            towers[i].stat.range/256.0});
            pos = (sfVector2f) {\
            towers[i].pos.x - towers[i].stat.range/2+towers[i].rect.width/2, \
            towers[i].pos.y - towers[i].stat.range/2+towers[i].rect.width/2};
            sfSprite_setPosition(sp, pos);
            sfSprite_setColor(sp, color);
            sfRenderWindow_drawSprite(win, sp, NULL);
        }

}

void render_range(global_t *g)
{
    static int init = 0;
    static gameobject_t sp;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(g->window);

    if (!init++)
        sp = init_sprite("res/range.png", 256, 256, (sfVector2f) {0, 0});
    render_all_range(g->tower, g->window, sp.sprite);
    sp.color = is_placable(g->window, g->map, g->tower, g->selec);
    sp.pos = (sfVector2f) {mouse_pos.x - g->selec.stat.range/2, \
    mouse_pos.y - g->selec.stat.range/2};
    if (g->selec.stat.cost > g->player.gold)
        sp.color = (sfColor) {255, 0, 0, 255};
    sfSprite_setColor(sp.sprite, sp.color);
    sp.scale = (sfVector2f) {g->selec.stat.range/256.0, \
    g->selec.stat.range/256.0};
    draw(sp, g->window);
}

void render_preview(global_t *g)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(g->window);

    g->selec.color = is_placable(g->window, g->map, g->tower, g->selec);
    g->selec.pos = (sfVector2f) {mouse_pos.x - \
    g->selec.rect.width/2, mouse_pos.y - g->selec.rect.width/2};
    render_range(g);
    draw(g->selec, g->window);
}
