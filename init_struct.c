/*
** EPITECH PROJECT, 2019
** window.c
** File description:
** init and update window
*/

#include "include/function.h"

gameobject_t model[6];

typedef void (*func)(void *, int);
const func tabl_shoot[3] =
{
    &shoot_straight,
    &shoot_money,
    &shoot_slow_aoe
};

void init(void)
{
    init_tower_model(&model[1], "tower/tower_1.dat", 1);
    init_tower_model(&model[2], "tower/tower_2.dat", 2);
    init_tower_model(&model[3], "tower/tower_3.dat", 3);
    init_tower_model(&model[4], "tower/tower_4.dat", 4);
    init_tower_model(&model[5], "tower/tower_5.dat", 5);
}

void init_tower_model(gameobject_t *obj, char *path, int index)
{
    char *buffer = read_map(path);
    char **arr = my_str_to_word_array(buffer);
    char *new_path = path + 6;

    obj->sprite = sfSprite_create();
    obj->texture = sfTexture_createFromFile(arr[0], NULL);
    obj->texture110 = sfTexture_createFromFile(my_strcat(arr[0], "M"), NULL);
    obj->rect = (sfIntRect) {0, 0, my_atoi(arr[1]), my_atoi(arr[1])};
    obj->scale = (v2f) {my_atoi(arr[2]), my_atoi(arr[2])};
    obj->name = arr[3];
    obj->info = read_map(my_strcat("tower/info_", new_path));
    obj->init = my_atoi(arr[4]);
    obj->stat.range = my_atoi(arr[5]);
    obj->stat.cost = my_atoi(arr[6]);
    obj->stat.dmg = my_atoi(arr[7]);
    obj->stat.AS = my_atoi(arr[8]) / 100.0;
    obj->arr = init_arr(index);
    obj->func = tabl_shoot[my_atoi(arr[9])];
    obj->armored = my_atoi(arr[10]);
    obj->sound = create_sound(my_strcat("res/", arr[11]));
}

text_info_t init_text_info(int size, sfVector2f pos)
{
    text_info_t ret;

    ret.text = sfText_create();
    ret.font = sfFont_createFromFile("res/font.ttf");
    ret.size = size;
    ret.data = malloc(sizeof(char) * 1024);
    my_memset(ret.data, 0, 1024);
    ret.color = sfWhite;
    ret.pos = pos;
    return (ret);
}

gameobject_t init_sprite(char *path, int width, int height, sfVector2f pos)
{
    gameobject_t ret;

    ret.sprite = sfSprite_create();
    ret.texture = sfTexture_createFromFile(path, NULL);
    ret.rect = (sfIntRect) {0, 0, width, height};
    ret.pos = pos;
    ret.scale = (v2f) {1, 1};
    ret.rotation = 0;
    ret.name = path;
    ret.init = 1;
    ret.solid = 0;
    return (ret);
}
