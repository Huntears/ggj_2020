#ifndef RIGID_BODY_H_
#define RIGID_BODY_H_

#include "libdragon.h"

typedef struct rigid_body {
    sfVector2f strengh;
    float gravity;
    float mass;
} rigid_body_t;

rigid_body_t *rb_create(float, float);

void rb_destroy(rigid_body_t *);

#endif /* !RIGID_BODY_H_ */
