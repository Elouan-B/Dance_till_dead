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
    #define HP 3
int innit(void);
void draw_grid(sfRenderWindow **window, tileset_t *tileset, map_t map);
char rand_char(void);
void randomize_row(map_t map, int row);
void randomize_column(map_t map, int column);
void move_right(map_t map);
char rand_char(void);
void move_left(map_t map);
void move_down(map_t map);
void move_up(map_t map);
int running(map_t map, tileset_t *tileset, sfSprite *player, game_state_t *gs);
char **generate_map(void);
#endif /* ifndef GUH_H
 */
