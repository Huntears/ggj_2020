#ifndef ENTITY_H_
#define ENTITY_H_

#include "libdragon.h"

dg_entity_t *ent_player(int x, int y);
dg_entity_t *ent_decor(int x, int y, int id);
dg_entity_t *ent_object(char *, dg_spritesheet_t *, sfVector2f, sfVector2f);

#endif /* !ENTITY_H_ */
