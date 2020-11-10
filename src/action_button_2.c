/*
** EPITECH PROJECT, 2019
** action button menu
** File description:
** defender
*/

#include "../include/my.h"

int change_scene_credits(all_game_t *all_game, scene_t scene)
{
    all_game->prev_scene = all_game->ret;
    all_game->ret = 5;
    return (all_game->ret);
}

int change_scene_pause(all_game_t *all_game, scene_t scene)
{
    all_game->prev_scene = all_game->ret;
    all_game->ret = 4;
    return (all_game->ret);
}

int change_prev_scene(all_game_t *all_game, scene_t scene)
{
    all_game->ret = all_game->prev_scene;
    return (all_game->ret);
}
