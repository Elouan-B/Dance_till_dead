/*
** EPITECH PROJECT, 2024
** main
** File description:
** epitech > epita
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System.h>
#include <SFML/System/Vector2.h>
#include <time.h>
#include <stdlib.h>
#include "include/settings.h"
#include "include/structures.h"

void event_poll(sfRenderWindow **window, map_t map, sfSprite **player)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(*window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(*window);
        if (event.type == sfEvtKeyPressed) {
            if (event.key.code == sfKeyRight || event.key.code == sfKeyD) {
                move_right(map);
                sfSprite_setScale(*player, (sfVector2f) {-SCALE, SCALE});
            }
            if (event.key.code == sfKeyLeft || event.key.code == sfKeyQ) {
                move_left(map);
                sfSprite_setScale(*player, (sfVector2f) {SCALE, SCALE});
            }
            if (event.key.code == sfKeyDown || event.key.code == sfKeyS)
                move_down(map);
            if (event.key.code == sfKeyUp || event.key.code == sfKeyZ)
                move_up(map);
        }
    }
}

char rand_char(void)
{
    char rez = 'l';

    if (random() % 2)
        rez = 't';
    if (random() % 3)
        rez = 'o';
    if (random() % 4)
        rez = '.';
    return rez;
}

char **generate_map(void)
{
    char **map_array = malloc(sizeof(char *) * 7);

    srandom(time(NULL));
    for (int i = 0; i < 7; i++) {
        map_array[i] = malloc(sizeof(char) * 7);
        for (int y = 0; y < 7; y++) {
            map_array[i][y] = rand_char();
        }
    }
    return (map_array);
}

int running(map_t map, tileset_t *tileset, sfSprite *player, game_state_t *gs)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "Dance_till_dead", sfResize | sfClose, 0);
    sfSprite *bg = sfSprite_create();
    sfTexture *bg_text = sfTexture_createFromFile("sprites/space_bg.png", 0);

    sfSprite_setTexture(bg, bg_text, 1);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfColor_fromRGB(5, 2, 79));
        event_poll(&window, map, &player);
        sfRenderWindow_drawSprite(window, bg, 0);
        draw_grid(&window, tileset, map);
        sfRenderWindow_drawSprite(window, player, 0);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    return 0;
}
