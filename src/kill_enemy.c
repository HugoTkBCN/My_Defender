/*
** EPITECH PROJECT, 2019
** jonathan
** File description:
** kill_enemy
*/

#include "../include/my.h"

en_t *enemy_conditions(en_t *enemy, tower_t tower, int **zom, int i)
{
    sfVector2f pos = tower.pos;
    int hp = enemy[i].hp;

    if ((pos.x - zom[i][0]) >= - tower.range &&
        (pos.x - zom[i][0]) <= tower.range
        && (pos.y - zom[i][1]) >= - tower.range &&
        (pos.y - zom[i][1]) <= tower.range) {
        if (enemy[i].dead == ALIVE && enemy[0].attack == 1 && enemy[i].hp > 0) {
            enemy[i].size.left = SPRITE_DEAD_BEGIN;
            enemy[i].dead = WALKING_DEAD;
            enemy[0].attack = 0;
        }
    }
    return (enemy);
}

int **zombie_positions(en_t *enemy, int quantity)
{
    int **zom = malloc(sizeof(int *) * (quantity + 1));
    sfVector2f z_pos;

    for (int i = 0; i < quantity; i++)
        zom[i] = malloc(sizeof(int) * 3);
    for (int i = 0; i < quantity; i++) {
        z_pos = enemy[i].position;
        zom[i][0] = z_pos.x;
        zom[i][1] = z_pos.y;
    }
    return (zom);
}

void kill_enemy(tower_t *tower, en_t *enemy, sfRenderWindow *window,
                sfClock *clock)
{
    int **zom = zombie_positions(enemy, enemy->quantity);
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = (time.microseconds / 1000000.0);

    if (seconds >= tower[0].speed_attack &&
        (tower[0].speed_attack == SPEED_ATT[0] ||
        tower[0].speed_attack == SPEED_ATT[1] ||
        tower[0].speed_attack == SPEED_ATT[2] ||
        tower[0].speed_attack == SPEED_ATT[3])) {
        for (int y = 0; tower[y].put == 1; y++) {
            enemy[0].attack = 1;
            for (int i = 0; i < enemy[0].quantity; i++) {
                enemy = enemy_conditions(enemy, tower[y], zom, i);
                enemy = kill_bullet(tower[y], enemy, window);
                i = enemy[0].attack == 0 ? enemy[0].quantity : i;
            }
        }
        sfClock_restart(clock);
    }
    free(zom);
}
