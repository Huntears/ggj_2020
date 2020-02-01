#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "entity.h"
#include "system.h"
#include "libdragon.h"

static int map[9][10] = {{16, 16, 16, 16, 16, 16, 16, 16, 16, 16},
                        {16, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 16},
                        {16, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 16},
                        {16, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 16},
                        {16, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 16},
                        {16, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 16},
                        {16, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 16},
                        {16, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 16},
                        {16, 16, 16, 16, 16, 16, 16, 16, 16, 16}};

dg_scene_t *scene_game_create(void)
{
    dg_scene_t *scene_game = dg_scene_create();

    dg_scene_add_ent(scene_game, ent_player(0, 0));
    dg_scene_add_ent(scene_game, ent_player(100, 100));

    for (int i = 0; i < 9; i++)
        for (int z = 0; z < 10; z++)
            if (map[i][z])
                dg_scene_add_ent(scene_game, ent_decor(z * 32, i * 32, map[i][z] - 1));

    dg_scene_add_ent(scene_game, dg_ent_camera(0, 0));

    dg_scene_add_sys(scene_game, dg_system_create(&sys_gravity));
    dg_scene_add_sys(scene_game, dg_system_create(&sys_set_pos_sprite));

    dg_scene_add_sys(scene_game, dg_system_create(&dg_sys_animator));
    dg_scene_add_sys(scene_game, dg_system_create(&dg_sys_render));
    dg_scene_add_sys(scene_game, dg_system_create(&system_player_control));
    return scene_game;
}
