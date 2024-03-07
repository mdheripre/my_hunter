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

static spw_t get_xy(sfMouseButtonEvent ev, spw_t spw, int i)
{
    if (ev.x >= spw.mob[i].pos.x && ev.x <= spw.mob[i].pos.x + 110) {
        if (ev.y >= spw.mob[i].pos.y && ev.y <= spw.mob[i].pos.y + 110) {
            spw = destroy_mob(spw, i);
            sfSound_play(spw.sound);
        }
    }
    return spw;
}

static spw_t kill_confirm(sfMouseButtonEvent ev, spw_t spw)
{
    for (int i = 0; i < spw.i; i++) {
        spw = get_xy(ev, spw, i);
    }
    return spw;
}

static mage_t anim_shot(mage_t mage)
{
    mage.time = sfClock_getElapsedTime(mage.clock);
    mage.seconds = mage.time.microseconds / 1000000.0;
    for (int i = 0; i < 7; i++) {
        if (mage.seconds > 0.1) {
            move_rect(&mage.rect, 128, 896);
            sfClock_restart(mage.clock);
        }
    }
    sfSprite_setTextureRect(mage.sprite, mage.rect);
    return mage;
}

static gamevar_t analyse_events(gamevar_t game)
{
    if (game.event.type == sfEvtClosed) {
        sfRenderWindow_close(game.window);
    }
    if (game.event.mouseButton.type == sfEvtMouseButtonPressed) {
        if (game.pauseq == false) {
            game.mage = anim_shot(game.mage);
            game.spw = kill_confirm(game.event.mouseButton, game.spw);
            game.strt = true;
        }
    }
    return game;
}

gamevar_t draw_window(gamevar_t game)
{
    sfRenderWindow_display(game.window);
    sfRenderWindow_clear(game.window, sfBlack);
    sfRenderWindow_drawSprite(game.window, game.spr_bg, NULL);
    sfRenderWindow_drawSprite(game.window, game.spw.hps.sprite, NULL);
    sfRenderWindow_drawText(game.window, game.spw.score_field, NULL);
    game = mage(game);
    while (sfRenderWindow_pollEvent(game.window, &game.event)) {
        game = analyse_events(game);
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ) && game.strt == true) {
        game.pauseq = !game.pauseq;
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        sfRenderWindow_close(game.window);
    }
    if (sfKeyboard_isKeyPressed(sfKeyR) && game.strt == true) {
        game = recreate_game(game);
    }
    return game;
}
