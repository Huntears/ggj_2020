SHELL	=	bash

SRC 	=	src/game_src/scene/scene_game.c \
			src/game_src/component/cpt_box_collider.c \
			src/game_src/entities/ent_player.c	\
			src/game_src/systems/sys_set_pos_sprite.c	\

OBJ 	=	$(SRC:.c=.o)

MAIN_SRC	=	src/main.c 	\

MAIN_OBJ	=	$(MAIN_SRC:.c=.o)

CFLAGS	=	-I./include -Wall -Wextra -Werror

LFLAGS	=	-L./lib -lcsfml-graphics -lcsfml-system -ldragon

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
