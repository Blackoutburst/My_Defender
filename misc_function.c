/*
** EPITECH PROJECT, 2019
** window.c
** File description:
** init and update window
*/

#include "include/function.h"

float float_rand(float min, float max)
{
    float scale = rand() / (float) RAND_MAX;
    return (min + scale * (max - min));
}

void move_rect(sfIntRect *rect, int offset, int reset, int max_value)
{
    if (rect->left + offset < max_value)
        rect->left += offset;
    else
        rect->left = reset;
}

void draw(gameobject_t object, sfRenderWindow *window)
{
    if (!object.init)
        return;
    sfSprite_setScale(object.sprite, object.scale);
    sfSprite_setPosition(object.sprite, object.pos);
    sfSprite_setTexture(object.sprite, object.texture, sfTrue);
    sfSprite_setTextureRect(object.sprite, object.rect);
    sfRenderWindow_drawSprite(window, object.sprite, NULL);
}

void draw_text(text_info_t texte, sfRenderWindow *window)
{
    sfText_setCharacterSize(texte.text, texte.size);
    sfText_setString(texte.text, texte.data);
    sfText_setFont(texte.text, texte.font);
    sfText_setColor (texte.text, texte.color);
    sfText_setPosition (texte.text, texte.pos);
    sfRenderWindow_drawText(window, texte.text, NULL);
}

sfSound *create_sound(char *path)
{
    sfSound *sound = sfSound_create();
    sfSoundBuffer *soundbuffer = sfSoundBuffer_createFromFile(path);

    sfSound_setBuffer(sound, soundbuffer);
    return (sound);
}