/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "include/function.h"

int update_pausemenu(global_t *g, int scene)
{
    draw(g->pausemenu.background, g->window);
    draw(g->pausemenu.play_but, g->window);
    draw(g->pausemenu.option_but, g->window);
    draw(g->pausemenu.exit_but, g->window);
    scene = update_button(g->pausemenu.play_but, g->window, 2, scene);
    scene = update_button(g->pausemenu.option_but, g->window, 1, scene);
    scene = update_button(g->pausemenu.exit_but, g->window, -1, scene);
    g->pausemenu.play_but.rect.top = 0;
    if (hover_button(g->pausemenu.play_but, g->window))
        g->pausemenu.play_but.rect.top = 128;
    g->pausemenu.option_but.rect.top = 0;
    if (hover_button(g->pausemenu.option_but, g->window))
        g->pausemenu.option_but.rect.top = 128;
    g->pausemenu.exit_but.rect.top = 0;
    if (hover_button(g->pausemenu.exit_but, g->window))
        g->pausemenu.exit_but.rect.top = 128;
    if (sfKeyboard_isKeyPressed(sfKeyReturn))
        scene = 2;
    return (scene);
}

menu_t init_pausemenu(void)
{
    menu_t pausemenu;
    sfVector2f origin = {0, 0};
    sfVector2f pp = {1920 / 2 - 128, 350.0};
    sfVector2f op = {1920 / 2 - 128, 550.0};
    sfVector2f ep = {1920 / 2 - 128, 750.0};

    pausemenu.soundBuffer = sfSoundBuffer_createFromFile("res/menu.ogg");
    pausemenu.song = sfSound_create();
    sfSound_setBuffer(pausemenu.song, pausemenu.soundBuffer);
    pausemenu.play_but = init_sprite("res/resume_button.png", 256, 128, pp);
    pausemenu.option_but = init_sprite("res/menu_button.png", 256, 128, op);
    pausemenu.exit_but = init_sprite("res/exit_button.png", 256, 128, ep);
    pausemenu.background = init_sprite("res/pausemenu.png", 1920, 1080, origin);
    return (pausemenu);
}
