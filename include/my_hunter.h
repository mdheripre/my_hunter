/*
** EPITECH PROJECT, 2023
** MY_HUNTER.H
** File description:
** header file for my_hunter game
*/

#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <SFML/Audio.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef MY_HUNTER
    #define MY_HUNTER

typedef struct mob {
    sfClock *clock;
    sfTime time;
    float seconds;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
} mob_t;

typedef struct gtime {
    sfClock *clock;
    sfTime time;
    float seconds;
    float spd;
} gtime_t;

typedef struct hps {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
} hps_t;

typedef struct spw {
    int hp;
    int score;
    sfText *score_field;
    hps_t hps;
    gtime_t gtime;
    sfClock *clock;
    sfTime time;
    float seconds;
    int i;
    mob_t *mob;
    sfSound *sound;
    sfSoundBuffer *sound_buff;
} spw_t;

typedef struct mage {
    sfClock *clock;
    sfTime time;
    float seconds;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos_mage;
    sfIntRect rect;
} mage_t;

typedef struct pause {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
} pause_t;

typedef struct go {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
} go_t;

typedef struct start {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
} start_t;

typedef struct gamevar {
    bool strt;
    bool pauseq;
    sfMusic *music;
    start_t start;
    pause_t pause;
    go_t go;
    mage_t mage;
    spw_t spw;
    sfRenderWindow *window;
    sfEvent event;
    sfTexture *texture;
    sfSprite *spr_bg;
    sfTexture *text_cur;
    sfSprite *cursor_spr;
    sfIntRect rect;
} gamevar_t;

gamevar_t play_game(gamevar_t game);

sfRenderWindow *create_window(void);

gamevar_t draw_window(gamevar_t game);

pause_t create_pause(pause_t pause);

go_t create_go(go_t go);

start_t create_start(start_t start);

hps_t create_hp(hps_t hps);

spw_t create_spw(spw_t spw);

mage_t create_mage(mage_t mage);

gamevar_t create_game(gamevar_t game);

gamevar_t recreate_game(gamevar_t game);

void destroy_all_mob(spw_t spw);

void cursor(gamevar_t game);

mob_t create_mob(mob_t mob);

gamevar_t spawn_mob(gamevar_t game);

spw_t destroy_mob(spw_t spw, int i);

gamevar_t mage(gamevar_t game);

void rect_speed(sfClock *clock, sfIntRect *rect);

void move_rect(sfIntRect *rect, int offset, int max_value);

void move_rect_bird(sfIntRect *rect, int offset, int max_value);

#endif /* MY_HUNTER */
