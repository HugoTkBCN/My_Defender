/*
** EPITECH PROJECT, 2018
** open window
** File description:
** CSFML
*/

#include "../include/my.h"

sfRenderWindow *open_window(int width, int height, char *name)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, name, sfDefaultStyle, NULL);
    return (window);
}
