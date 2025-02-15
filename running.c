/*
** EPITECH PROJECT, 2024
** main
** File description:
** epitech > epita
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <time.h>
#include <stdlib.h>
#include "include/settings.h"
#include "include/structures.h"

void event_poll(sfRenderWindow **window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(*window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(*window);
    }
}

char **generate_map(void)
{
    char **map_array = malloc(sizeof(char *) * 7);

    srandom(time(NULL));
    for (int i = 0; i < 7; i++) {
        map_array[i] = malloc(sizeof(char) * 7);
        for (int y = 0; y < 7; y++) {
            if (random() % 2)
                map_array[i][y] = '.';
            else
                map_array[i][y] = 'o';
        }
    }
    return (map_array);
}

int running(map_t map, tileset_t *tileset)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "Dance_till_dead", sfResize | sfClose, 0);


    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfColor_fromRGB(5, 2, 79));
        event_poll(&window);
        draw_grid(&window, tileset, map);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    return 0;
}

int innit(void)
{
    char **tiles_map = generate_map();
    char **entity_map = NULL;
    sfSprite *tile = sfSprite_create();
    sfTexture *tile_text = sfTexture_createFromFile("sprites/tile.png", 0);
    sfSprite *tile2 = sfSprite_create();
    sfTexture *tile_text2 = sfTexture_createFromFile("sprites/tile2.png", 0);
    tileset_t *tileset = malloc(sizeof(tileset_t *));
    map_t map = {tiles_map, NULL};


    sfSprite_setTexture(tile, tile_text, 1);
    sfSprite_setScale(tile, (sfVector2f) {SCALE, SCALE});
    sfSprite_setTexture(tile2, tile_text2, 1);
    sfSprite_setScale(tile2, (sfVector2f) {SCALE, SCALE});
    tileset->tile1 = tile;
    tileset->tile2 = tile2;
    return (running(map, tileset));
}
