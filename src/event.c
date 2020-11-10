/*
** EPITECH PROJECT, 2019
** event
** File description:
** defender
*/

#include "../include/my.h"

int button_is_clicked(button_t button, sfVector2f click_position)
{
    sfVector2f size = sfRectangleShape_getSize(button.rect);
    sfVector2f position = sfRectangleShape_getPosition(button.rect);

    if ((click_position.x >= position.x &&
        click_position.x <= position.x + size.x) &&
        (click_position.y >= position.y &&
        click_position.y <= position.y + size.y))
        return (1);
    else
        return (0);
}

int pause_unpause(all_game_t *all_game, sfEvent event, scene_t scene)
{
    if (event.key.code == sfKeyEscape && all_game->ret == 1)
        all_game->ret = change_scene_pause(all_game, scene);
    else if (event.key.code == sfKeyEscape && all_game->ret == 4)
        all_game->ret = change_scene_game(all_game, scene);
    return (all_game->ret);
}

int analyse_clicks(all_game_t *all_game, scene_t scene, sfEvent event)
{
    for (int i = 0; i < scene.nbr_buttons; i++) {
        if (button_is_clicked(scene.buttons[i],
                            (sfVector2f){event.mouseButton.x,
                                    event.mouseButton.y})) {
            all_game->ret = scene.buttons[i].callback(all_game, scene);
            return (all_game->ret);
        }
    }
    if (all_game->is_selected != 0 && all_game->ret == 1) {
        save_towers((sfVector2f){event.mouseButton.x, event.mouseButton.y},
                    all_game);
        return (all_game->ret);
    }
    return (all_game->ret);
}

int analyse_events(all_game_t *all_game, scene_t scene)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(all_game->window, &event)) {
        switch (event.type) {
        case sfEvtMouseButtonPressed :
            all_game->ret = analyse_clicks(all_game, scene, event);
            return (all_game->ret);
            break;
        case sfEvtKeyPressed :
            all_game->ret = pause_unpause(all_game, event, scene);
            return (all_game->ret);
        case sfEvtClosed :
            sfRenderWindow_close(all_game->window);
            break;
        }
    }
    return (all_game->ret);
}
