/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** define the dg_component struct
*/

#ifndef DG_COMPONENT_H_
#define DG_COMPONENT_H_

typedef void (*dg_cpt_destroy_t)(void *);

typedef struct dg_component
{
    char *name;
    void *data;
    dg_cpt_destroy_t on_destroy;
} dg_component_t;

dg_component_t *dg_component_create(char *, void *, dg_cpt_destroy_t);

void dg_component_destroy(dg_component_t *);

#endif /*DG_COMPONENT_H*/
