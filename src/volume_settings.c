/*
** EPITECH PROJECT, 2019
** volume_settings
** File description:
** volume up and volume down
*/

#include "../include/my.h"

music_t music_display(music_t music, sfRenderWindow *window)
{
    sfFont *font = sfFont_createFromFile(PATH_TO_FONT);
    char *str = "100";
    sfColor color = sfColor_fromRGB(255, 255, 255);
    sfVector2f pos = {125, 50};

    music.music = sfMusic_createFromFile(PATH_TO_MUSIC);
    music.volume = 100;
    sfMusic_play(music.music);
    music.text = sfText_create();
    sfText_setString(music.text, str);
    sfText_setFont(music.text, font);
    sfText_setCharacterSize(music.text, 30);
    sfText_setColor(music.text, color);
    sfText_setPosition(music.text, pos);
    return (music);
}

int draw_changed_volume(all_game_t *all_game, int quit, int prev_volume,
                        scene_t scene)
{
    if (quit == 0  && all_game->music.volume != prev_volume) {
        sfRenderWindow_clear(all_game->window, sfBlack);
        draw_scene(scene, all_game->window);
        all_game->music.volume == 0 ?
            sfText_setString(all_game->music.text, "0") :
            sfText_setString(all_game->music.text,
                            int_to_str(all_game->music.volume));
        sfRenderWindow_drawText(all_game->window, all_game->music.text, NULL);
        sfRenderWindow_display(all_game->window);
        prev_volume = all_game->music.volume;
    }
    return (prev_volume);
}

int change_volume(all_game_t *all_game, scene_t scene)
{
    int quit = 0;
    sfEvent event;
    int prev_volume = 0;

    while (sfRenderWindow_pollEvent(all_game->window, &event) || quit == 0) {
        switch (event.type) {
        case sfEvtKeyPressed :
            volume_settings(&all_game->music, all_game->window, event);
            break;
        case sfEvtMouseButtonPressed :
            quit = 1;
            break;
        case sfEvtClosed :
            sfRenderWindow_close(all_game->window);
            quit = 1;
            break;
        }
        prev_volume = draw_changed_volume(all_game, quit, prev_volume, scene);
    }
    return (all_game->ret);
}

int volume_settings(music_t *music, sfRenderWindow *window, sfEvent event)
{
    if (event.key.code == sfKeyUp && music->volume < 100) {
        sfMusic_setVolume(music->music, music->volume += 5);
    } else if (event.key.code == sfKeyDown && music->volume > 0) {
        sfMusic_setVolume(music->music, music->volume -= 5);
    }
}
