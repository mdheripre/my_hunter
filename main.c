/*
** EPITECH PROJECT, 2023
** MAIN
** File description:
** main function for bs_my_hunter
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
#include <fcntl.h>
#include "include/my_hunter.h"

void destroy_all_mob(spw_t spw)
{
    while (spw.i >= 0) {
        if (spw.score == 0 && spw.hp != 3) {
        sfClock_destroy(spw.mob[spw.i].clock);
        sfSprite_destroy(spw.mob[spw.i].sprite);
        sfTexture_destroy(spw.mob[spw.i].texture);
        }
        spw.i--;
    }
}

static void destroy_all_2(gamevar_t game)
{
    sfClock_destroy(game.spw.clock);
    sfClock_destroy(game.mage.clock);
    sfClock_destroy(game.spw.gtime.clock);
    sfTexture_destroy(game.mage.texture);
    sfSprite_destroy(game.mage.sprite);
    sfTexture_destroy(game.texture);
    sfSprite_destroy(game.spr_bg);
    sfTexture_destroy(game.text_cur);
    sfSprite_destroy(game.cursor_spr);
    sfTexture_destroy(game.pause.texture);
    sfText_destroy(game.spw.score_field);
}

static void destroy_all_1(gamevar_t game)
{
    destroy_all_2(game);
    sfSprite_destroy(game.pause.sprite);
    sfTexture_destroy(game.go.texture);
    sfSprite_destroy(game.go.sprite);
    sfTexture_destroy(game.start.texture);
    sfSprite_destroy(game.start.sprite);
    sfTexture_destroy(game.spw.hps.texture);
    sfSprite_destroy(game.spw.hps.sprite);
    sfMusic_destroy(game.music);
    sfSound_destroy(game.spw.sound);
    sfSoundBuffer_destroy(game.spw.sound_buff);
    destroy_all_mob(game.spw);
    free(game.spw.mob);
    sfRenderWindow_destroy(game.window);
}

static void display_description(void)
{
    write(1, "Welcome to my game !\n", 22);
    write(1, "Type ./my_hunter in your terminal to start the game.\n", 54);
    write(1, "you are a mage who has to shoot monsters, ", 43);
    write(1, "if a monster makes it off the screen you lose 1 hp", 51);
    write(1, ", after losing 3 hps you lose the game.\n", 41);
    write(1, "The longer you survive, faster the monsters will spawn. ", 57);
    write(1, "To shoot a monster, just click on it with your mouse.\n\n", 56);
    write(1, "You can exit the game by pressing ESC, ", 40);
    write(1, "or by closing the game window.\n", 32);
    write(1, "You can pause the game by pressing Q.\n", 39);
    write(1, "You can restart the game by pressing R.\n", 41);
    write(1, "Good luck have fun !\n", 22);
}

static bool check_assets_2(void)
{
    if (open("ressources/q.png", O_RDONLY) == -1) {
        return false;
    }
    if (open("ressources/strt.png", O_RDONLY) == -1) {
        return false;
    }
    return true;
}

static bool check_assets_1(void)
{
    if (open("ressources/hp.png", O_RDONLY) == -1) {
        return false;
    }
    if (open("ressources/kill.ogg", O_RDONLY) == -1) {
        return false;
    }
    if (open("ressources/music.ogg", O_RDONLY) == -1) {
        return false;
    }
    if (open("ressources/mage.png", O_RDONLY) == -1) {
        return false;
    }
    if (open("ressources/pause.png", O_RDONLY) == -1) {
        return false;
    }
    if (check_assets_2() == false) {
        return false;
    }
    return true;
}

static bool check_assets(void)
{
    if (open("ressources/background.png", O_RDONLY) == -1) {
        return false;
    }
    if (open("ressources/bird_sheet.png", O_RDONLY) == -1) {
        return false;
    }
    if (open("ressources/cursor.png", O_RDONLY) == -1) {
        return false;
    }
    if (open("ressources/game_icon.png", O_RDONLY) == -1) {
        return false;
    }
    if (open("ressources/go.png", O_RDONLY) == -1) {
        return false;
    }
    if (check_assets_1() == false) {
        return false;
    }
    return true;
}

int main(int ac, char **av)
{
    gamevar_t game;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        display_description();
        return 0;
    }
    if (ac != 1) {
        write(2, "./my_hunter -h\n", 16);
        return 84;
    }
    if (check_assets() == false) {
        return 84;
    }
    game = create_game(game);
    game = play_game(game);
    destroy_all_1(game);
    return 0;
}
