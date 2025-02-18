/*
** EPITECH PROJECT, 2025
** /home/elouan/projet_perso/Dtd/monster
** File description:
** 01100010 01101001 01101110 01100001 01110010 01111001
*/

#include <time.h>
#include <stdlib.h>
#include "include/settings.h"

char **generate_entity_map(void)
{
    char **entity_array = malloc(sizeof(char *) * 7);

    srandom(time(NULL));
    for (int i = 0; i < 7; i++) {
        entity_array[i] = malloc(sizeof(char) * 7);
        for (int y = 0; y < 7; y++) {
            entity_array[i][y] = '.';
        }
    }
    return (entity_array);
}
