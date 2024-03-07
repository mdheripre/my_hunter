/*
** EPITECH PROJECT, 2023
** MAGE
** File description:
** function to animate the mage of my_hunter
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

gamevar_t mage(gamevar_t game)
{
    sfSprite_setPosition(game.mage.sprite, game.mage.pos_mage);
    sfRenderWindow_drawSprite(game.window, game.mage.sprite, NULL);
    return game;
}
