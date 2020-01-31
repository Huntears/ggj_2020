/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** dg_system
*/

#include <stdlib.h>
#include <stdarg.h>
#include "dg_system.h"

dg_system_t *dg_system_create(dg_sysf_t action)
{
    dg_system_t *system = 0;

    if (!action)
        return 0;
    system = malloc(sizeof(dg_system_t));
    if (!system)
        return 0;
    system->system = action;
    return system;
}

void dg_system_destroy(dg_system_t *system)
{
    free(system);
}

int dg_system_require(dg_entity_t *entity, unsigned int len, ...)
{
    va_list arg;
    unsigned int test = 0;

    va_start(arg, len);
    for (int i = 0; i < len; i++) {
        if (dg_entity_has_component(entity, va_arg(arg, char *)) >= 0)
            test++;
    }
    if (test == len)
        return 1;
    return 0;
}
