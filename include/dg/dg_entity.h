/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** define the dg_entity struct
*/

#ifndef DG_ENTITY_H_
#define DG_ENTITY_H_

#include "dg_component.h"
#include "dg_array.h"

typedef struct dg_entity
{
    char *name;
    dg_array_t *components;
} dg_entity_t;

dg_entity_t *dg_entity_create(char *);

void dg_entity_destroy(dg_entity_t *);

void dg_entity_add_component(dg_entity_t *, dg_component_t *);

int dg_entity_has_component(dg_entity_t *, char *);

void *dg_entity_get_component(dg_entity_t *, char *);

dg_component_t *dg_entity_rm_component(dg_entity_t *, char *);

void dg_entity_free_component(dg_entity_t *, char *);

dg_entity_t *dg_ent_camera(int, int);

#endif /*DG_ENTITY_H*/
