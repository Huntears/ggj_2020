#ifndef INVENTORY_H_
#define INVENTORY_H_

#include <SFML/Graphics.h>
#include "libdragon.h"

typedef struct inventory
{
    dg_entity_t *left;
    dg_entity_t *right;
} inventory_t;

#endif /*INVENTOORY_H*/
