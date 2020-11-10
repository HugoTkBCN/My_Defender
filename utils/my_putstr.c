/*
** EPITECH PROJECT, 2018
** putstr
** File description:
** display one by one the characters of a string
*/

#include "../include/my.h"

void my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}
