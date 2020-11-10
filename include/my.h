/*
** EPITECH PROJECT, 2019
** include
** File description:
** exemple
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Audio/Music.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/System/Clock.h>
#include <SFML/Window/Keyboard.h>


#define EXIT_ERROR 84
#define LEN_MENU 10800
#define WIDTH_TOWER 140
#define HEIGHT_TOWER 180
#define WIDTH_WP 1200
#define HEIGHT_WP 1000
#define PATH_TO_SCENE_MENU "jh/menu.jh"
#define PATH_TO_SCENE_GAME "jh/game.jh"
#define PATH_TO_SCENE_HELP "jh/help.jh"
#define PATH_TO_SCENE_SCORE "jh/score.jh"
#define PATH_TO_SCENE_PAUSE "jh/pause.jh"
#define PATH_TO_SCENE_CREDITS "jh/credit.jh"
#define PATH_TO_FILE_TOP_SCORE "top_scores.txt"
#define PATH_TO_FONT "assets/fonts/zombie.ttf"
#define PATH_TO_MUSIC "assets/musics/dash_music.ogg"
#define SELECTED "assets/images/game_assets/button/selected.png"
#define PATH_LVL1 "assets/images/game_assets/tower_lvl1.png"
#define PATH_LVL2 "assets/images/game_assets/tower_lvl2.png"
#define PATH_LVL3 "assets/images/game_assets/tower_lvl3.png"
#define PATH_LVL4 "assets/images/game_assets/tower_lvl4.png"
#define PATH_ZOMBIES "assets/images/enemies/cacerola.png"
#define PATH_SPIDERS "assets/images/enemies/spider.png"
#define PATH_BULLETS "assets/images/bullet.png"
#define POS_BUTTON_LVL1 (sfVector2f){180, 822}
#define POS_BUTTON_LVL2 (sfVector2f){350, 832}
#define POS_BUTTON_LVL3 (sfVector2f){520, 822}
#define POS_BUTTON_LVL4 (sfVector2f){700, 822}
#define MARGE_TOWER_BEFORE (sfVector2f){5, 30}
#define MARGE_TOWER_AFTER (sfVector2f){135, 210}
#define LIM_UPROAD (int[2]){260, 350}
#define LIM_DOROAD (int[2]){525, 590}
#define LIM_WINDOW (int[2]){725, 825}
#define POS_1 280
#define POS_2 590
#define POS_3 755
#define POS_FPS (sfVector2f){125, 150}
#define POS_MONEY (sfVector2f){950, 895}
#define MONEY_100 100
#define MONEY_250 250
#define MONEY_500 500
#define MONEY_1000 1000
#define NBR_SCENES 6
#define NBR_TOWER_MAX 50
#define MAX_QUANTITY 200
#define QUANTITY 5
#define ADD_ENEMIES_WAVE 2
#define SPRITE_LEFT 99
#define SPRITE_LEFT2 130
#define SPRITE_WIDTH 119
#define SPRITE_WIDTH2 100
#define SPRITE_HEIGHT 113
#define SPRITE_HEIGHT2 120
#define HP 1
#define HP2 2
#define SPRITE_LIMIT 203
#define SPRITE_VELOCITY (0.2)
#define SPRITE_SPAWN 111
#define SPRITE_SPAWN_COND 676
#define SPRITE_SPAWN_END 683
#define SPRITE_WALK 121
#define SPRITE_WALK2 99
#define SPRITE_WALK_RESET 883
#define SPRITE_WALK_RESET2 36
#define SPRITE_WALK_COND 1200
#define SPRITE_WALK_COND2 300
#define SPRITE_DEAD_BEGIN 1417
#define SPRITE_DEAD_BEGIN2 391
#define SPRITE_DEAD_WALK2 80
#define SPRITE_DEAD 1900
#define SPRITE_DEAD2 950
#define RANGE_TOWER (int[4]){300, 450, 550, 1000}
#define BULLET_RANGE 50
#define BULLET_SPEED 8
#define SPEED_ATT (float[4]){1.5, 1, 0.8, 0.5}
#define ALIVE 0
#define WALKING_DEAD 1
#define DEAD_ANIMATION 2
#define JUST_DEAD 3
#define RANDOM_POS_MIN (sfVector2f){0, 325}
#define RANDOM_POS_MAX (sfVector2f){25, 420}
#define X_CASTLE 935
#define SPEED_ZOMBIE 2
#define SPEED_SPIDER 7

typedef struct en_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect size;
    int quantity;
    int dead;
    int hp;
    sfVector2f position;
    sfTexture *t_bull;
    sfSprite *s_bull;
    sfVector2f b_pos;
    int speed_x;
    int speed_y;
    int speed_change;
    int attack;
    int type;
    int display;
}en_t;

typedef struct scene_s scene_t;
typedef struct all_game_s all_game_t;

typedef struct top_scores_s {
    char *name;
    int pos;
    int score;
}top_scores_t;

typedef struct music_s {
    sfMusic *music;
    int volume;
    sfText *text;
}music_t;

typedef struct fps_s {
    int fps;
    sfText *text;
}fps_t;

typedef struct button_s {
    sfRectangleShape *rect;
    sfTexture *texture;
    int (*callback)(all_game_t *, scene_t);
} button_t;

typedef struct game_object_s {
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f pos;
    sfSprite *sprite;
} game_object_t;

typedef struct tower_s {
    sfVector2f pos;
    int life;
    int put;
    int range;
    float speed_attack;
} tower_t;

typedef struct image_s {
    sfSprite *sprite;
    sfTexture *texture;
}image_t;

typedef struct scene_s {
    int nbr_objs;
    int nbr_buttons;
    game_object_t *objs;
    button_t *buttons;
} scene_t;

typedef struct money_s {
    int money;
    sfText *money_text;
    int speed;
} money_t;

typedef struct all_game_s {
    sfRenderWindow *window;
    scene_t *scene;
    tower_t *towers_lvl1;
    image_t image_tower1;
    tower_t *towers_lvl2;
    image_t image_tower2;
    tower_t *towers_lvl3;
    image_t image_tower3;
    tower_t *towers_lvl4;
    image_t image_tower4;
    int is_selected;
    game_object_t selected;
    int prev_scene;
    int ret;
    music_t music;
    fps_t fps;
    money_t money;
}all_game_t;

void init_image(image_t *, char *);
tower_t *init_tower(tower_t *);
void put_towers(all_game_t);
void save_towers(sfVector2f, all_game_t *);
int select_tower_lvl1(all_game_t *, scene_t);
int select_tower_lvl2(all_game_t *, scene_t);
int select_tower_lvl3(all_game_t *, scene_t);
int select_tower_lvl4(all_game_t *, scene_t);
void put_top_scores(all_game_t all_game);
void destroy_music(music_t *music);
void destroy_fps(fps_t *fps);
void destroy_scenes(scene_t *scene);
int change_prev_scene(all_game_t *, scene_t);
int change_scene_game(all_game_t *, scene_t);
int change_scene_menu(all_game_t *, scene_t);
int change_scene_help(all_game_t *, scene_t);
int change_scene_scores(all_game_t *, scene_t);
int change_scene_credits(all_game_t *, scene_t);
int change_scene_pause(all_game_t *, scene_t);
int quit_game(all_game_t *, scene_t);
int change_volume(all_game_t *, scene_t);
int change_fps(all_game_t *, scene_t);
int analyse_events(all_game_t *, scene_t);
void move_rect(sfIntRect *, int, int);
scene_t parse_my_file(char *, scene_t );
game_object_t init_game_object(game_object_t *, sfVector2f, char *);
button_t init_button(button_t *, sfVector2f, char *);
void draw_scene(scene_t , sfRenderWindow *);
void free_array(char **);
int button_is_clicked(button_t, sfVector2f);
music_t music_display(music_t music, sfRenderWindow *window);
int settings(music_t *, sfRenderWindow * , sfEvent);
void frame_limit_settings(all_game_t *, sfEvent);
int volume_settings(music_t *, sfRenderWindow *, sfEvent);
sfRenderWindow *open_window(int, int, char *);
void my_putchar(char c);
int my_put_nbr(int nb);
void my_putstr(char const *str);
int my_strlen(char const *);
char *my_strdup(char *src);
char *my_strcpy(char *dest, char *src);
int my_strcmp(char *str1, char *str2);
char *mem_alloc(char const *, char const *);
int str_to_int(char *nbr);
char *int_to_str(int nbr);
char *my_revstr(char *str);
char *get_filepath(char *);
sfVector2f get_pos(char *);
int get_nbr_line(char *filepath);
char **get_config(char *filepath);
int run_game(int, char **);
scene_t *init_buttons_on_scenes_2(scene_t *scene);
scene_t *init_buttons_on_scenes(scene_t *scene);
scene_t *init_scenes(scene_t *scene);
all_game_t init_all_game_2(all_game_t all_game);
all_game_t init_all_game(all_game_t all_game);
void destroy_images(image_t *);
void destroy_game_object(game_object_t *);
en_t *display_enemies(en_t *enemy, int quantity);
void infinite_sprite(en_t *enemy, sfRenderWindow *window, sfClock *clock);
void kill_enemy(tower_t *tower, en_t *enemy, sfRenderWindow *window,
                sfClock *clock);
en_t *enemy_initial_values(en_t *enemy, int quantity);
en_t *enemy_moves(en_t *enemy, sfRenderWindow *window);
en_t *check_dead(en_t *enemy, int i);
en_t *check_dead2(en_t *enemy, int i);
en_t *move_bullet(en_t *enemy, int i);
en_t *move_bullet2(en_t *enemy, int i);
en_t *kill_bullet(tower_t tower, en_t *enemy, sfRenderWindow *window);
void texture_enemy_bullet(en_t *enemy, int i);
void put_enemies_and_bullets(all_game_t *, en_t *, sfClock **);
void put_money(all_game_t *all_game);

#endif /* !MY_H_ */
