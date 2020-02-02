##
## EPITECH PROJECT, 2019
## libDragon
## File description:
## Install the lib
##

SRC_SKL	=		src/dragon.c									\
				src/dg_window.c									\

SRC_EPI =		src/epi_tools/dep_tools.c						\

SRC_LIST =		src/array/dg_arr.c								\
				src/array/dg_arr_free.c							\
				src/array/dg_arr_pop.c							\
				src/array/dg_arr_swap.c							\
				src/array/dg_arr_add_node.c						\
				src/array/dg_arr_transfer.c						\
				src/array/dg_arr_iswap.c						\
				src/array/dg_arr_rotate.c						\
				src/array/dg_arr_get_length.c					\
				src/array/dg_arr_merge.c						\

SRC_FMB =		src/elements/framebuffer/dg_framebuffer.c		\
				src/elements/framebuffer/dg_fb_putpx.c			\
				src/elements/framebuffer/dg_fb_putline.c		\
				src/elements/framebuffer/dg_fb_putcircle.c		\
				src/elements/framebuffer/dg_fb_putrectangle.c	\

SRC_MATH =		src/mathematics/dg_square.c 					\
				src/mathematics/dg_abs.c 						\
				src/mathematics/dg_pow.c						\
				src/mathematics/dg_square.c						\
				src/mathematics/dg_trigo.c						\
				src/mathematics/dg_arc_trigo.c					\

SRC_RD =		src/elements/rendering/dg_spritesheet.c			\
				src/elements/rendering/dg_animation.c			\
				src/elements/rendering/dg_animator.c			\

SRC_ECS_STC =	src/ecs/struct/dg_component.c					\
				src/ecs/struct/dg_entity.c						\
				src/ecs/struct/dg_system.c						\
				src/ecs/struct/dg_scene.c						\

SRC_ECS_S =		src/ecs/systems/dg_sys_animator.c				\
				src/ecs/systems/dg_sys_render.c					\

SRC_ECS_C =		src/ecs/components/dg_cpt_animator.c			\
				src/ecs/components/dg_cpt_sprite.c				\
				src/ecs/components/dg_cpt_pos.c					\

SRC_ECS_E =		src/ecs/entities/dg_ent_camera.c				\

SRC_ALL =	$(SRC_SKL)		\
			$(SRC_EPI)		\
			$(SRC_FMB)		\
			$(SRC_MATH)		\
			$(SRC_RD)		\
			$(SRC_ECS_STC)	\
			$(SRC_ECS_S)	\
			$(SRC_LIST)		\
			$(SRC_ECS_C)	\
			$(SRC_ECS_E)	\

OBJ	=	$(SRC_ALL:.c=.o)

INC_PATH = $(strip ../../include/)

INC =	$(INC_PATH)libdragon.h		\

CFLAGS =	-Iinclude

NAME	= libdragon.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	-rm -f $(OBJ)

fclean: clean
	-rm -f $(NAME)
