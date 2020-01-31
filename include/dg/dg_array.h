/*
** EPITECH PROJECT, 2020
** libdragon
** File description:
** include all array functions
*/

#ifndef DG_ARRAY_H_
#define DG_ARRAY_H_

typedef struct dg_array {
    void *data;
    struct dg_array *next;
    struct dg_array *previous;
} dg_array_t;

void dg_arr_add_end(dg_array_t **, void *);

void dg_arr_add_begin(dg_array_t **, void *);

void dg_arr_add_at(dg_array_t **, void *, int);

void dg_arr_add_node_end(dg_array_t **, dg_array_t *);

void dg_arr_add_node_begin(dg_array_t **, dg_array_t *);

void dg_arr_add_node_at(dg_array_t **, dg_array_t *, int);

void *dg_arr_remove_at(dg_array_t **, int);

void *dg_arr_remove_end(dg_array_t **);

void *dg_arr_remove_begin(dg_array_t **);

dg_array_t *dg_arr_pop_end(dg_array_t **);

dg_array_t *dg_arr_pop_begin(dg_array_t **);

dg_array_t *dg_arr_pop_at(dg_array_t **, int);

void dg_arr_free_all(dg_array_t **);

void dg_arr_transfer_b_to_b(dg_array_t **, dg_array_t **);

void dg_arr_transfer_b_to_e(dg_array_t **, dg_array_t **);

void dg_arr_transfer_e_to_b(dg_array_t **, dg_array_t **);

void dg_arr_transfer_e_to_e(dg_array_t **, dg_array_t **);

void dg_arr_itransfer_b_to_e(dg_array_t **);

void dg_arr_itransfer_e_to_b(dg_array_t **);

void dg_arr_itransfer_at(dg_array_t **, int, int);

void dg_arr_transfer_at(dg_array_t **, int, dg_array_t **, int);

void dg_arr_swap_b_to_b(dg_array_t **, dg_array_t **);

void dg_arr_swap_b_to_e(dg_array_t **, dg_array_t **);

void dg_arr_swap_e_to_b(dg_array_t **, dg_array_t **);

void dg_arr_swap_e_to_e(dg_array_t **, dg_array_t **);

void dg_arr_iswap_extreme(dg_array_t **);

void dg_arr_iswap_at(dg_array_t **, int, int);

void dg_arr_swap_at(dg_array_t **, int, dg_array_t **, int);

void *dg_arr_get_data(dg_array_t *, int);

dg_array_t *dg_arr_get(dg_array_t *, int);

int dg_arr_get_size(dg_array_t *);

void dg_arr_merge(dg_array_t **, dg_array_t **);

void dg_arr_merge_at(dg_array_t **, dg_array_t **, int);

#endif /*DG_ARRAY_H*/
