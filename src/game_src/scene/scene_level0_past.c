#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "entity.h"
#include "system.h"
#include "libdragon.h"

int **read_csv_from_file(char *filepath);

dg_scene_t *scene_level0_past(void)
{
    dg_scene_t *scene_game = dg_scene_create("past");
    int **map = read_csv_from_file("map/level0_past.csv");
    dg_spritesheet_t *ss = dg_spritesheet_create("res/tileset01.png", 32, 32);
    //dg_spritesheet_t *cog_left = dg_spritesheet_create("./res/cog_left.png", 32, 32);
    //dg_spritesheet_t *cog_right = dg_spritesheet_create("./res/cog_right.png", 32, 32);
    //dg_spritesheet_t *crate = dg_spritesheet_create("./res/box.png", 32, 32);
    dg_spritesheet_t *door = dg_spritesheet_create("./res/door.png", 32, 64);
    dg_spritesheet_t *key = dg_spritesheet_create("./res/key.png", 32, 32);
    dg_spritesheet_t *plank = dg_spritesheet_create("res/plank.png", 32, 32);
    dg_spritesheet_t *ss_lader = dg_spritesheet_create("res/ladder.png", 32, 32);

    if (!map)
        return (NULL);
    dg_scene_add_ent(scene_game, ent_player(200, 100));
    dg_scene_add_ent(scene_game, dg_ent_camera(0, 0));

    //Add entities here

    dg_scene_add_ent(scene_game, ent_warp_place(1193, 1300));
    dg_scene_add_ent(scene_game, ent_warp_place(2108, 1170));
    dg_scene_add_ent(scene_game, ent_warp_place(4690, 1088));
    dg_scene_add_ent(scene_game, ent_ladder(1706, 1000, 10, ss_lader));
    dg_scene_add_ent(scene_game, ent_object("key", key, (sfVector2f) {1861, 896}, (sfVector2f) {32, 32}));
    dg_scene_add_ent(scene_game, ent_object("plank", plank, (sfVector2f) {2827, 1300}, (sfVector2f) {32, 32}));
    dg_scene_add_ent(scene_game, ent_object("plank", plank, (sfVector2f) {4027, 1300}, (sfVector2f) {32, 32}));
    dg_scene_add_ent(scene_game, ent_door((sfVector2f) {2052, 1280}, door));

    //...

    for (int i = 0; map[i][0] != -3; i++)
        for (int z = 0; map[i][z] != -2; z++)
            if (map[i][z] >= 0)
                dg_scene_add_ent(scene_game, ent_decor(z * 32 * 2, i * 32 * 2, map[i][z], ss));

    dg_scene_add_sys(scene_game, dg_system_create(&sys_win));
    dg_scene_add_sys(scene_game, dg_system_create(&sys_gravity));
    dg_scene_add_sys(scene_game, dg_system_create(&sys_set_pos_sprite));
    dg_scene_add_sys(scene_game, dg_system_create(&sys_warp_zone));
    dg_scene_add_sys(scene_game, dg_system_create(&sys_camera_follow_player));
    dg_scene_add_sys(scene_game, dg_system_create(&sys_crafting));
    dg_scene_add_sys(scene_game, dg_system_create(&dg_sys_animator));
    dg_scene_add_sys(scene_game, dg_system_create(&dg_sys_render));
    dg_scene_add_sys(scene_game, dg_system_create(&system_player_control));
    return scene_game;
}
