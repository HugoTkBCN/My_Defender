/*
** EPITECH PROJECT, 2019
** get me doc
** File description:
** for parser
*/

#include "../../include/my.h"

int get_nbr_line(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char buff[2];
    int line = 1;

    while (read(fd, buff, 1) != 0) {
        buff[1] = '\0';
        if (buff[0] == '\n')
            line++;
    }
    close(fd);
    return (line);
}

char *get_filepath(char *conf)
{
    int i = 0;
    char *filepath = "";
    char letter[2];

    for (i = 0; conf[i] != '"'; i++) {
    }
    for (i = i + 1; conf[i] != '"'; i++) {
        letter[0] = conf[i];
        letter[1] = '\0';
        filepath = mem_alloc(filepath, letter);
    }
    return (filepath);
}

int get_x(int i, char *conf, int for_i)
{
    char letter[2];
    char *tmp = "";

    for (i = 0; conf[i] != ';'; i++) {
    }
    for (i; conf[i] != '='; i++) {
    }
    for (i = i + 2; conf[i] != ' '; i++) {
        letter[0] = conf[i];
        letter[1] = '\0';
        tmp = mem_alloc(tmp, letter);
    }
    if (for_i == 1)
        return (i);
    return (str_to_int(tmp));
}

int get_y(int i, char *conf)
{
    char letter[2];
    char *tmp = "";

    for (i; conf[i] != '='; i++) {
    }
    for (i = i + 2; conf[i] != '\n' && conf[i] != '\0'; i++) {
        letter[0] = conf[i];
        letter[1] = '\0';
        tmp = mem_alloc(tmp, letter);
    }
    return (str_to_int(tmp));
}

sfVector2f get_pos(char *conf)
{
    sfVector2f pos;
    int i = 0;

    pos.x = get_x(i, conf, 0);
    pos.y = get_y(get_x(i, conf, 1), conf);
    return (pos);
}
