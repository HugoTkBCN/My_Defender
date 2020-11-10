/*
** EPITECH PROJECT, 2019
** put tower
** File description:
** my defender
*/

#include "../include/my.h"

tower_t *init_tower(tower_t *tower)
{
    for (int i = 0; i < NBR_TOWER_MAX; i++) {
        tower[i].put = 0;
        tower[i].life = 100;
        tower[i].pos = (sfVector2f){0, 0};
    }
    return (tower);
}

int select_tower_lvl1(all_game_t *all_game, scene_t scene)
{
    if (all_game->is_selected == 1)
        all_game->is_selected = 0;
    else
        all_game->is_selected = 1;
    all_game->selected.pos = POS_BUTTON_LVL1;
    sfSprite_setPosition(all_game->selected.sprite, all_game->selected.pos);
    return (all_game->ret);
}

int select_tower_lvl2(all_game_t *all_game, scene_t scene)
{
    if (all_game->is_selected == 2)
        all_game->is_selected = 0;
    else
        all_game->is_selected = 2;
    all_game->selected.pos = POS_BUTTON_LVL2;
    sfSprite_setPosition(all_game->selected.sprite, all_game->selected.pos);
    return (all_game->ret);
}

int select_tower_lvl3(all_game_t *all_game, scene_t scene)
{
    if (all_game->is_selected == 3)
        all_game->is_selected = 0;
    else
        all_game->is_selected = 3;
    all_game->selected.pos = POS_BUTTON_LVL3;
    sfSprite_setPosition(all_game->selected.sprite, all_game->selected.pos);
    return (all_game->ret);
}

int select_tower_lvl4(all_game_t *all_game, scene_t scene)
{
    if (all_game->is_selected == 4)
        all_game->is_selected = 0;
    else
        all_game->is_selected = 4;
    all_game->selected.pos = POS_BUTTON_LVL4;
    sfSprite_setPosition(all_game->selected.sprite, all_game->selected.pos);
    return (all_game->ret);
}
