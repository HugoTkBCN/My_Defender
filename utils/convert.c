/*
** EPITECH PROJECT, 2018
** convert
** File description:
** convertisseur
*/

#include "../include/my.h"

int str_to_int(char *nbr)
{
    int i = 0;
    int res = 0;

    while (nbr[i]) {
        res = res * 10;
        res = res + (nbr[i++] - 48);
    }
    return (res);
}

char *int_to_str(int nbr)
{
    int i = 0;
    int tmp = 0;
    char *str;

    str = malloc(sizeof(int) * nbr + 1);
    while (nbr != 0) {
        tmp = nbr % 10;
        str[i++] = tmp + 48;
        nbr = nbr / 10;
    }
    str[i] = '\0';
    str = my_revstr(str);
    return (str);
}
