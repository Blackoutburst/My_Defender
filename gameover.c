/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "include/function.h"

int update_gameover(global_t *g, int scene)
{
    draw(g->gameover.background, g->window);
    draw(g->gameover.title, g->window);
    draw(g->gameover.exit_but, g->window);
    scene = update_button(g->gameover.exit_but, g->window, -1, scene);
    if (hover_button(g->gameover.exit_but, g->window))
        g->gameover.exit_but.rect.top = 256;
    else
        g->gameover.exit_but.rect.top = 0;
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        scene = -1;
    return (scene);
}

menu_t init_gameover(void)
{
    menu_t gameover;
    sfVector2f origin = {0, 0};
    sfVector2f exit_pos = {704, 680.0};
    sfVector2f title_pos = {448, 0};

    gameover.exit_but = init_sprite("res/leave.png", 512, 256, exit_pos);
    gameover.title = init_sprite("res/game_over.png", 1024, 512, title_pos);
    gameover.background = init_sprite("res/background.png", 1920, 1080, origin);
    return (gameover);
}
