/*
** EPITECH PROJECT, 2019
** animation
** File description:
** defender
*/

#include "../include/my.h"

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->top = 0;
    if (rect->left == max_value - offset)
        rect->left = 0;
    else
        rect->left = rect->left + offset;
    rect->width = WIDTH_WP;
    rect->height = HEIGHT_WP;
}
