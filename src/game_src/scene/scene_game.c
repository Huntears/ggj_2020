#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libdragon.h"

dg_scene_t *scene_game_create(void)
{
    dg_scene_t *scene_game = dg_scene_create();
    int **map = read_csv_from_file("text.tmp");

    dg_scene_add_ent(scene_game, ent_player(100, 100));

    for (int i = 0; map[i][0] != -2; i++)
        for (int z = 0; map[i][z] != -1; z++)
            if (map[i][z])
                dg_scene_add_ent(scene_game, ent_decor(z * 32 * 5, i * 32 * 5, map[i][z] - 1));

    dg_scene_add_ent(scene_game, dg_ent_camera(0, 0));
    dg_scene_add_sys(scene_game, dg_system_create(&dg_sys_animator));
    dg_scene_add_sys(scene_game, dg_system_create(&dg_sys_render));
    return scene_game;
}
