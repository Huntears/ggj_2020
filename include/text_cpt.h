/*
** EPITECH PROJECT, 2020
** ggj_2020
** File description:
** text_cpt
*/

#ifndef TEXT_CPT_H_
#define TEXT_CPT_H_

#include <SFML/Graphics.h>

typedef struct text {
    char *string;
    int size;
    sfFont *font;
    sfColor color;
    float thickness;
}text_t;

#endif /* !TEXT_CPT_H_ */
