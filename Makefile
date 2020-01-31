SRC	=	main.c		\
		player.c	\

NAME	=	dragon.out

DEBUG	=	dragon.d

all:	$(NAME)

$(NAME):
		make -C lib/dragon/
		gcc -o $(NAME) $(SRC) -Iinclude -L./ -ldragon -lcsfml-graphics -lcsfml-system -lcsfml-window

debug:
		make -C dragon/
		gcc -g3 -o $(DEBUG) $(SRC) -Iinclude -L./ -ldragon -lcsfml-graphics -lcsfml-system -lcsfml-window

clean:
		make clean -C lib/dragon/

fclean:	clean
		make fclean -C lib/dragon/
		-rm $(NAME)
		-rm $(DEBUG)

re:	fclean all
