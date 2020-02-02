#ifndef SYSTEM_H_
#define SYSTEM_H_

#include "libdragon.h"

void sys_set_pos_sprite(dg_entity_t *entity, dg_window_t *w, dg_array_t **entities, sfTime dt);
void sys_gravity(dg_entity_t *, dg_window_t *, dg_array_t **, sfTime);
void system_player_control(dg_entity_t *entity, dg_window_t *w, dg_array_t **entities, sfTime dt);
void sys_camera_follow_player(dg_entity_t *entity, dg_window_t *w, dg_array_t **entities, sfTime dt);
void sys_warp_zone(dg_entity_t *entity, dg_window_t *w, dg_array_t **entities, sfTime dt);
void sys_crafting(dg_entity_t *entity, dg_window_t *w, dg_array_t **entities, sfTime dt);

#endif /* !SYSTEM_H_ */
