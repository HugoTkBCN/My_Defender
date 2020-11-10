##
## EPITECH PROJECT, 2018
## makefile
## File description:
## .o
##

SRC	=	my_defender.c	\
		utils/my_putchar.c	\
		utils/my_putstr.c	\
		utils/my_put_nbr.c	\
		utils/my_revstr.c	\
		utils/my_strcmp.c	\
		utils/convert.c	\
		utils/my_strlen.c	\
		utils/open_window.c	\
		utils/my_strdup.c	\
		utils/mem_alloc.c	\
		utils/my_strcpy.c	\
		src/bullet_actions.c	\
		src/check_dead.c	\
		src/display_enemies.c	\
		src/enemy_moves.c	\
		src/infinite_sprite.c	\
		src/kill_enemy.c	\
		src/action_button.c	\
		src/action_button_2.c	\
		src/animation.c	\
		src/event.c	\
		src/frame_limit_settings.c	\
		src/parse/get_for_parse.c	\
		src/parse/init_scene.c	\
		src/init_enemy.c	\
		src/parse/parse.c	\
		src/get_put_save_score.c	\
		src/select_init_tower.c	\
		src/put_tower.c	\
		src/save_towers.c	\
		src/init_images.c	\
		src/init_game.c	\
		src/destroy.c	\
		src/destroy_scenes.c	\
		src/put_enemies_and_bullets.c	\
		src/volume_settings.c

NAME	=	my_defender

OBJ	=	$(SRC:.c=.o)

FLAGS =	-Wall -Werror

LIB = -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) main.c $(OBJ) $(LIB) $(FALGS)

clean:
	rm -rf $(OBJ)
fclean:		clean
	rm -rf $(NAME)

re:	fclean all
