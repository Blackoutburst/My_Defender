/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "include/function.h"

int scene_1(global_t *global)
{
    int val = update_mainmenu(global, 1);

    if (global->muted)
        sfSound_setVolume(global->mainmenu.song, 0.0f);
    else
        sfSound_setVolume(global->mainmenu.song, 100.0f);
    return (val);
}

int scene_2(global_t *global)
{
    draw(global->map.map_render, global->window);
    for (int i = 0; i < 1000; i++)
        draw(global->tower[i], global->window);
    update_round(global);
    place_tower(global);
    render_preview(global);
    update_ennemi(global);
    update_tower(global);
    draw_hud(global);
    draw(global->pause_button, global->window);
    if (global->player.hp <= 0)
        return (4);
    if (global->round.ID == 51)
        return (5);
    return (update_pause_button(global, 2));
}

int scene_3(global_t *global)
{
    draw(global->map.map_render, global->window);
    for (int i = 0; i < 1000; i++)
        draw(global->tower[i], global->window);
    draw_hud(global);
    draw(global->pause_button, global->window);
    draw_ennemi(global);
    return (update_pausemenu(global, 3));
}

int scene_4(global_t *global)
{
    int val = update_gameover(global, 4);

    return (val);
}

int scene_5(global_t *global)
{
    int val = update_victory(global, 5);

    return (val);
}
