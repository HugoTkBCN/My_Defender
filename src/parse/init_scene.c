/*
** EPITECH PROJECT, 2019
** init scene
** File description:
** defender
*/

#include "../../include/my.h"

button_t init_button(button_t *button, sfVector2f position,
                    char *path_to_texture)
{
    sfVector2u size_u;
    sfVector2f size;

    button->rect = sfRectangleShape_create();
    button->texture = sfTexture_createFromFile(path_to_texture, NULL);
    size_u = sfTexture_getSize(button->texture);
    size.x = size_u.x;
    size.y = size_u.y;
    sfRectangleShape_setPosition(button->rect, position);
    sfRectangleShape_setTexture(button->rect, button->texture, sfTrue);
    sfRectangleShape_setSize(button->rect, size);
    return (*button);
}

game_object_t init_game_object(game_object_t *objs, sfVector2f position,
                        char *path_to_sprite)
{
    objs->texture = sfTexture_createFromFile(path_to_sprite, NULL);
    objs->sprite = sfSprite_create();
    objs->pos = position;
    sfSprite_setTexture(objs->sprite, objs->texture, sfTrue);
    sfSprite_setPosition(objs->sprite, position);
    return (*objs);
}
