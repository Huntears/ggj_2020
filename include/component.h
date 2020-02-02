#ifndef COMPONENT_H_
#define COMPONENT_H_

#include "libdragon.h"

dg_component_t *cpt_box_collider(float, float, float, float);

int box_collider_test(dg_entity_t *, dg_entity_t *, int *);

dg_component_t *cpt_box_trigger(float, float, float, float);

int box_trigger_point(sfVector2f, dg_entity_t *);

int box_trigger_box(dg_entity_t *, dg_entity_t *);

dg_component_t *cpt_rigid_body(float, float);

dg_component_t *cpt_catchable(void);

dg_component_t *cpt_inventory(void);

dg_component_t *cpt_music(char *path);

dg_component_t *cpt_roping(int size);

#endif /* !COMPONENT_H_ */
