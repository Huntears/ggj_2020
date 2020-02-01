/*
** Author: Cotax
** ggj_2020
** File description:
** init_component
*/

#include "libdragon.h"
#include <stdlib.h>

void cpt_value_click_destroy(void *ptr)
{
    free(ptr);
}

dg_component_t *cpt_value_on_click(int value)
{
    void (*destroy)(void *) = &cpt_value_click_destroy;
    dg_component_t *cpt = NULL;

    cpt = dg_component_create("click_value", &value, destroy);
    return (cpt);
}