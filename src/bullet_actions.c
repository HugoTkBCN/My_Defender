/*
** EPITECH PROJECT, 2019
** jonathan
** File description:
** bullet_actions
*/

#include "../include/my.h"

en_t *move_bullet(en_t *enemy, int i)
{
    int x = enemy[i].position.x;
    int y = enemy[i].position.y;
    int hp = enemy[i].hp;

    enemy[i].b_pos.x += enemy[i].speed_x * BULLET_SPEED / 2;
    enemy[i].b_pos.y += enemy[i].speed_y * BULLET_SPEED / 2;
    if ((enemy[i].b_pos.x - enemy[i].position.x <= BULLET_RANGE &&
        (enemy[i].b_pos.x - enemy[i].position.x) >= - BULLET_RANGE))
        if ((enemy[i].b_pos.y - enemy[i].position.y <= BULLET_RANGE &&
            (enemy[i].b_pos.y - enemy[i].position.y) >= - BULLET_RANGE)) {
            enemy[i].hp -= 1;
            enemy = check_dead(enemy, i);
        }
    return (enemy);
}

en_t *move_bullet2(en_t *enemy, int i)
{
    int x = enemy[i].position.x;
    int y = enemy[i].position.y;
    int hp = enemy[i].hp;

    enemy[i].b_pos.x += enemy[i].speed_x * BULLET_SPEED / 2;
    enemy[i].b_pos.y += enemy[i].speed_y * BULLET_SPEED / 2;
    if ((enemy[i].b_pos.x - enemy[i].position.x <= BULLET_RANGE &&
        (enemy[i].b_pos.x - enemy[i].position.x) >= - BULLET_RANGE))
        if ((enemy[i].b_pos.y - enemy[i].position.y <= BULLET_RANGE &&
            (enemy[i].b_pos.y - enemy[i].position.y) >= - BULLET_RANGE)) {
            enemy[i].hp -= 1;
            enemy = check_dead2(enemy, i);
        }
    return (enemy);
}

en_t *bullet_speed(en_t *enemy, sfVector2f e_pos, sfVector2f t_pos, int i)
{
    int x = t_pos.x - e_pos.x;
    int y = t_pos.y - e_pos.y;

    x = -x;
    y = -y;
    enemy[i].speed_x = x / BULLET_SPEED;
    enemy[i].speed_y = y / BULLET_SPEED;
    enemy[i].b_pos = t_pos;
    enemy[i].speed_change = 1;
    return (enemy);
}

en_t *kill_bullet(tower_t tower, en_t *enemy, sfRenderWindow *window)
{
    for (int i = 0; i < enemy->quantity; i++) {
        if (enemy[i].dead != WALKING_DEAD)
            continue;
        i = i;
        if (enemy[i].speed_change == 0)
            enemy = bullet_speed(enemy, enemy[i].position, tower.pos, i);
    }
    return (enemy);
}
