#include <stdio.h>
#include "libdragon.h"
#include "inventory.h"
#include "string.h"
#include "entity.h"

void sys_crafting(dg_entity_t *entity, dg_window_t *w, dg_array_t **entities, sfTime dt)
{
    dg_entity_t *player = dg_get_entity(*entities, "player");
    inventory_t *inv = (inventory_t *) (dg_entity_get_component(player, "inventory"));

    (void)w;
    (void)dt;
    (void)entity;
    if (!player || !inv || !inv->left || !inv->right)
        return;
    if (((!strcmp(inv->left->name, "broken_cog_left") && !strcmp(inv->right->name, "broken_cog_right")) || (!strcmp(inv->left->name, "broken_cog_right") && !strcmp(inv->right->name, "broken_cog_left"))) && sfMouse_isButtonPressed(sfMouseMiddle)) {
        inv->left = ent_object("cog", dg_spritesheet_create("./res/cog.png", 32, 32), (sfVector2f) {0, 0}, (sfVector2f) {64, 64});
        inv->right = 0;
        return;
    }
}