/*
** EPITECH PROJECT, 2019
** action button menu
** File description:
** defender
*/

#include "../include/my.h"

int quit_game(all_game_t *all_game, scene_t scene)
{
    sfRenderWindow_close(all_game->window);
    return (all_game->ret);
}

int change_scene_game(all_game_t *all_game, scene_t scene)
{
    all_game->prev_scene = all_game->ret;
    all_game->ret = 1;
    return (all_game->ret);
}

int change_scene_menu(all_game_t *all_game, scene_t scene)
{
    all_game->prev_scene = all_game->ret;
    all_game->ret = 0;
    return (all_game->ret);
}

int change_scene_help(all_game_t *all_game, scene_t scene)
{
    all_game->prev_scene = all_game->ret;
    all_game->ret = 2;
    return (all_game->ret);
}

int change_scene_scores(all_game_t *all_game, scene_t scene)
{
    all_game->prev_scene = all_game->ret;
    all_game->ret = 3;
    return (all_game->ret);
}
