/*
** EPITECH PROJECT, 2020
** My Hunter
** File description:
** Windows related function
*/

#include "include/function.h"

gameobject_t *init_arr(int index)
{
    if (index == 1)
        return (arr_1());
    if (index == 2)
        return (arr_2());
    if (index == 3)
        return (arr_3());
    if (index == 4)
        return (arr_4());
    if (index == 5)
        return (arr_5());
    return (NULL);
}

HTP_t init_htp(void)
{
    HTP_t htp;

    htp.htp0 = init_sprite("res/htp0.png", 1920, 1080, (v2f){0, 0});
    htp.htp1 = init_sprite("res/htp1.png", 1920, 1080, (v2f){0, 0});
    htp.htp2 = init_sprite("res/htp2.png", 1920, 1080, (v2f){0, 0});
    htp.htp3 = init_sprite("res/htp3.png", 1920, 1080, (v2f){0, 0});
    htp.down = 1;
    return (htp);
}
