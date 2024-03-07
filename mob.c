/*
** EPITECH PROJECT, 2023
** DRAW_WINDOW
** File description:
** function to display the window of the game
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
#include "include/my_hunter.h"

spw_t destroy_mob(spw_t spw, int i)
{
    spw.score++;
    spw.i--;
    while (i < spw.i) {
        spw.mob[i].pos.x = spw.mob[i + 1].pos.x;
        spw.mob[i].pos.y = spw.mob[i + 1].pos.y;
        spw.mob[i].rect.left = spw.mob[i + 1].rect.left;
        i++;
    }
    sfClock_destroy(spw.mob[spw.i].clock);
    sfSprite_destroy(spw.mob[spw.i].sprite);
    sfTexture_destroy(spw.mob[spw.i].texture);
    return spw;
}

spw_t mob_display(spw_t spw, int i)
{
    spw.mob[i].time = sfClock_getElapsedTime(spw.mob[i].clock);
    spw.mob[i].seconds = spw.mob[i].time.microseconds / 1000000.0;
    if (spw.mob[i].seconds > 0.01 - spw.gtime.spd) {
        spw.mob[i].pos.x += -(3 + (spw.gtime.spd * 100));
    }
    if (spw.mob[i].seconds > 0.2 - spw.gtime.spd) {
        move_rect_bird(&spw.mob[i].rect, 97, 776);
        sfClock_restart(spw.mob[i].clock);
    }
    sfSprite_setPosition(spw.mob[i].sprite, spw.mob[i].pos);
    if (spw.mob[i].pos.x < -97) {
        spw = destroy_mob(spw, i);
        move_rect(&spw.hps.rect, 50, 330);
        sfSprite_setTextureRect(spw.hps.sprite, spw.hps.rect);
        spw.hp--;
    }
    sfSprite_setTextureRect(spw.mob[i].sprite, spw.mob[i].rect);
    return spw;
}

gamevar_t spawn_mob(gamevar_t game)
{
    game.spw.time = sfClock_getElapsedTime(game.spw.clock);
    game.spw.seconds = game.spw.time.microseconds / 1000000.0;
    if (game.spw.seconds > (1.0 - game.spw.gtime.spd)) {
        game.spw.mob[game.spw.i] = create_mob(game.spw.mob[game.spw.i]);
        game.spw.i++;
        sfClock_restart(game.spw.clock);
    }
    for (int i = 0; i < game.spw.i; i++) {
        game.spw = mob_display(game.spw, i);
        sfRenderWindow_drawSprite(game.window, game.spw.mob[i].sprite, NULL);
    }
    return game;
}
