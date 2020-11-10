/*
** EPITECH PROJECT, 2019
** jonathan
** File description:
** enemy_moves
*/

#include "../include/my.h"

en_t *enemy_dead(en_t *enemy, sfRenderWindow *window, int i)
{
    if (enemy[i].dead == ALIVE || enemy[i].dead == JUST_DEAD)
        return (enemy);
    enemy = move_bullet(enemy, i);
    if (enemy[i].size.left < SPRITE_DEAD && enemy[i].dead == DEAD_ANIMATION)
        enemy[i].size.left += SPRITE_WALK;
    else if (enemy[i].dead == DEAD_ANIMATION) {
        enemy[i].size.left = SPRITE_DEAD;
        enemy[i].dead = JUST_DEAD;
    }
    return (enemy);
}

en_t *enemy_dead2(en_t *enemy, sfRenderWindow *window, int i)
{
    if (enemy[i].dead == ALIVE || enemy[i].dead == JUST_DEAD)
        return (enemy);
    enemy = move_bullet2(enemy, i);
    if (enemy[i].size.left < SPRITE_DEAD2 && enemy[i].dead == DEAD_ANIMATION)
        enemy[i].size.left += SPRITE_DEAD_WALK2;
    else if (enemy[i].dead == DEAD_ANIMATION) {
        enemy[i].size.left = SPRITE_DEAD2;
        enemy[i].dead = JUST_DEAD;
    }
    return (enemy);
}

en_t *enemy_move(en_t *enemy, int i)
{
    if (enemy[i].dead == DEAD_ANIMATION || enemy[i].dead == JUST_DEAD)
        return (enemy);
    i = i;
    if (enemy[i].size.left < SPRITE_SPAWN_COND)
        enemy[i].size.left += SPRITE_SPAWN;
    else if (enemy[i].size.left < SPRITE_WALK_COND)
        enemy[i].size.left += SPRITE_WALK;
    else
        enemy[i].size.left = SPRITE_WALK_RESET;
    return (enemy);
}

en_t *enemy_move2(en_t *enemy, int i)
{
    if (enemy[i].dead == DEAD_ANIMATION || enemy[i].dead == JUST_DEAD)
        return (enemy);
    else if (enemy[i].size.left < SPRITE_WALK_COND2)
        enemy[i].size.left += SPRITE_WALK2;
    else
        enemy[i].size.left = SPRITE_WALK_RESET2;
    return (enemy);
}

en_t *enemy_moves(en_t *enemy, sfRenderWindow *window)
{
    for (int i = 0; i < (enemy[0].quantity / 2); i++) {
        enemy = enemy_move(enemy, i);
        enemy = enemy_dead(enemy, window, i);
        texture_enemy_bullet(enemy, i);
    }
    for (int i = (enemy->quantity / 2); i < enemy[0].quantity; i++) {
        enemy = enemy_move2(enemy, i);
        enemy = enemy_dead2(enemy, window, i);
        texture_enemy_bullet(enemy, i);
    }
    return (enemy);
}
