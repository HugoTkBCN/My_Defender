/*
** EPITECH PROJECT, 2019
** destroy
** File description:
** defender
*/

#include "../include/my.h"

void destroy_images(image_t *image)
{
    sfTexture_destroy(image->texture);
    sfSprite_destroy(image->sprite);
}

void destroy_game_object(game_object_t *objs)
{
    sfTexture_destroy(objs->texture);
    sfSprite_destroy(objs->sprite);
}
