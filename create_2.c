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

hps_t create_hp(hps_t hps)
{
    hps.rect.top = 0;
    hps.rect.left = 0;
    hps.rect.height = 48;
    hps.rect.width = 150;
    hps.pos.x = 850 - 150 / 2;
    hps.pos.y = 0;
    hps.sprite = sfSprite_create();
    hps.texture = sfTexture_createFromFile("ressources/hp.png",
        NULL);
    sfSprite_setTexture(hps.sprite, hps.texture, sfTrue);
    sfSprite_setTextureRect(hps.sprite, hps.rect);
    sfSprite_setPosition(hps.sprite, hps.pos);
    return hps;
}
