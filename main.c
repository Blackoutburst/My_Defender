/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "include/function.h"

void poll_event(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event))
    {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyP)
            sfRenderWindow_close(window);
    }
}

void description(void)
{
    write(1, "My Defender\n\n", 13);
    write(1, "USAGE:\n", 7);
    write(1, "    ./my_defender\n", 18);
    write(1, "    Launch the game.\n\n", 22);
    write(1, "HOW TO PLAY:\n", 13);
    write(1, "    Click with your mouse on the top left corner of the \
game menu to know how to play the game.\n", 96);
    write(1, "CREDITS:\n", 9);
    write(1, "    Developement : Jules MINGUET and Florian CHANSON\n", 53);
    write(1, "    All graphics : Florian CHANSON\n", 35);

}

int main(int argc, char **argv)
{
    if (argc > 1) {
        if (argv[1][0] == '-' && argv[1][1] == 'h') {
            description();
            return (0);
        }
    }
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;
    sfEvent event;
    sfImage *icon = sfImage_createFromFile("res/icon.png");

    init();
    window = sfRenderWindow_create(mode, "The Defender", sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setIcon(window, 226, 226, sfImage_getPixelsPtr(icon));
    update(window, event);
    sfImage_destroy(icon);
    return (0);
}
