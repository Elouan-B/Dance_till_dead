/*
** EPITECH PROJECT, 2024
** /home/elouan/Graphical/animation_function
** File description:
** don't forget to free at the end
*/

#include <SFML/Graphics.h>

void parse(sfSprite *sprite, int length, int size)
{
    sfIntRect rect = sfSprite_getTextureRect(sprite);

    rect.left = rect.left + size;
    if (rect.left >= length * size)
        rect.left = 0;
    sfSprite_setTextureRect(sprite, rect);
}

void animate(sfSprite *sprite, int length, int size, sfClock *clock)
{
    sfTime time;
    float seconds;

    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.5) {
        parse(sprite, length, size);
        sfSprite_setColor(sprite, sfWhite);
        sfClock_restart(clock);
    }
}
