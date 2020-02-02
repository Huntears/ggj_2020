#include <SFML/Audio.h>
#include <stdlib.h>
#include "libdragon.h"

static void component_music_destroy(void *data)
{
    sfMusic *music = (sfMusic *)(data);

    sfMusic_destroy(music);
}

dg_component_t *cpt_music(char *path)
{
    void (*destroy)(void *) = &component_music_destroy;
    sfMusic *music = sfMusic_createFromFile(path);

    sfMusic_setLoop (music, 1);
    dg_component_t *component = dg_component_create("music", music, destroy);

    sfMusic_play(music);
    return component;
}