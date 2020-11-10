/*
** EPITECH PROJECT, 2019
** parse
** File description:
** defender
*/

#include "../../include/my.h"

int get_nbr_obj_button(char **conf, int type)
{
    char *tmp = "";
    char letter[2];
    int nbr_objs = 0;
    int nbr_buttons = 0;

    for (int i = 0; conf[i]; i++) {
        for (int y = 0; conf[i][y] != ':'; y++) {
            letter[0] = conf[i][y];
            tmp = mem_alloc(tmp, letter);
        }
        if (my_strcmp(tmp, "Background") == 1)
            nbr_objs += 1;
        else if (my_strcmp(tmp, "Button") == 1)
            nbr_buttons += 1;
    }
    if (type == 1)
        return (nbr_objs);
    else if (type == 2)
        return (nbr_buttons);
}

char **get_config(char *filepath)
{
    char **conf = malloc(sizeof(char *) * (get_nbr_line(filepath) + 1));
    int i = 0;
    size_t size = 0;
    char *s = NULL;
    FILE *fd = fopen(filepath, "r");

    if (conf == NULL)
        return (NULL);
    for (i = 0; getline(&s, &size, fd) != EOF; i++) {
        conf[i] = my_strdup(s);
    }
    free(s);
    fclose(fd);
    conf[i] = NULL;
    return (conf);
}

scene_t init_fonction(scene_t scene, char **conf)
{
    scene.objs = malloc(sizeof(game_object_t) *
                        (get_nbr_obj_button(conf, 1) + 2));
    scene.buttons = malloc(sizeof(button_t) *
                            (get_nbr_obj_button(conf, 2) + 2));
    scene.nbr_objs = 0;
    scene.nbr_buttons = 0;
    return (scene);
}

char *get_type(int i, char **conf)
{
    char *type = "";
    char letter[2];
    int y = 0;

    for (y = 0; conf[i][y] != ':'; y++) {
        letter[0] = conf[i][y];
        letter[1] = '\0';
        type = mem_alloc(type, letter);
    }
    type[y] = '\0';
    return (type);
}

scene_t parse_my_file(char *filepath, scene_t scene)
{
    char **conf = get_config(filepath);
    char *type = NULL;
    int c = 0;
    int t = 0;

    scene = init_fonction(scene, conf);
    for (int i = 0; conf[i]; i++) {
        type = get_type(i, conf);
        if (my_strcmp(type, "Background") == 1) {
            scene.nbr_objs += 1;
            scene.objs[c] = init_game_object(&scene.objs[c++],
                            get_pos(conf[i]), get_filepath(conf[i]));
        } else if (my_strcmp(type, "Button") == 1) {
            scene.nbr_buttons += 1;
            scene.buttons[t] = init_button(&scene.buttons[t++],
                                get_pos(conf[i]), get_filepath(conf[i]));
        }
    }
    return (scene);
}
