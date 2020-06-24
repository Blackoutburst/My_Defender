/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "include/function.h"

int update_victory(global_t *g, int scene)
{
    draw(g->victory.background, g->window);
    draw(g->victory.title, g->window);
    draw(g->victory.exit_but, g->window);
    scene = update_button(g->victory.exit_but, g->window, -1, scene);
    if (hover_button(g->victory.exit_but, g->window))
        g->victory.exit_but.rect.top = 256;
    else
        g->victory.exit_but.rect.top = 0;
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        scene = -1;
    return (scene);
}

menu_t init_victory(void)
{
    menu_t victory;
    sfVector2f origin = {0, 0};
    sfVector2f exit_pos = {704, 680.0};
    sfVector2f title_pos = {448, 0};

    victory.exit_but = init_sprite("res/leave.png", 512, 256, exit_pos);
    victory.title = init_sprite("res/victory.png", 1024, 512, title_pos);
    victory.background = init_sprite("res/background.png", 1920, 1080, origin);
    return (victory);
}
