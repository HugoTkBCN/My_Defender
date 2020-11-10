/*
** EPITECH PROJECT, 2019
** jonathan
** File description:
** check_dead
*/

#include "../include/my.h"

en_t *check_dead2(en_t *enemy, int i)
{
    enemy[i].dead = DEAD_ANIMATION;
    enemy[i].size.left = SPRITE_DEAD_BEGIN2;
    if (enemy[i].hp > 0) {
        enemy[i].speed_change = 0;
        enemy[i].dead = ALIVE;
        enemy[i].size.left = SPRITE_WALK_RESET2;
    }
    return (enemy);
}

en_t *check_dead(en_t *enemy, int i)
{
    enemy[i].dead = DEAD_ANIMATION;
    enemy[i].size.left = SPRITE_DEAD_BEGIN;
    if (enemy[i].hp > 0) {
        enemy[i].speed_change = 0;
        enemy[i].dead = ALIVE;
        enemy[i].size.left = SPRITE_WALK_RESET;
    }
    return (enemy);
}
