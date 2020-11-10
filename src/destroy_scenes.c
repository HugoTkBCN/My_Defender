/*
** EPITECH PROJECT, 2019
** destroy
** File description:
** defender
*/

#include "../include/my.h"

void destroy_scene(scene_t *scene)
{
    for (int i = 0; i < scene->nbr_objs; i++) {
        sfTexture_destroy(scene->objs[i].texture);
        sfSprite_destroy(scene->objs[i].sprite);
    }
    for (int i = 0; i < scene->nbr_buttons; i++) {
        sfRectangleShape_destroy(scene->buttons[i].rect);
        sfTexture_destroy(scene->buttons[i].texture);
    }
}

void destroy_scenes(scene_t *scene)
{
    for (int i = 0; i <= NBR_SCENES - 1; i++) {
        destroy_scene(&scene[i]);
    }
}

void destroy_music(music_t *music)
{
    sfMusic_destroy(music->music);
    sfText_destroy(music->text);
}

void destroy_fps(fps_t *fps)
{
    sfText_destroy(fps->text);
}
