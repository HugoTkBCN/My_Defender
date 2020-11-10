/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** defender
*/

#include "include/my.h"

void free_array(char **array)
{
    int i = 0;

    for (i = 0; array[i] != NULL; i++) {
    }
    for (i = i - 1; i >= 0; i--) {
        free(array[i]);
    }
}

int is_display(char **envp)
{
    for (int i = 0; envp[i]; i++) {
        if (envp[i][0] == 'D' && envp[i][1] == 'I')
            return (1);
    }
    return (0);
}

int main(int ac, char **av, char **env)
{
    int ret = 0;

    if (env[0] && is_display(env) == 1)
        ret = run_game(ac, av);
    else
        return (EXIT_ERROR);
    return (ret);
}
