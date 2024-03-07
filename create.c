/*
** EPITECH PROJECT, 2023
** CREATE
** File description:
** function to create things for the game
*/

#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/my_hunter.h"

mob_t create_mob(mob_t mob)
{
    srand(time(NULL));
    mob.clock = sfClock_create();
    mob.seconds = 0;
    mob.rect.top = 0;
    mob.rect.left = 388;
    mob.rect.height = 120;
    mob.rect.width = 97;
    mob.pos.x = 1800;
    mob.pos.y = 150 + (rand() % 580);
    mob.sprite = sfSprite_create();
    mob.texture = sfTexture_createFromFile("ressources/bird_sheet.png",
        NULL);
    sfSprite_setTexture(mob.sprite, mob.texture, sfTrue);
    sfSprite_setTextureRect(mob.sprite, mob.rect);
    return mob;
}

mage_t create_mage(mage_t mage)
{
    mage.clock = sfClock_create();
    mage.seconds = 0;
    mage.rect.top = 0;
    mage.rect.left = 0;
    mage.rect.height = 128;
    mage.rect.width = 128;
    mage.pos_mage.x = 100;
    mage.pos_mage.y = 500;
    mage.sprite = sfSprite_create();
    mage.texture = sfTexture_createFromFile("ressources/mage.png",
        NULL);
    sfSprite_setTexture(mage.sprite, mage.texture, sfTrue);
    sfSprite_setTextureRect(mage.sprite, mage.rect);
    return mage;
}

gtime_t create_spd(gtime_t gtime)
{
    gtime.clock = sfClock_create();
    gtime.spd = 0;
    return gtime;
}

spw_t create_spw(spw_t spw)
{
    spw.hp = 3;
    spw.score = 0;
    spw.score_field = sfText_create();
    spw.sound = sfSound_create();
    spw.sound_buff = sfSoundBuffer_createFromFile("ressources/kill.ogg");
    sfSound_setBuffer(spw.sound, spw.sound_buff);
    spw.clock = sfClock_create();
    spw.gtime = create_spd(spw.gtime);
    spw.mob = malloc(sizeof(mob_t) * 100);
    spw.i = 0;
    spw.hps = create_hp(spw.hps);
    return spw;
}

gamevar_t create_game(gamevar_t game)
{
    game.strt = false;
    game.pauseq = false;
    game.music = sfMusic_createFromFile("ressources/music.ogg");
    game.start = create_start(game.start);
    game.pause = create_pause(game.pause);
    game.go = create_go(game.go);
    game.spw = create_spw(game.spw);
    game.window = create_window();
    game.texture = sfTexture_createFromFile("ressources/background.png",
        NULL);
    game.text_cur = sfTexture_createFromFile("ressources/cursor.png", NULL);
    game.spr_bg = sfSprite_create();
    game.cursor_spr = sfSprite_create();
    game.mage = create_mage(game.mage);
    sfSprite_setTexture(game.spr_bg, game.texture, sfTrue);
    sfSprite_setTexture(game.cursor_spr, game.text_cur, sfTrue);
    return game;
}
