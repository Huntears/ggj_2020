#include "libdragon.h"
#include "inventory.h"
#include "string.h"

void sys_crafting(dg_entity_t *entity, dg_window_t *w, dg_array_t **entities, sfTime dt)
{
    dg_entity_t *player = dg_get_entity(*entities, "player");
    inventory_t *inv = (inventory_t *) (dg_entity_get_component(player, "inventory"));

    (void)w;
    (void)dt;
    (void)entity;
    if (!player)
        return;
    if (((!strcmp(inv->left->name, "broken_cog_left") && !strcmp(inv->right->name, "broken_cog_right")) || (!strcmp(inv->left->name, "broken_cog_right") && !strcmp(inv->right->name, "broken_cog_left"))) && sfMouse_isButtonPressed(sfMouseMiddle)) {
        inv->left = 0;
        inv->right = 0;
        return;
    }
}