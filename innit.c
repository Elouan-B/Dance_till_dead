
/*
** EPITECH PROJECT, 2024
** main
** File description:
** epitech > epita
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System/Clock.h>
#include <time.h>
#include <stdlib.h>
#include "include/settings.h"
#include "include/structures.h"

static map_t innit_map(void)
{
    char **tiles_map = generate_map();
    char **entity_map = NULL;

    map_t map = {tiles_map, entity_map};
    return map;
}

static tileset_t *innit_tileset(void)
{
    sfSprite *tile = sfSprite_create();
    sfTexture *tile_text = sfTexture_createFromFile("sprites/tile.png", 0);
    sfSprite *tile2 = sfSprite_create();
    sfTexture *tile_text2 = sfTexture_createFromFile("sprites/tile2.png", 0);
    tileset_t *tileset = malloc(sizeof(tileset_t *));


    sfSprite_setTexture(tile, tile_text, 1);
    sfSprite_setScale(tile, (sfVector2f) {SCALE, SCALE});
    sfSprite_setTexture(tile2, tile_text2, 1);
    sfSprite_setScale(tile2, (sfVector2f) {SCALE, SCALE});
    tileset->tile1 = tile;
    tileset->tile2 = tile2;
    return tileset;
}

static sfSprite *innit_player(void)
{
    sfSprite *player = sfSprite_create();
    sfTexture *player_text = sfTexture_createFromFile("sprites/player.png", 0);

    sfSprite_setTexture(player, player_text, 1);
    sfSprite_setScale(player, (sfVector2f) {SCALE, SCALE});
    sfSprite_setPosition(player, (sfVector2f) {OFFSET + (TILE_SIZE * 3) + 34, 78 + (TILE_SIZE * 2)});
    sfSprite_setOrigin(player, (sfVector2f) {SPRITE_SIZE / 2, SPRITE_SIZE / 2});
    sfSprite_setColor(player, sfColor_fromRGB(200, 200, 255));
    return player;
}

static game_state_t *innit_game_state(void)
{
    game_state_t *state = malloc(sizeof(game_state_t *));

    state->animation_clock = sfClock_create();
    state->timing_clock = sfClock_create();
    state->hp = HP;
    return state;
}

int innit(void)
{
    sfSprite *player = innit_player();
    map_t map = innit_map();
    tileset_t *tileset = innit_tileset();
    game_state_t *state = innit_game_state();
    return (running(map, tileset, player, state));
}
