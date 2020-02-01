//Auteur : Alexia
//gravity

#include <stdlib.h>
#include <stdio.h>
#include "libdragon.h"
#include "rigid_body.h"

rigid_body_t *rb_create(float gravity, float mass)
{
    rigid_body_t *rb = malloc(sizeof(rigid_body_t));

    if (!rb) {
        dprintf(2, "Error: rigid body not created.\n");
        return 0;
    }
    rb->strengh = (sfVector2f){0};
    rb->gravity = gravity;
    rb->mass = mass;
    return rb;
}

void rb_destroy(rigid_body_t *rb)
{
    free(rb);
}
