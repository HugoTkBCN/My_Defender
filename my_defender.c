/*
** EPITECH PROJECT, 2019
** my defender
** File description:
** defender
*/

#include "include/my.h"

int destroy_all(all_game_t *all_game)
{
    destroy_images(&all_game->image_tower1);
    destroy_images(&all_game->image_tower2);
    destroy_images(&all_game->image_tower3);
    destroy_images(&all_game->image_tower4);
    destroy_game_object(&all_game->selected);
    destroy_scenes(all_game->scene);
    destroy_music(&all_game->music);
    destroy_fps(&all_game->fps);
    return (0);
}

void draw_scene(scene_t scene, sfRenderWindow *window)
{
    for (int i = 0; i < scene.nbr_objs; i++) {
        sfRenderWindow_drawSprite(window, scene.objs[i].sprite, NULL);
    }
    for (int y = 0; y < scene.nbr_buttons; y++) {
        sfRenderWindow_drawRectangleShape(window, scene.buttons[y].rect, NULL);
    }
}

void add_special_sprites(all_game_t *all_game, en_t *enemy, sfClock **clocks)
{
    sfTime time;

    if (all_game->ret == 0) {
        time = sfClock_getElapsedTime(clocks[0]);
        if (time.microseconds / 1000000.0 > 0.5) {
            move_rect(&all_game->scene[0].objs->rect, WIDTH_WP, LEN_MENU);
            sfSprite_setTextureRect(all_game->scene[0].objs->sprite,
                                    all_game->scene[0].objs->rect);
            sfClock_restart(clocks[0]);
        }
    }
    all_game->ret == 1 ? put_towers(*all_game) : 0;
    all_game->ret == 1 ? put_enemies_and_bullets(all_game, enemy, clocks) : 0;
    all_game->is_selected != 0 && all_game->ret == 1 ?
        sfRenderWindow_drawSprite(all_game->window,
                                    all_game->selected.sprite, NULL) : 0;
    all_game->ret == 3 ? put_top_scores(*all_game) : 0;
}

void put_money(all_game_t *all_game)
{
    static int upgrade = 0;

    all_game->money.money == 0 ? sfText_setString(all_game->money.money_text,
                                                "0") :
        sfText_setString(all_game->money.money_text,
                        int_to_str(all_game->money.money));
    sfRenderWindow_drawText(all_game->window, all_game->money.money_text, NULL);
    all_game->money.money += 2 * all_game->money.speed;
    all_game->money.speed += upgrade >= 250 ? 1 : 0;
    upgrade = upgrade >= 250 ? 0 : upgrade;
}

int run_game(int ac, char **av)
{
    all_game_t all_game = init_all_game(all_game);
    sfClock *clocks[6];
    en_t *enemy = malloc(sizeof(en_t) * MAX_QUANTITY);

    clocks[0] = sfClock_create();
    clocks[1] = sfClock_create();
    clocks[2] = sfClock_create();
    clocks[3] = sfClock_create();
    clocks[4] = sfClock_create();
    clocks[5] = sfClock_create();
    enemy = enemy_initial_values(enemy, QUANTITY);
    enemy = display_enemies(enemy, enemy->quantity);
    while (sfRenderWindow_isOpen(all_game.window)) {
        sfRenderWindow_clear(all_game.window, sfBlack);
        draw_scene(all_game.scene[all_game.ret], all_game.window);
        all_game.ret = analyse_events(&all_game, all_game.scene[all_game.ret]);
        add_special_sprites(&all_game, enemy, clocks);
        sfRenderWindow_display(all_game.window);
    }
    return (destroy_all(&all_game));
}
