/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "include/function.h"

map_t init_game(void)
{
    map_t game;
    sfVector2f origin = {0, 0};
    char *buffer = read_map("map/map1.dat");

    game.map_render = init_sprite("res/map.png", 1920, 1080, origin);
    game.tiles_number = count_lines(buffer);
    game.tile = generate_map(buffer, game.tiles_number);
    return (game);
}

gameobject_t *init_list_gameobject(void)
{
    gameobject_t *list = malloc(sizeof(gameobject_t) * 1000);

    for (int i = 0; i < 1000; i++)
        list[i] = model[0];
    return (list);
}

player_info_t init_player(void)
{
    player_info_t player;

    player.gold = 500;
    player.hp = 100;
    player.xp = 0;
    return (player);
}

HUD_t init_hud(void)
{
    HUD_t hud;

    sfVector2f left_pos = {350, 2000};
    sfVector2f right_pos = {750, 2000};

    hud.up_but_l = init_sprite("res/upgrade.png", 350, 200, left_pos);
    hud.up_but_r = init_sprite("res/upgrade.png", 350, 200, right_pos);
    hud.p_top = init_sprite("res/top_panel.png", 1920, 70, (v2f){0, 0});
    hud.p_upgr = init_sprite("res/upgr_panel.png", 1050, 256, (v2f){310, 850});
    hud.p_t = init_sprite("res/tower_panel.png", 500, 1080, (v2f){1820, 0});
    hud.sell_button = init_sprite("res/sell_button.png", 128, 64, (v2f){1150, \
    hud.p_upgr.pos.y + 150});
    return (hud);
}

round_info_t init_round(void)
{
    round_info_t ret;

    ret.ID = 0;
    ret.clock = sfClock_create();
    ret.time = sfClock_getElapsedTime(ret.clock);
    ret.seconde = 0;
    ret.spawn = -1;
    return (ret);
}
