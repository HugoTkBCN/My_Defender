/*
** EPITECH PROJECT, 2019
** init ennemy
** File description:
** defender
*/

#include "../include/my.h"

en_t *enemy_initial_values(en_t *enemy, int quantity)
{
    enemy->quantity = quantity;
    enemy->attack = 0;
    for (int i = 0; i < enemy->quantity; i++) {
        enemy[i].dead = ALIVE;
        enemy[i].speed_change = 0;
    }
    return (enemy);
}
