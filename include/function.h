/*
** EPITECH PROJECT, 2020
** My Runner
** File description:
** All function prototype
*/

#include "my.h"
#include "global.h"
#include "include.h"

void init(void);
map_t init_game(void);
player_info_t init_player(void);
HUD_t init_hud(void);
round_info_t init_round(void);
global_t *init_global(void);
gameobject_t *init_arr(int);
gameobject_t *init_list_gameobject(void);

//////// Misc Function ////////

float float_rand(float, float);
void move_rect(sfIntRect *, int, int, int);
void draw(gameobject_t, sfRenderWindow *);
void draw_text(text_info_t, sfRenderWindow *);
sfSound *create_sound(char *);

////////  Map Loader ////////

gameobject_t *generate_map(char *, int);
map_t fill_arg(char **, char, map_t);
void fill_map(gameobject_t *, int, char **);
sfIntRect choose_texture(int);

//////// Update ////////

void update(sfRenderWindow *, sfEvent);
void poll_event(sfRenderWindow *, sfEvent);

//////// Reader ////////

char *read_map(char *);
int count_lines(char *);

//////// Init Struct ////////

text_info_t init_text_info(int, sfVector2f);
gameobject_t init_sprite(char *, int, int, sfVector2f);

//////// HUD //////////

void top_panel(global_t *);
void upgr_panel(global_t *);
void tower_panel(global_t *);
void draw_hud(global_t *);

//////// Info tower ////////

void info_tower_panel(global_t *);

//////// Turret placement //////////

void place_tower(global_t *);
void render_preview(global_t *);

//////// Gestion input /////////

int isclick(sfVector2f, sfVector2f, sfRenderWindow *);

//////// Ennemi /////////

void update_ennemi(global_t *);
void draw_ennemi(global_t *);
gameobject_t choose_ennemi_direction(gameobject_t, map_t);
gameobject_t choose_ennemi_direction_2(gameobject_t, map_t);

//////// Tower /////////

void update_tower(global_t *);

//////// Main Menu /////////

int update_mainmenu(global_t *, int);
menu_t init_mainmenu(void);

//////// Button /////////

int update_button(gameobject_t, sfRenderWindow *, int, int);
int hover_button(gameobject_t, sfRenderWindow *);

//////// Song /////////

void run_song(sfSound *song, global_t *g);
void pause_song(sfSound *);
void stop_song(sfSound *);
void loop_song(sfSound *);

//////// Math ////////

float square(float);
float pythagore(float, float);
void draw_line(sfRenderWindow *, sfVector2f, sfVector2f);

//////// Init Ennemi ////////

gameobject_t init_ennemi_0(map_t);
gameobject_t init_ennemi_1(map_t);
gameobject_t init_ennemi_2(map_t);
gameobject_t init_ennemi_3(map_t);

//////// Round ////////

void update_round(global_t *);

//////// Pause ////////

int update_pause_button(global_t *, int);
int update_pausemenu(global_t *, int);
menu_t init_pausemenu(void);

//////// Shoot ////////

void shoot_straight(void *, int);
void shoot_money(void *, int);
void shoot_slow_aoe(void *, int);

//////// Game Over ////////

int update_gameover(global_t *, int);
menu_t init_gameover(void);

//////// Victory ////////

int update_victory(global_t *, int);
menu_t init_victory(void);

//////// Scene ////////

int scene_1(global_t *);
int scene_2(global_t *);
int scene_3(global_t *);
int scene_4(global_t *);
int scene_5(global_t *);
int scene_6(global_t *);
int scene_7(global_t *);
int scene_8(global_t *);
int scene_9(global_t *);

//////// Skill Tree ////////

void update_visual_upgrade_buttons(global_t *);
void update_upgrade_buttons(global_t *);
int upgrade_buttons_event(global_t *, int, int);

//////// Skill Tree Func /////////

void increase_damage(void *, int);
void increase_range(void *, int);
void increase_attack_speed(void *, int);
void hit_armored_ennemi(void *, int);
void increase_slow(void *, int);
void increase_gold(void *, int);

//////// How To Play /////////

HTP_t init_htp(void);

//////// Upgrade Array ////////

gameobject_t *arr_1(void);
gameobject_t *arr_2(void);
gameobject_t *arr_3(void);
gameobject_t *arr_4(void);
gameobject_t *arr_5(void);
