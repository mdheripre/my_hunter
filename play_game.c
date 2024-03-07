/*
** EPITECH PROJECT, 2023
** PLAY_GAME
** File description:
** functions to play the game
*/

#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <SFML/Window.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "include/my_hunter.h"

static gtime_t spd(gtime_t gtime)
{
    gtime.time = sfClock_getElapsedTime(gtime.clock);
    gtime.seconds = gtime.time.microseconds / 1000000.0;
    if (gtime.seconds > 10.0) {
        gtime.spd += 0.01;
        sfClock_restart(gtime.clock);
    }
    return gtime;
}

static gamevar_t pause_loop(gamevar_t game)
{
    sfRenderWindow_drawSprite(game.window, game.pause.sprite, NULL);
    game = draw_window(game);
    sfMusic_setVolume(game.music, 20.0);
    return game;
}

static gamevar_t go_loop(gamevar_t game)
{
    sfRenderWindow_drawSprite(game.window, game.go.sprite, NULL);
    game = draw_window(game);
    sfMusic_setVolume(game.music, 20.0);
    return game;
}

static gamevar_t start_loop(gamevar_t game)
{
    sfRenderWindow_drawSprite(game.window, game.start.sprite, NULL);
    game = draw_window(game);
    sfMusic_play(game.music);
    return game;
}

gamevar_t play_game(gamevar_t game)
{
    while (sfRenderWindow_isOpen(game.window)) {
        while (game.strt == false && sfRenderWindow_isOpen(game.window)) {
            game = start_loop(game);
        }
        game.spw.gtime = spd(game.spw.gtime);
        game = draw_window(game);
        game = spawn_mob(game);
        cursor(game);
        while (game.pauseq == true && sfRenderWindow_isOpen(game.window)) {
            game = pause_loop(game);
        }
        sfMusic_setVolume(game.music, 100.0);
        while (game.spw.hp == 0 && sfRenderWindow_isOpen(game.window)) {
            game = go_loop(game);
        }
    }
    return game;
}
