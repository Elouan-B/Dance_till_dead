/*
** EPITECH PROJECT, 2025
** movement
** File description:
** vim-epitech made by x4m3
*/


#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <string.h>
#include "include/settings.h"
#include "include/structures.h"

void randomize_column(map_t map, int row)
{
    for (int i = 0; i < 7; i++) {
        map.tilemap[row][i] = rand_char();
    }
}

void randomize_row(map_t map, int column)
{
    for (int i = 0; i < 7; i++) {
        map.tilemap[i][column] = rand_char();
    }
}

void copy_row(map_t map, int des, int src)
{
    for (int i = 0; i < 7; i++) {
        map.tilemap[i][des] = map.tilemap[i][src];
    }
}

void move_left(map_t map)
{
    char temp_row[7];
    memcpy(temp_row, map.tilemap[6], 7);
    for (int i = 6; i > 0; i--) {
        memcpy(map.tilemap[i], map.tilemap[i - 1], 7);
    }
    randomize_column(map, 0);
}

void move_right(map_t map)
{
    char temp_row[7];

    memcpy(temp_row, map.tilemap[6], 7);
    for (int i = 0; i < 6; i++) {
        memcpy(map.tilemap[i], map.tilemap[i + 1], 7);
    }
    randomize_column(map, 6);
}

void move_down(map_t map)
{
    for (int i = 0; i < 6; i++){
        copy_row(map, i, i + 1);
    }
    randomize_row(map, 6);
}

void move_up(map_t map)
{
    for (int i = 6; i > 0; i--){
        copy_row(map, i, i - 1);
    }
    randomize_row(map, 0);
}
