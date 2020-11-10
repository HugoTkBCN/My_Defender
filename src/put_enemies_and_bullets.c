/*
** EPITECH PROJECT, 2019
** draw enemies and bullets
** File description:
** defender
*/

#include "../include/my.h"

void put_enemies_and_bullets(all_game_t *all_game, en_t *enemy,
                            sfClock **clocks)
{
    put_money(all_game);
    infinite_sprite(enemy, all_game->window, clocks[1]);
    kill_enemy(all_game->towers_lvl1, enemy, all_game->window, clocks[2]);
    kill_enemy(all_game->towers_lvl2, enemy, all_game->window, clocks[3]);
    kill_enemy(all_game->towers_lvl3, enemy, all_game->window, clocks[4]);
    kill_enemy(all_game->towers_lvl4, enemy, all_game->window, clocks[5]);
    for (int i = 0; i < enemy[0].quantity; i++) {
        if (enemy[i].dead == 1 && enemy[i].b_pos.x > 0 &&
            enemy[i].b_pos.y > 200 && enemy[i].display == 1) {
            sfSprite_setPosition(enemy[i].s_bull, enemy[i].b_pos);
            sfRenderWindow_drawSprite(all_game->window, enemy[i].s_bull, NULL);
        }
    }
}
