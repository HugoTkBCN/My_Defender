/*
** EPITECH PROJECT, 2018
** my_strcpy
** File description:
** task01
*/

#include "../include/my.h"

char *my_strcpy(char *dest, char *src)
{
    int i = 0;

    for (i = 0; src[i]; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
