/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** manage the spritesheet
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "dg_spritesheet.h"

dg_spritesheet_t *dg_spritesheet_create(char *filepath, int x, int y)
{
    dg_spritesheet_t *spritesheet = malloc(sizeof(dg_spritesheet_t));
    sfImage *file = sfImage_createFromFile(filepath);
    sfTexture *sheet = sfTexture_createFromImage(file, 0);

    if (!spritesheet)
        return 0;
    spritesheet->sheet = sheet;
    spritesheet->x = x;
    spritesheet->y = y;
    return spritesheet;
}

void dg_spritesheet_free(dg_spritesheet_t *spritesheet)
{
    sfTexture_destroy(spritesheet->sheet);
    free(spritesheet);
}

void dg_spritesheet_to_sprite(
    dg_spritesheet_t *sheet,
    sfSprite *sprite,
    int id
    )
{
    sfVector2u image_size = sfTexture_getSize(sheet->sheet);
    sfIntRect pos = {0, 0, sheet->x, sheet->y};

    for (int i = 0; i < id; i++) {
        pos.left += sheet->x;
        if (pos.left >= image_size.x) {
            pos.top += sheet->y;
            pos.left = 0;
        }
        if (pos.top >= image_size.y) {
            pos.top = 0;
            pos.left = 0;
        }
    }
    sfSprite_setTexture(sprite, sheet->sheet, id);
    sfSprite_setTextureRect(sprite, pos);
}
