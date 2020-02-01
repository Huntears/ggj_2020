#ifndef COMPONENT_H_
#define COMPONENT_H_

#include "libdragon.h"

dg_component_t *cpt_box_collider(float, float, float, float);

int box_collider_test(dg_entity_t *, dg_entity_t *, int *);

dg_component_t *cpt_rigid_body(float, float);

#endif /* !COMPONENT_H_ */
