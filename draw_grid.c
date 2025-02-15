/*
** EPITECH PROJECT, 2025
** /home/elouan/projet_perso/Dtd/draw_grid
** File description:
** 01100010 01101001 01101110 01100001 01110010 01111001
*/

#include "include/structures.h"
#include "include/settings.h"
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>


static void draw_tiles(sfRenderWindow **window, tileset_t *tileset, map_t map, sfVector2f p)
{
    int i = p.x;
    int y = p.y;

    if (map.tilemap[i][y] == 'o') {
            sfSprite_setPosition(tileset->tile1, (sfVector2f) {TILE_SIZE * i + OFFSET, TILE_SIZE * y + 46});
            sfRenderWindow_drawSprite(*window, tileset->tile1, 0);
    } else {
            sfSprite_setPosition(tileset->tile2, (sfVector2f) {TILE_SIZE * i + OFFSET, TILE_SIZE * y + 46});
            sfRenderWindow_drawSprite(*window, tileset->tile2, 0);
    }
}

void draw_grid(sfRenderWindow **window, tileset_t *tileset, map_t map)
{
    sfVector2f p = {0, 0};

    for (int i = 0; i < 7; i++) {
        for (int y = 0; y < 7; y++) {
            p = (sfVector2f) {i, y};
            draw_tiles(window, tileset, map, p);
        }
    }
}

