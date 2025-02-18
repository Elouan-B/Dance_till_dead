/*
** EPITECH PROJECT, 2025
** /home/elouan/projet_perso/Dtd/include/structures
** File description:
** hey. real programmers use vim
*/

#include "SFML/Graphics.h"

#ifndef STRUCT_H
    #define STRUCT_H
typedef struct tileset {
    sfSprite *tile1;
    sfSprite *tile2;
}tileset_t;

typedef struct map_object {
    char **tilemap;
    char **entitymap;
}map_t;

typedef struct game_state {
    sfClock *animation_clock;
    sfClock *timing_clock;
    int hp;
}game_state_t;
#endif /* ifndef STRUCT_H */
