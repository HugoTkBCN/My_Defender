/*
** EPITECH PROJECT, 2019
** frame_limit_settings
** File description:
** vary the frame limit
*/

#include "../include/my.h"

int draw_when_change_fps(all_game_t *all_game, int quit, int prev_fps,
                        scene_t scene)
{
    if (quit == 0 && all_game->fps.fps != prev_fps) {
        sfRenderWindow_clear(all_game->window, sfBlack);
        draw_scene(scene, all_game->window);
        all_game->fps.fps == 0 ? sfText_setString(all_game->fps.text, "0") :
            sfText_setString(all_game->fps.text, int_to_str(all_game->fps.fps));
        sfRenderWindow_drawText(all_game->window, all_game->fps.text, NULL);
        sfRenderWindow_display(all_game->window);
        prev_fps = all_game->fps.fps;
    }
    return (prev_fps);
}

int change_fps(all_game_t *all_game, scene_t scene)
{
    int quit = 0;
    sfEvent event;
    int prev_fps = 0;

    while (sfRenderWindow_pollEvent(all_game->window, &event) || quit == 0) {
        switch (event.type) {
        case sfEvtKeyPressed :
            frame_limit_settings(all_game, event);
            break;
        case sfEvtMouseButtonPressed :
            quit = 1;
            break;
        case sfEvtClosed :
            sfRenderWindow_close(all_game->window);
            quit = 1;
            break;
        }
        prev_fps = draw_when_change_fps(all_game, quit, prev_fps, scene);
    }
    return (all_game->ret);
}

void frame_limit_settings(all_game_t *all_game, sfEvent event)
{
    if (event.key.code == sfKeyUp && all_game->fps.fps < 60) {
        all_game->fps.fps += 5;
    } else if (event.key.code == sfKeyDown && all_game->fps.fps > 0) {
        all_game->fps.fps -= 5;
    }
    sfRenderWindow_setFramerateLimit(all_game->window, all_game->fps.fps);
}
