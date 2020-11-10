/*
** EPITECH PROJECT, 2019
** put toer
** File description:
** my defender
*/

#include "../include/my.h"

void draw_tower(all_game_t all_game, sfSprite *sprite, sfVector2f pos)
{
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(all_game.window, sprite, NULL);
}

void put_towers(all_game_t all_game)
{
    for (int i = 0; i < NBR_TOWER_MAX; i++) {
        all_game.towers_lvl1[i].put == 1 ?
            draw_tower(all_game, all_game.image_tower1.sprite,
                        all_game.towers_lvl1[i].pos) : 0;
        all_game.towers_lvl2[i].put == 1 ?
            draw_tower(all_game, all_game.image_tower2.sprite,
                        all_game.towers_lvl2[i].pos) : 0;
        all_game.towers_lvl3[i].put == 1 ?
            draw_tower(all_game, all_game.image_tower3.sprite,
                        all_game.towers_lvl3[i].pos) : 0;
        all_game.towers_lvl4[i].put == 1 ?
            draw_tower(all_game, all_game.image_tower4.sprite,
                        all_game.towers_lvl4[i].pos) : 0;
    }
}
