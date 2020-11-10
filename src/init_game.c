/*
** EPITECH PROJECT, 2019
** init game
** File description:
** defender
*/

#include "../include/my.h"

scene_t *init_buttons_on_scenes_2(scene_t *scene)
{
    scene[4].buttons[1].callback = &change_scene_menu;
    scene[4].buttons[2].callback = &quit_game;
    scene[4].buttons[3].callback = &change_volume;
    scene[4].buttons[4].callback = &change_fps;
    scene[4].buttons[5].callback = &change_scene_help;
    scene[4].buttons[6].callback = &change_scene_credits;
    scene[5].buttons[0].callback = &change_prev_scene;
    return (scene);
}

scene_t *init_buttons_on_scenes(scene_t *scene)
{
    scene[0].buttons[0].callback = &change_scene_game;
    scene[0].buttons[1].callback = &quit_game;
    scene[0].buttons[2].callback = &change_volume;
    scene[0].buttons[3].callback = &change_fps;
    scene[0].buttons[4].callback = &change_scene_help;
    scene[0].buttons[5].callback = &change_scene_scores;
    scene[0].buttons[6].callback = &change_scene_credits;
    scene[1].buttons[0].callback = &change_scene_pause;
    scene[1].buttons[1].callback = &select_tower_lvl1;
    scene[1].buttons[2].callback = &select_tower_lvl2;
    scene[1].buttons[3].callback = &select_tower_lvl3;
    scene[1].buttons[4].callback = &select_tower_lvl4;
    scene[2].buttons[0].callback = &change_prev_scene;
    scene[3].buttons[0].callback = &change_prev_scene;
    scene[4].buttons[0].callback = &change_scene_game;
    scene = init_buttons_on_scenes_2(scene);
    return (scene);
}

scene_t *init_scenes(scene_t *scene)
{
    scene[0] = parse_my_file(PATH_TO_SCENE_MENU, scene[0]);
    scene[1] = parse_my_file(PATH_TO_SCENE_GAME, scene[1]);
    scene[2] = parse_my_file(PATH_TO_SCENE_HELP, scene[2]);
    scene[3] = parse_my_file(PATH_TO_SCENE_SCORE, scene[3]);
    scene[4] = parse_my_file(PATH_TO_SCENE_PAUSE, scene[4]);
    scene[5] = parse_my_file(PATH_TO_SCENE_CREDITS, scene[5]);
    scene[0].objs->rect.top = 0;
    scene[0].objs->rect.left = 0;
    scene[0].objs->rect.width = WIDTH_WP;
    scene[0].objs->rect.height = HEIGHT_WP;
    scene = init_buttons_on_scenes(scene);
    return (scene);
}

all_game_t init_all_game_2(all_game_t all_game)
{
    all_game.scene = malloc(sizeof(scene_t) * NBR_SCENES);
    all_game.ret = 0;
    all_game.scene = init_scenes(all_game.scene);
    all_game.music = music_display(all_game.music, all_game.window);
    all_game.towers_lvl1 = malloc(sizeof(tower_t) * NBR_TOWER_MAX);
    all_game.towers_lvl2 = malloc(sizeof(tower_t) * NBR_TOWER_MAX);
    all_game.towers_lvl3 = malloc(sizeof(tower_t) * NBR_TOWER_MAX);
    all_game.towers_lvl4 = malloc(sizeof(tower_t) * NBR_TOWER_MAX);
    all_game.towers_lvl1 = init_tower(all_game.towers_lvl1);
    init_image(&all_game.image_tower1, PATH_LVL1);
    all_game.towers_lvl2 = init_tower(all_game.towers_lvl2);
    init_image(&all_game.image_tower2, PATH_LVL2);
    all_game.towers_lvl3 = init_tower(all_game.towers_lvl3);
    init_image(&all_game.image_tower3, PATH_LVL3);
    all_game.towers_lvl4 = init_tower(all_game.towers_lvl4);
    init_image(&all_game.image_tower4, PATH_LVL4);
    sfRenderWindow_setFramerateLimit(all_game.window, all_game.fps.fps);
    return (all_game);
}

all_game_t init_all_game(all_game_t all_game)
{
    sfFont *font = sfFont_createFromFile(PATH_TO_FONT);

    all_game.window = open_window(WIDTH_WP, HEIGHT_WP, "Zombie Defender");
    all_game.is_selected = 0;
    all_game.selected = init_game_object(&all_game.selected, POS_FPS, SELECTED);
    all_game.fps.fps = 25;
    all_game.fps.text = sfText_create();
    sfText_setFont(all_game.fps.text, font);
    sfText_setCharacterSize(all_game.fps.text, 30);
    sfText_setColor(all_game.fps.text, sfWhite);
    sfText_setPosition(all_game.fps.text, POS_FPS);
    all_game.money.money = 300;
    all_game.money.speed = 1;
    all_game.money.money_text = sfText_create();
    sfText_setFont(all_game.money.money_text, font);
    sfText_setCharacterSize(all_game.money.money_text, 30);
    sfText_setColor(all_game.money.money_text, sfBlack);
    sfText_setPosition(all_game.money.money_text, POS_MONEY);
    return (all_game = init_all_game_2(all_game));
}
