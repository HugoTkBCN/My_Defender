/*
** EPITECH PROJECT, 2019
** jonathan
** File description:
** display_enemies
*/

#include "../include/my.h"

en_t *random_positions(en_t *enemy, int quantity)
{
    sfVector2f position = {0, 0};
    int quit = 0;

    srand(0);
    for (int i = 0; i < quantity; i++) {
        while (quit == 0) {
            position.x = (rand() % (WIDTH_WP / 4));
            quit = (position.x >= RANDOM_POS_MIN.x &&
                    position.x <= RANDOM_POS_MAX.x) ? 1 : 0;
        }
        while (quit == 1) {
            position.y = (rand() % (HEIGHT_WP - (HEIGHT_WP / 8)));
            quit = (position.y >= RANDOM_POS_MIN.y &&
                    position.y <= RANDOM_POS_MAX.y) ? 0 : 1;
        }
        enemy[i].position = position;
        sfSprite_setPosition(enemy[i].sprite, enemy[i].position);
    }
    return (enemy);
}

en_t *display_enemy1(en_t *enemy, int quantity)
{
    for (int i = 0; i < (quantity / 2); i++) {
        enemy[i].size.left = SPRITE_LEFT;
        enemy[i].size.top = 0;
        enemy[i].size.width = SPRITE_WIDTH;
        enemy[i].size.height = SPRITE_HEIGHT;
        enemy[i].texture = sfTexture_createFromFile(PATH_ZOMBIES, NULL);
        enemy[i].sprite = sfSprite_create();
        enemy[i].hp = HP;
        enemy[i].type = 0;
        enemy[i].display = 1;
        enemy[1].speed_x = SPEED_ZOMBIE;
        enemy[1].speed_y = 0;
    }
    return (enemy);
}

en_t *display_enemy2(en_t *enemy, int quantity)
{
    for (int i = (quantity / 2); i < quantity; i++) {
        enemy[i].size.left = SPRITE_LEFT2;
        enemy[i].size.top = 0;
        enemy[i].size.width = SPRITE_WIDTH2;
        enemy[i].size.height = SPRITE_HEIGHT2;
        enemy[i].texture = sfTexture_createFromFile(PATH_SPIDERS, NULL);
        enemy[i].sprite = sfSprite_create();
        enemy[i].hp = HP2;
        enemy[i].type = 1;
        enemy[i].display = 1;
        enemy[1].speed_x = SPEED_SPIDER;
        enemy[1].speed_y = 0;
    }
    return (enemy);
}

en_t *display_bullet(en_t * enemy, int quantity)
{
    for (int i = 0; i < quantity; i++) {
        enemy[i].t_bull = sfTexture_createFromFile(PATH_BULLETS, NULL);
        enemy[i].s_bull = sfSprite_create();
        sfSprite_setTexture(enemy[i].s_bull, enemy[i].t_bull, 0);
    }
    return (enemy);
}

en_t *display_enemies(en_t *enemy, int quantity)
{
    enemy = display_enemy1(enemy, quantity);
    enemy = display_enemy2(enemy, quantity);
    enemy = display_bullet(enemy, quantity);
    enemy = random_positions(enemy, quantity);
    return (enemy);
}
