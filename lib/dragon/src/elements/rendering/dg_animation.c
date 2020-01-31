/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** animation
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "dg_animation.h"

dg_animation_t *dg_animation_create(dg_spritesheet_t *sheet, float speed)
{
    dg_animation_t *animation = malloc(sizeof(dg_animation_t));

    if (!animation)
        return 0;
    animation->sheet = sheet;
    animation->speed = speed;
    animation->frames = 0;
    animation->size = 0;
    return animation;
}

void dg_animation_add(dg_animation_t *animation, int i)
{
    int *new_list = 0;
    if (!(animation->frames)) {
        animation->frames = malloc(sizeof(int));
        animation->frames[0] = i;
        animation->size = 1;
    } else {
        new_list = malloc(sizeof(int) * (animation->size + 1));
        for (int i = 0; i < animation->size; i++)
            new_list[i] = animation->frames[i];
        new_list[animation->size] = i;
        animation->size++;
        free(animation->frames);
        animation->frames = new_list;
    }
}

void dg_animation_update_sprite(
    dg_animation_t *animation,
    sfSprite *sprite,
    int i
    )
{
    dg_spritesheet_t *sheet = animation->sheet;
    int frame = animation->frames[(int)(i % animation->size)];
    dg_spritesheet_to_sprite(sheet, sprite, frame);
}

void dg_animation_free(dg_animation_t *animation)
{
    free(animation);
}
