/*
** EPITECH PROJECT, 2018
** strlen
** File description:
** returns the number of characters found in the string
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}
