/*
** EPITECH PROJECT, 2023
** DRAW_WINDOW
** File description:
** function to display the window of the game
*/

#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <SFML/Window.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/my_hunter.h"

void cursor(gamevar_t game)
{
    sfVector2f spr_pos;
    int x = 15;
    int y = 15;

    spr_pos.x = sfMouse_getPositionRenderWindow(game.window).x - x;
    spr_pos.y = sfMouse_getPositionRenderWindow(game.window).y - y;
    sfSprite_setPosition(game.cursor_spr, spr_pos);
    sfRenderWindow_drawSprite(game.window, game.cursor_spr, NULL);
}
