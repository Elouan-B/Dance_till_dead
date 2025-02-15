/*
** EPITECH PROJECT, 2025
** /home/elouan/projet_perso/Dance_till_dead/include/settings
** File description:
** csfml is the best thing ever
*/

#include "structures.h"

#ifndef GUH_H
    #define GUH_H
    #define WIDTH 800
    #define HEIGHT 600
    #define OFFSET ((WIDTH - HEIGHT) / 2) + 57
    #define SPRITE_SIZE 16
    #define SCALE 4
    #define TILE_SIZE (SPRITE_SIZE * SCALE)
int innit(void);
void draw_grid(sfRenderWindow **window, tileset_t *tileset, map_t map);
#endif /* ifndef GUH_H
 */
