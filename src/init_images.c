/*
** EPITECH PROJECT, 2019
** init images
** File description:
** defender
*/

#include "../include/my.h"

void init_image(image_t *image, char *filepath)
{
    image->texture = sfTexture_createFromFile(filepath, NULL);
    image->sprite = sfSprite_create();
    sfSprite_setTexture(image->sprite, image->texture, sfTrue);
}
