#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "entity.h"
#include "system.h"
#include "libdragon.h"

int **read_csv_from_file(char *filepath);

dg_scene_t *scene_game_create(void)
{
    dg_scene_t *scene_game = dg_scene_create("game");
    int **map = read_csv_from_file("map/map_present.csv");
    dg_spritesheet_t *ss = dg_spritesheet_create("res/tileset01.png", 32, 32);

    if (!map)
        return (NULL);
    dg_scene_add_ent(scene_game, ent_object("star", dg_spritesheet_create("res/time_light.png", 32, 32), (sfVector2f){100,150}, (sfVector2f) {32, 32}));
    dg_scene_add_ent(scene_game, ent_player(100, 100));
    dg_scene_add_ent(scene_game, ent_warp_place(500, 500));

    for (int i = 0; map[i][0] != -3; i++)
        for (int z = 0; map[i][z] != -2; z++)
            if (map[i][z] >= 0)
                dg_scene_add_ent(scene_game, ent_decor(z * 32 * 2, i * 32 * 2, map[i][z], ss));

    dg_scene_add_ent(scene_game, dg_ent_camera(0, 0));

    dg_scene_add_sys(scene_game, dg_system_create(&sys_gravity));
    dg_scene_add_sys(scene_game, dg_system_create(&sys_set_pos_sprite));
    dg_scene_add_sys(scene_game, dg_system_create(&sys_camera_follow_player));
    dg_scene_add_sys(scene_game, dg_system_create(&sys_warp_zone));

    dg_scene_add_sys(scene_game, dg_system_create(&dg_sys_animator));
    dg_scene_add_sys(scene_game, dg_system_create(&dg_sys_render));
    dg_scene_add_sys(scene_game, dg_system_create(&system_player_control));
    return scene_game;
}
