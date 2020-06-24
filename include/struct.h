/*
** EPITECH PROJECT, 2020
** My Runner
** File description:
** All function prototype
*/

#include "include.h"

typedef struct text_info {
    sfText *text;
    sfFont *font;
    int size;
    char *data;
    sfColor color;
    sfVector2f pos;
} text_info_t;

typedef struct tower_stat {
    int range;
    int cost;
    int dmg;
    float AS;
} tower_stat_t;

typedef struct gameobject {
    sfSprite *sprite;
    sfTexture *texture;
    sfTexture *texture110;
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f scale;
    sfColor color;
    int solid;
    float rotation;
    char *name;
    char *info;
    text_info_t txt;
    int init;
    int hp;
    sfClock *clock;
    sfTime time;
    float seconde;
    int lupdate;
    int rupdate;
    int max;
    int armored;
    struct gameobject *arr;
    sfSound *sound;
    void (*func)(void *, int);
    tower_stat_t stat;
} gameobject_t;

typedef struct player_info {
    int gold;
    int hp;
    int xp;
} player_info_t;

typedef struct map {
    int tiles_number;
    gameobject_t *tile;
    gameobject_t map_render;
    int x;
    int pos;
} map_t;

typedef struct round_info {
    int ID;
    sfClock *clock;
    sfTime time;
    float seconde;
    FILE *fd;
    int spawn;
    gameobject_t (*func)(map_t);
} round_info_t;

typedef struct menu {
    sfSoundBuffer *soundBuffer;
    sfSound *song;
    gameobject_t background;
    gameobject_t play_but;
    gameobject_t option_but;
    gameobject_t exit_but;
    gameobject_t sound_but;
    gameobject_t title;
} menu_t;

typedef struct HUD {
    gameobject_t p_t;
    gameobject_t p_top;
    gameobject_t p_upgr;
    gameobject_t sell_button;
    gameobject_t up_but_l;
    gameobject_t up_but_r;
} HUD_t;

typedef struct HTP {
    gameobject_t htp0;
    gameobject_t htp1;
    gameobject_t htp2;
    gameobject_t htp3;
    int down;
} HTP_t;

typedef struct global {
    sfRenderWindow *window;
    gameobject_t *tower;
    gameobject_t *ennemi;
    gameobject_t *bullet;
    map_t map;
    menu_t mainmenu;
    menu_t pausemenu;
    menu_t gameover;
    menu_t victory;
    player_info_t player;
    gameobject_t selec;
    HUD_t hud;
    round_info_t round;
    gameobject_t pause_button;
    gameobject_t next_button;
    HTP_t htp;
    int muted;
} global_t;
