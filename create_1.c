/*
** EPITECH PROJECT, 2023
** CREATE
** File description:
** function to create things for the game
*/

#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <SFML/Window.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/my_hunter.h"

sfRenderWindow *create_window(void)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {1700, 956, 32};

    window = sfRenderWindow_create(video_mode,
        "GOTY 2023",
        sfClose,
        NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setIcon(window, 100, 100,
        sfImage_getPixelsPtr(
            sfImage_createFromFile("ressources/game_icon.png")));
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    return window;
}

pause_t create_pause(pause_t pause)
{
    pause.pos.x = 850 - 741 / 2;
    pause.pos.y = 476 - 181 / 2;
    pause.sprite = sfSprite_create();
    pause.texture = sfTexture_createFromFile("ressources/pause.png",
        NULL);
    sfSprite_setTexture(pause.sprite, pause.texture, sfTrue);
    sfSprite_setPosition(pause.sprite, pause.pos);
    return pause;
}

go_t create_go(go_t go)
{
    go.pos.x = 850 - 422 / 2;
    go.pos.y = 476 - 182 / 2;
    go.sprite = sfSprite_create();
    go.texture = sfTexture_createFromFile("ressources/go.png",
        NULL);
    sfSprite_setTexture(go.sprite, go.texture, sfTrue);
    sfSprite_setPosition(go.sprite, go.pos);
    return go;
}

start_t create_start(start_t start)
{
    start.pos.x = 850 - 741 / 2;
    start.pos.y = 476 - 741 / 2;
    start.sprite = sfSprite_create();
    start.texture = sfTexture_createFromFile("ressources/strt.png",
        NULL);
    sfSprite_setTexture(start.sprite, start.texture, sfTrue);
    sfSprite_setPosition(start.sprite, start.pos);
    return start;
}

gamevar_t recreate_game(gamevar_t game)
{
    game.pauseq = false;
    sfMusic_play(game.music);
    sfClock_destroy(game.spw.clock);
    sfClock_destroy(game.spw.gtime.clock);
    sfTexture_destroy(game.spw.hps.texture);
    sfSprite_destroy(game.spw.hps.sprite);
    sfSoundBuffer_destroy(game.spw.sound_buff);
    sfSound_destroy(game.spw.sound);
    sfText_destroy(game.spw.score_field);
    destroy_all_mob(game.spw);
    free(game.spw.mob);
    game.spw = create_spw(game.spw);
    return game;
}
