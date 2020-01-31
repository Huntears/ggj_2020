/*
** EPITECH PROJECT, 2019
** libdragon example
** File description:
** player entity and system
*/

#include <stdlib.h>
#include "libdragon.h"
#include "epitech_tools.h"

static dg_animator_t *set_player_animator(void)
{
    dg_animator_t *animator = dg_animator_create();
    dg_spritesheet_t *ss = dg_spritesheet_create("res/bat.png", 32, 32);
    dg_animation_t *down = dg_animation_create(ss, 10);
    dg_animation_t *right = dg_animation_create(ss, 10);
    dg_animation_t *up = dg_animation_create(ss, 10);
    dg_animation_t *left = dg_animation_create(ss, 10);

    dg_animation_add(down, 0);
    dg_animation_add(down, 1);
    dg_animation_add(down, 2);
    dg_animation_add(down, 3);

    dg_animation_add(right, 4);
    dg_animation_add(right, 5);
    dg_animation_add(right, 6);
    dg_animation_add(right, 7);

    dg_animation_add(left, 12);
    dg_animation_add(left, 13);
    dg_animation_add(left, 14);
    dg_animation_add(left, 15);

    dg_animation_add(up, 8);
    dg_animation_add(up, 9);
    dg_animation_add(up, 10);
    dg_animation_add(up, 11);

    dg_animator_add(animator, "down", down);
    dg_animator_add(animator, "right", right);
    dg_animator_add(animator, "up", up);
    dg_animator_add(animator, "left", left);

    return animator;
}

dg_entity_t *entity_player_create()
{
    sfVector2f scale = {5, 5};
    dg_entity_t *player = dg_entity_create("player");

    dg_entity_add_component(player, dg_cpt_sprite(&scale));
    dg_entity_add_component(player, dg_cpt_animator(&set_player_animator));
    return player;
}

void system_player_control(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    sfVector2f move = {0, 0};
    dg_animator_t *animator = (dg_animator_t *)(dg_entity_get_component(entity, "animator"));
    sfSprite *sprite = (sfSprite *)(dg_entity_get_component(entity, "sprite"));

    if (!dg_system_require(entity, 2, "animator", "sprite") || dg_strcmp(entity->name, "player"))
        return;
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        move.x += 1;
        dg_animator_set_animation(animator, "right");
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        move.x -= 1;
        dg_animator_set_animation(animator, "left");
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        move.y += 1;
        dg_animator_set_animation(animator, "down");
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        move.y -= 1;
        dg_animator_set_animation(animator, "up");
    }
    if (sfKeyboard_isKeyPressed(sfKeySpace)) {
        dg_entity_free_component(entity, "sprite");
    }
    sfSprite_move(sprite, move);
}
