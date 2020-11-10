/*
** EPITECH PROJECT, 2018
** strdup
** File description:
** task01
*/

#include "../include/my.h"

char *my_strdup(char *src)
{
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));

    if (dest == NULL)
        return (NULL);
    my_strcpy(dest, src);
    return (dest);
}
