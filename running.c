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
#include <SFML/Window/Event.h>
#include "include/settings.h"

void event_poll(sfRenderWindow **window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(*window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(*window);
    }
}

void draw_grid(sfRenderWindow **window, sfSprite *tile)
{
    for (int i = 0; i < 7; i++) {
        for (int y = 0; y < 7; y++) {
                sfSprite_setPosition(tile, (sfVector2f) {TILE_SIZE * i + OFFSET, TILE_SIZE * y + 46});
            sfRenderWindow_drawSprite(*window, tile, 0);
        }
    }
}

int running(void)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "Dance_till_dead", sfResize | sfClose, 0);
    sfSprite *tile = sfSprite_create();
    sfTexture *tile_text = sfTexture_createFromFile("sprites/tile.png", 0);

    sfSprite_setTexture(tile, tile_text, 1);
    sfSprite_setScale(tile, (sfVector2f) {SCALE, SCALE});
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfColor_fromRGB(5, 2, 79));
        event_poll(&window);
        draw_grid(&window, tile);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    return 0;
}
