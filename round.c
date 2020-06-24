/*
** EPITECH PROJECT, 2020
** My Defender
** File description:
** Windows related function
*/

#include "include/function.h"

typedef gameobject_t (*func)(map_t);
const func tabl_func[4] =
{
    &init_ennemi_0,
    &init_ennemi_1,
    &init_ennemi_2,
    &init_ennemi_3
};

char *path_from_round(int round)
{
    char *path = my_strdup("round/round_**.dat");

    path[12] = round / 10 + 48;
    path[13] = round % 10 + 48;
    return (path);
}

void round_line(global_t *g)
{
    static int round = -1;
    char *ret = NULL;
    char **arr;
    size_t len = 0;

    if (round != g->round.ID) {
        round += 1;
        g->round.fd = fopen(path_from_round(g->round.ID), "r");
        g->round.time = sfClock_restart(g->round.clock);
    }
    if (getline(&ret, &len, g->round.fd) <= 1) {
        g->round.spawn = -1;
        return;
    }
    arr = my_str_to_word_array(ret);
    g->round.spawn = my_atoi(arr[1]);
    g->round.func = tabl_func[my_atoi(arr[0])];
}

void update_round(global_t *g)
{
    g->round.time = sfClock_getElapsedTime(g->round.clock);
    g->round.seconde = g->round.time.microseconds / 1000000.0;
    if (g->round.seconde >= (float) g->round.spawn / 100.0) {
        for (int i = 0; i < 1000; i++) {
            if (!g->ennemi[i].init && g->round.spawn > 0) {
                g->ennemi[i] = g->round.func(g->map);
                break;
            }
        }
        round_line(g);
    }
}