SHELL	=	bash

SRC 	=	src/game_src/scene/scene_game.c \
			src/game_src/component/cpt_box_collider.c \
			src/game_src/entities/ent_player.c	\
			src/game_src/entities/ent_furret.c	\
			src/game_src/entities/ent_music.c	\
			src/game_src/system/sys_set_pos_sprite.c	\
			src/game_src/component/cpt_rigid_body.c \
			src/game_src/component/cpt_catchable.c \
			src/game_src/component/cpt_music.c \
			src/game_src/system/sys_gravity.c \
			src/game_src/rigid_body.c \
			src/game_src/entities/ent_decor.c	\
			src/game_src/system/sys_player_control.c \
			src/game_src/system/sys_camera_follow_player.c	\
			src/game_src/system/sys_warp_zone.c	\
			src/game_src/scene/scene_past.c	\
			src/game_src/read_csv_from_file.c \
			src/game_src/entities/ent_object.c \
			src/game_src/component/cpt_box_trigger.c \
			src/game_src/component/cpt_entity.c \
			src/game_src/key_is_down.c \
			src/game_src/entities/ent_warp_place.c	\
			src/game_src/component/cpt_roping.c	\
			src/game_src/entities/ent_ladder.c \

OBJ 	=	$(SRC:.c=.o)

MAIN_SRC	=	src/main.c 	\

MAIN_OBJ	=	$(MAIN_SRC:.c=.o)

CFLAGS	=	-I./include -W -Wall -Wextra -Werror -g3

LFLAGS	=	-L./lib -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio -ldragon

TARGET	=	game

#-------------------------------------------------------------------------------

all:	$(TARGET) ## Build the main binary with libs

$(TARGET) : build_lib build

build_lib: ## Compile the libs
	@$(MAKE) -C ./lib/dragon/ --silent
	@cp ./lib/dragon/libdragon.a ./lib/libdragon.a

%.o: %.c ## Compile the objects
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "[\e[1;34mCompiled\e[0m] % 41s\n" $@ | tr ' ' '.'

build: $(OBJ) $(MAIN_OBJ) ## Build the main binary
	@printf "\e[1;32mFinished compiling sources\e[0m\n"
	@$(CC) $(OBJ) $(MAIN_OBJ) -o $(TARGET) $(LFLAGS)
	@printf "[\e[1;33mLinked\e[0m] % 43s\n" $(OBJ) | tr ' ' '.'
	@printf "[\e[1;33mLinked\e[0m] % 43s\n" $(MAIN_OBJ) | tr ' ' '.'
	@printf "\e[1;32mLinked all object files\e[0m\n"

clean_lib: ## Clean the libs
	@$(MAKE) -C ./lib/dragon/ --silent clean

fclean_lib: ## Force clean the libs
	@$(MAKE) -C ./lib/dragon/ --silent fclean
	@rm -f lib/libdragon.a

clean: clean_lib ## Clean the project
	@rm -f $(OBJ) $(MAIN_OBJ)
	@printf "[\e[1;31mRemoved\e[0m] % 42s\n" $(OBJ) | tr ' ' '.'
	@printf "[\e[1;31mRemoved\e[0m] % 42s\n" $(MAIN_OBJ) | tr ' ' '.'
	@printf "\e[1;32mFinished removing objects\e[0m\n"

fclean: fclean_lib clean ## Force clean the project
	@rm -f $(TARGET)
	@printf "[\e[1;31mRemoved\e[0m] % 42s\n" $(TARGET) | tr ' ' '.'
	@printf "\e[1;32mFinished removing linked binaries\e[0m\n"

re:	fclean all ## Force clean then compile

valgrind: all ## Launch valgrind
	@valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

help: ## Help for the Makefile
	@cat $(MAKEFILE_LIST) | sed -En 's/^([a-zA-Z_-]+)\s*:.*##\s?(.*)/\1 "\2"/p' | xargs printf "\033[36m%-30s\033[0m %s\n"

.PHONY:	re fclean clean fclean_lib clean_lib build build_lib all tests_run re_tests help valgrind
