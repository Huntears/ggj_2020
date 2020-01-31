/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** dg_component
*/

#include <stdlib.h>
#include "dg_component.h"

dg_component_t *dg_component_create(char *name, void *data,
    dg_cpt_destroy_t cff)
{
    dg_component_t *component = malloc(sizeof(dg_component_t));

    if (!component)
        return 0;
    component->name = name;
    component->data = data;
    component->on_destroy = cff;
    return component;
}

void dg_component_destroy(dg_component_t *component)
{
    if (!component)
        return;
    component->on_destroy(component->data);
    free(component);
}
