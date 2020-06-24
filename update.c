/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "include/function.h"

global_t *init_global(void)
{
    global_t *global = malloc(sizeof(global_t));
    sfVector2f pbp = {1920 - 50, 0};

    global->map = init_game();
    global->tower = init_list_gameobject();
    global->ennemi = init_list_gameobject();
    global->bullet = init_list_gameobject();
    global->player = init_player();
    global->mainmenu = init_mainmenu();
    global->pausemenu = init_pausemenu();
    global->gameover = init_gameover();
    global->victory = init_victory();
    global->selec = model[0];
    global->hud = init_hud();
    global->round = init_round();
    global->htp = init_htp();
    global->muted = 0;
    global->pause_button = init_sprite("res/pause_button.png", 50, 50, pbp);
    global->next_button = init_sprite("res/skip.png", 64, 64, (v2f) {0, 1016});
    return (global);
}

int update_game2(global_t *global, int scene)
{
    if (scene == 4)
        scene = scene_4(global);
    if (scene == 5)
        scene = scene_5(global);
    if (scene == 6)
        scene = scene_6(global);
    if (scene == 7)
        scene = scene_7(global);
    if (scene == 8)
        scene = scene_8(global);
    if (scene == 9)
        scene = scene_9(global);
    return (scene);
}

int update_game(global_t *global)
{
    static int scene = 0;

    if (scene == 0) {
        scene++;
        loop_song(global->mainmenu.song);
        run_song(global->mainmenu.song, global);
    }
    if (scene == 1)
        scene = scene_1(global);
    if (scene == 2)
        scene = scene_2(global);
    if (scene == 3)
        scene = scene_3(global);
    scene = update_game2(global, scene);
    return (scene);
}

void update(sfRenderWindow *window, sfEvent event)
{
    global_t *global = init_global();

    global->window = window;
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear (window, sfBlack);
        poll_event(window, event);
        if (update_game(global) == -1)
            break;
        sfRenderWindow_display(window);
    }
}
