/*
** EPITECH PROJECT, 2019
** infinite_sprite
** File description:
** create infinite sprites
*/

#include "../include/my.h"

en_t *destroy_enemy_resources(en_t *enemy, int quantity)
{
    for (int i = 0; i < quantity; i++) {
        sfTexture_destroy(enemy[i].texture);
        sfSprite_destroy(enemy[i].sprite);
        sfTexture_destroy(enemy[i].t_bull);
        sfSprite_destroy(enemy[i].s_bull);
    }
    return (enemy);
}

en_t *create_enemy(en_t *enemy)
{
    int quantity = enemy->quantity + ADD_ENEMIES_WAVE;

    if (quantity > MAX_QUANTITY)
        quantity = MAX_QUANTITY;
    enemy = destroy_enemy_resources(enemy, enemy->quantity);
    enemy = enemy_initial_values(enemy, quantity);
    enemy = display_enemies(enemy, quantity);
    return (enemy);
}

int check_wave(en_t *enemy)
{
    for (int i = 0; i < (enemy->quantity - 1); i++) {
        if (enemy[i].dead < 3)
            return (0);
    }
        return (1);
}

void texture_enemy_bullet(en_t *enemy, int i)
{
    sfSprite_setPosition(enemy[i].sprite, enemy[i].position);
    sfSprite_setTexture(enemy[i].sprite, enemy[i].texture, 0);
    sfSprite_setTextureRect(enemy[i].sprite, enemy[i].size);
    if (enemy[i].dead == WALKING_DEAD) {
        sfSprite_setPosition(enemy[i].s_bull, enemy[i].b_pos);
        sfSprite_setTexture(enemy[i].s_bull, enemy[i].t_bull, 0);
    }
}

void infinite_sprite(en_t *enemy, sfRenderWindow *window, sfClock *clock)
{
    float seconds = (sfClock_getElapsedTime(clock).microseconds / 1000000.0);

    enemy = check_wave(enemy) == 1 ? create_enemy(enemy) : enemy;
    enemy = seconds > SPRITE_VELOCITY ? enemy_moves(enemy, window) : enemy;
    if (seconds > SPRITE_VELOCITY)
        sfClock_restart(clock);
    for (int i = 0; i < enemy[0].quantity; i++) {
        if (seconds > SPRITE_VELOCITY / 2 && enemy[i].hp > 0) {
            enemy[i].position.x += enemy[i].type == 0 ?
                SPEED_ZOMBIE : SPEED_SPIDER;
            enemy[i].display = enemy[i].position.x >= X_CASTLE ?
                0 : enemy[i].display;
            enemy[i].hp = enemy[i].position.x >= X_CASTLE ? 0 : enemy[i].hp;
            enemy[i].dead = enemy[i].position.x >= X_CASTLE ? 3 : enemy[i].dead;
        }
        enemy[i].display == 1 ? sfSprite_setPosition(enemy[i].sprite,
                                                    enemy[i].position) : 0;
        enemy[i].display == 1 ? sfRenderWindow_drawSprite(window,
                                                    enemy[i].sprite, NULL) : 0;
    }
}
