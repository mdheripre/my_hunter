/*
** EPITECH PROJECT, 2023
** BIRD
** File description:
** functions to make a bird fly accros the window
*/

#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/my_hunter.h"
#include <stdbool.h>


void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left == max_value) {
        rect->left = 0;
    }
}

void move_rect_bird(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left == max_value) {
        rect->left = 388;
    }
}

void rect_speed(sfClock *clock, sfIntRect *rect)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.2) {
        move_rect(rect, 110, 330);
        sfClock_restart(clock);
    }
}
