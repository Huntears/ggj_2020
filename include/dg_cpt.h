/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** define all the preset components
*/

#ifndef DG_CPT_H_
#define DG_CPT_H_

#include "dg_component.h"

dg_component_t *dg_cpt_sprite(sfVector2f *);

dg_component_t *dg_cpt_animator(dg_animator_t *(*)(void));

dg_component_t *dg_cpt_pos(int, int);

#endif /*DG_CPT_H*/
