/*
** EPITECH PROJECT, 2019
** save towers pos
** File description:
** defender
*/

#include "../include/my.h"

int loop_is_tower(tower_t *tower, sfVector2f pos)
{
    sfVector2f pos_tower;

    for (int i = 0; tower[i].put == 1; i++) {
        pos_tower = tower[i].pos;
        if ((pos.x >= pos_tower.x + MARGE_TOWER_BEFORE.x &&
            pos.x <= pos_tower.x + MARGE_TOWER_AFTER.x) &&
            (pos.y >= pos_tower.y - MARGE_TOWER_BEFORE.y &&
            pos.y <= pos_tower.y + MARGE_TOWER_AFTER.y))
            return (1);
    }
    return (0);
}

int is_tower(all_game_t all_game, sfVector2f pos)
{
    int ret = 0;

    ret = loop_is_tower(all_game.towers_lvl1, pos);
    if (ret == 1)
        return (1);
    ret = loop_is_tower(all_game.towers_lvl2, pos);
    if (ret == 1)
        return (1);
    ret = loop_is_tower(all_game.towers_lvl3, pos);
    if (ret == 1)
        return (1);
    ret = loop_is_tower(all_game.towers_lvl4, pos);
    if (ret == 1)
        return (1);
    return (0);
}

int check_money(all_game_t *all_game, int money)
{
    switch (all_game->is_selected) {
    case 1:
        money = all_game->money.money >= MONEY_100 ? 1 : 0;
        all_game->money.money -= all_game->money.money >= 100 ? 100 : 0;
        break;
    case 2:
        money = all_game->money.money >= MONEY_250 ? 1 : 0;
        all_game->money.money -= all_game->money.money >= 250 ? 250 : 0;
        break;
    case 3:
        money = all_game->money.money >= MONEY_500 ? 1 : 0;
        all_game->money.money -= all_game->money.money >= 500 ? 500 : 0;
        break;
    case 4:
        money = all_game->money.money >= MONEY_1000 ? 1 : 0;
        all_game->money.money -= all_game->money.money >= 1000 ? 1000 : 0;
        break;
    }
    return (money);
}

tower_t *save_pos(tower_t *towers, sfVector2f pos, all_game_t *all_game)
{
    int i = 0;
    int prev_money = all_game->money.money;
    int money = 0;

    pos.y = (pos.y >= LIM_UPROAD[0] && pos.y <= LIM_UPROAD[1]) ? POS_1 : pos.y;
    pos.y = (pos.y >= LIM_DOROAD[0] && pos.y <= LIM_DOROAD[1]) ? POS_2 : pos.y;
    pos.y = (pos.y >= LIM_WINDOW[0] && pos.y <= LIM_WINDOW[1]) ? POS_3 : pos.y;
    money = check_money(all_game, money);
    if (pos.x < X_CASTLE && ((pos.y <= POS_3 && pos.y >= POS_2) ||
        pos.y <= POS_1) && is_tower(*all_game, pos) == 0 && money == 1) {
        for (i = 0; towers[i].put == 1; i++) {
        }
        towers[i].put = 1;
        towers[i].pos.x = pos.x - (WIDTH_TOWER / 2);
        towers[i].pos.y = pos.y - (HEIGHT_TOWER / 2);
        towers[i].speed_attack = SPEED_ATT[all_game->is_selected - 1];
        towers[i].range = RANGE_TOWER[all_game->is_selected - 1];
    } else
        all_game->money.money = prev_money;
    return (towers);
}

void save_towers(sfVector2f pos, all_game_t *all_game)
{
    switch (all_game->is_selected) {
    case 1 :
        all_game->towers_lvl1 = save_pos(all_game->towers_lvl1, pos, all_game);
        break;
    case 2 :
        all_game->towers_lvl2 = save_pos(all_game->towers_lvl2, pos, all_game);
        break;
    case 3 :
        all_game->towers_lvl3 = save_pos(all_game->towers_lvl3, pos, all_game);
        break;
    case 4 :
        all_game->towers_lvl4 = save_pos(all_game->towers_lvl4, pos, all_game);
        break;
    }
}
