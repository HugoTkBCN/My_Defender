/*
** EPITECH PROJECT, 2019
** get put and sav the score
** File description:
** defender
*/

#include "../include/my.h"

char *get_name(char *s)
{
    char *name = "";
    char tmp[2];
    int i;

    for (i = 2; s[i] != '/'; i++) {
        tmp[0] = s[i];
        tmp[1] = '\0';
        name = mem_alloc(name, tmp);
    }
    name[i - 2] = '\0';
    return (name);
}

int get_score(char *s)
{
    int i;
    char *score = "";
    char tmp[2];

    for (i = 2; s[i] != '/'; i++) {
    }
    for (i = i + 1; s[i]; i++) {
        tmp[0] = s[i];
        tmp[1] = '\0';
        score = mem_alloc(score, tmp);
    }
    score[my_strlen(score) - 1] = '\0';
    return (str_to_int(score));
}

top_scores_t *get_top_scores(void)
{
    FILE *fd = fopen(PATH_TO_FILE_TOP_SCORE, "r");
    char *s = NULL;
    size_t n = 0;
    top_scores_t *top_scores = malloc(sizeof(top_scores_t) * 5);

    if (fd == NULL)
        return (NULL);
    getline(&s, &n, fd);
    for (int i = 0; i < 5; i++) {
        top_scores[i].pos = s[0] - 48;
        top_scores[i].name = get_name(s);
        top_scores[i].score = get_score(s);
        getline(&s, &n, fd);
    }
    return (top_scores);
}

void draw_scores(all_game_t all_game, sfText *text, sfVector2f pos,
                top_scores_t *top_scores)
{
    for (int i = 0; i < 5; i++) {
        sfText_setString(text, top_scores[i].name);
        sfText_setPosition(text, pos);
        sfRenderWindow_drawText(all_game.window, text, NULL);
        pos.x = 900;
        top_scores[i].score == 0 ? sfText_setString(text, "0") :
            sfText_setString(text, int_to_str(top_scores[i].score));
        sfText_setPosition(text, pos);
        sfRenderWindow_drawText(all_game.window, text, NULL);
        pos.y += 115;
        pos.x = 350;
    }
}

void put_top_scores(all_game_t all_game)
{
    top_scores_t *top_scores = get_top_scores();
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(PATH_TO_FONT);
    sfVector2f pos = {350, 375};

    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    sfText_setColor(text, sfWhite);
    draw_scores(all_game, text, pos, top_scores);
    sfText_destroy(text);
    sfFont_destroy(font);
}
