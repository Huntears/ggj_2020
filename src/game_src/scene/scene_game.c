#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "entity.h"
#include "system.h"
#include "libdragon.h"

dg_scene_t *scene_game_create(void)
{
    dg_scene_t *scene_game = dg_scene_create();

    dg_scene_add_ent(scene_game, ent_player(0, 0));
    dg_scene_add_ent(scene_game, ent_player(100, 100));
    dg_scene_add_ent(scene_game, ent_decor(0, 300));

    dg_scene_add_ent(scene_game, dg_ent_camera(0, 0));

    dg_scene_add_sys(scene_game, dg_system_create(&sys_gravity));
    dg_scene_add_sys(scene_game, dg_system_create(&sys_set_pos_sprite));

    dg_scene_add_sys(scene_game, dg_system_create(&dg_sys_animator));
    dg_scene_add_sys(scene_game, dg_system_create(&dg_sys_render));
    return scene_game;
}
