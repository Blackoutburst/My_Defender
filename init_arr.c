/*
** EPITECH PROJECT, 2019
** window.c
** File description:
** init and update window
*/

#include "include/function.h"

gameobject_t *arr_1(void)
{
    gameobject_t *ret = malloc(sizeof(gameobject_t) * 6);

    ret[0] = init_sprite("res/armoredup.png", 350, 200, (sfVector2f) {350, 0});
    ret[0].func = hit_armored_ennemi;
    ret[1] = init_sprite("res/rangeup.png", 350, 200, (sfVector2f) {350, 0});
    ret[1].func = increase_range;
    ret[2] = init_sprite("res/rangeup.png", 350, 200, (sfVector2f) {350, 0});
    ret[2].func = increase_range;
    ret[3] = init_sprite("res/dpsup.png", 350, 200, (sfVector2f) {750, 0});
    ret[3].func = increase_attack_speed;
    ret[4] = init_sprite("res/dpsup.png", 350, 200, (sfVector2f) {750, 0});
    ret[4].func = increase_attack_speed;
    ret[5] = init_sprite("res/dpsup.png", 350, 200, (sfVector2f) {750, 0});
    ret[5].func = increase_attack_speed;
    return (ret);
}

gameobject_t *arr_2(void)
{
    gameobject_t *ret = malloc(sizeof(gameobject_t) * 6);

    ret[0] = init_sprite("res/dmgup.png", 350, 200, (sfVector2f) {350, 0});
    ret[0].func = increase_damage;
    ret[1] = init_sprite("res/dmgup.png", 350, 200, (sfVector2f) {350, 0});
    ret[1].func = increase_damage;
    ret[2] = init_sprite("res/dmgup.png", 350, 200, (sfVector2f) {350, 0});
    ret[2].func = increase_damage;
    ret[3] = init_sprite("res/rangeup.png", 350, 200, (sfVector2f) {750, 0});
    ret[3].func = increase_range;
    ret[4] = init_sprite("res/rangeup.png", 350, 200, (sfVector2f) {750, 0});
    ret[4].func = increase_range;
    ret[5] = init_sprite("res/rangeup.png", 350, 200, (sfVector2f) {750, 0});
    ret[5].func = increase_range;
    return (ret);
}

gameobject_t *arr_3(void)
{
    gameobject_t *ret = malloc(sizeof(gameobject_t) * 6);

    ret[0] = init_sprite("res/dmgup.png", 350, 200, (sfVector2f) {350, 0});
    ret[0].func = increase_damage;
    ret[1] = init_sprite("res/dmgup.png", 350, 200, (sfVector2f) {350, 0});
    ret[1].func = increase_damage;
    ret[2] = init_sprite("res/dmgup.png", 350, 200, (sfVector2f) {350, 0});
    ret[2].func = increase_damage;
    ret[3] = init_sprite("res/dpsup.png", 350, 200, (sfVector2f) {750, 0});
    ret[3].func = increase_attack_speed;
    ret[4] = init_sprite("res/dpsup.png", 350, 200, (sfVector2f) {750, 0});
    ret[4].func = increase_attack_speed;
    ret[5] = init_sprite("res/dpsup.png", 350, 200, (sfVector2f) {750, 0});
    ret[5].func = increase_attack_speed;
    return (ret);
}

gameobject_t *arr_4(void)
{
    gameobject_t *ret = malloc(sizeof(gameobject_t) * 6);

    ret[0] = init_sprite("res/goldup.png", 350, 200, (sfVector2f) {350, 0});
    ret[0].func = increase_gold;
    ret[1] = init_sprite("res/goldup.png", 350, 200, (sfVector2f) {350, 0});
    ret[1].func = increase_gold;
    ret[2] = init_sprite("res/goldup.png", 350, 200, (sfVector2f) {350, 0});
    ret[2].func = increase_gold;
    ret[3] = init_sprite("res/dpsup.png", 350, 200, (sfVector2f) {750, 0});
    ret[3].func = increase_attack_speed;
    ret[4] = init_sprite("res/dpsup.png", 350, 200, (sfVector2f) {750, 0});
    ret[4].func = increase_attack_speed;
    ret[5] = init_sprite("res/dpsup.png", 350, 200, (sfVector2f) {750, 0});
    ret[5].func = increase_attack_speed;
    return (ret);
}

gameobject_t *arr_5(void)
{
    gameobject_t *ret = malloc(sizeof(gameobject_t) * 6);

    ret[0] = init_sprite("res/slowup.png", 350, 200, (sfVector2f) {350, 0});
    ret[0].func = increase_slow;
    ret[1] = init_sprite("res/slowup.png", 350, 200, (sfVector2f) {350, 0});
    ret[1].func = increase_slow;
    ret[2] = init_sprite("res/slowup.png", 350, 200, (sfVector2f) {350, 0});
    ret[2].func = increase_slow;
    ret[3] = init_sprite("res/dpsup.png", 350, 200, (sfVector2f) {750, 0});
    ret[3].func = increase_attack_speed;
    ret[4] = init_sprite("res/dpsup.png", 350, 200, (sfVector2f) {750, 0});
    ret[4].func = increase_attack_speed;
    ret[5] = init_sprite("res/dpsup.png", 350, 200, (sfVector2f) {750, 0});
    ret[5].func = increase_attack_speed;
    return (ret);
}