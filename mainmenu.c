/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "include/function.h"

global_t *hover_main_mute(global_t *g)
{
    if (g->muted)
        g->mainmenu.sound_but.rect.left = 100;
    else
        g->mainmenu.sound_but.rect.left = 0;
    if (hover_button(g->mainmenu.sound_but, g->window))
        g->mainmenu.sound_but.rect.top = 100;
    else
        g->mainmenu.sound_but.rect.top = 0;
    return (g);
}

global_t *hover_main(global_t *g)
{
    if (hover_button(g->mainmenu.option_but, g->window))
        g->mainmenu.option_but.rect.top = 64;
    else
        g->mainmenu.option_but.rect.top = 0;
    if (hover_button(g->mainmenu.play_but, g->window))
        g->mainmenu.play_but.rect.top = 256;
    else
        g->mainmenu.play_but.rect.top = 0;
    if (hover_button(g->mainmenu.exit_but, g->window))
        g->mainmenu.exit_but.rect.top = 256;
    else
        g->mainmenu.exit_but.rect.top = 0;
    g = hover_main_mute(g);
    return (g);
}

int update_mainmenu(global_t *g, int scene)
{
    draw(g->mainmenu.background, g->window);
    draw(g->mainmenu.title, g->window);
    draw(g->mainmenu.play_but, g->window);
    draw(g->mainmenu.exit_but, g->window);
    draw(g->mainmenu.option_but, g->window);
    draw(g->mainmenu.sound_but, g->window);
    if (!g->htp.down) {
        scene = update_button(g->mainmenu.option_but, g->window, 6, scene);
        scene = update_button(g->mainmenu.play_but, g->window, 2, scene);
        scene = update_button(g->mainmenu.exit_but, g->window, -1, scene);
    }
    if (!g->muted && !g->htp.down)
        g->muted = update_button(g->mainmenu.sound_but, g->window, 1, g->muted);
    else if (!g->htp.down)
        g->muted = update_button(g->mainmenu.sound_but, g->window, 0, g->muted);
    g->htp.down = sfMouse_isButtonPressed(sfMouseLeft) ? 1 : 0;
    g = hover_main(g);
    if (sfKeyboard_isKeyPressed(sfKeyReturn))
        scene = 2;
    return (scene);
}

menu_t init_mainmenu(void)
{
    menu_t mainmenu;
    sfVector2f ori = {0, 0};
    sfVector2f play_pos = {458, 680.0};
    sfVector2f exit_pos = {980, 680.0};
    sfVector2f htp_pos = {0, 0};
    sfVector2f title_pos = {448, 0};
    sfVector2f sound_pos = {1820, 0};

    mainmenu.soundBuffer = sfSoundBuffer_createFromFile("res/menu.ogg");
    mainmenu.song = sfSound_create();
    sfSound_setBuffer(mainmenu.song, mainmenu.soundBuffer);
    mainmenu.play_but = init_sprite("res/play.png", 512, 256, play_pos);
    mainmenu.option_but = init_sprite("res/htp.png", 256, 64, htp_pos);
    mainmenu.exit_but = init_sprite("res/leave.png", 512, 256, exit_pos);
    mainmenu.sound_but = init_sprite("res/sound.png", 100, 100, sound_pos);
    mainmenu.title = init_sprite("res/title.png", 1024, 512, title_pos);
    mainmenu.background = init_sprite("res/background.png", 1920, 1080, ori);
    return (mainmenu);
}
