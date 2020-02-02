#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "entity.h"
#include "system.h"
#include "libdragon.h"

int **read_csv_from_file(char *filepath);

dg_scene_t *scene_level01_present(void)
{
    dg_scene_t *scene_game = dg_scene_create("game");
    int **map = read_csv_from_file("map/level01_present.csv");
    dg_spritesheet_t *ss = dg_spritesheet_create("res/tileset01.png", 32, 32);
    dg_spritesheet_t *cog_left = dg_spritesheet_create("./res/cog_left.png", 32, 32);
    dg_spritesheet_t *cog_right = dg_spritesheet_create("./res/cog_right.png", 32, 32);
    //dg_spritesheet_t *crate = dg_spritesheet_create("./res/box.png", 32, 32);
    //dg_spritesheet_t *key = dg_spritesheet_create("./res/key.png", 32, 32);
    //dg_spritesheet_t *door = dg_spritesheet_create("./res/door.png", 32, 64);
    //dg_spritesheet_t *ss_lader = dg_spritesheet_create("res/broken_ladder.png", 32, 32);

    if (!map)
        return (NULL);

    dg_scene_add_ent(scene_game, ent_player(1000, 1000));
    dg_scene_add_ent(scene_game, dg_ent_camera(0, 0));

        //Add entities here

    dg_scene_add_ent(scene_game, ent_warp_place(3342, 1344));

    dg_scene_add_ent(scene_game, ent_object("broken_cog_right", cog_right, (sfVector2f) {3520, 1344}, (sfVector2f) {32, 32}));
    dg_scene_add_ent(scene_game, ent_object("broken_cog_left", cog_left, (sfVector2f) {767, 512}, (sfVector2f) {32, 32}));
    dg_scene_add_ent(scene_game, ent_machine((sfVector2f) {3200, 1344}));

    //...

    for (int i = 0; map[i][0] != -3; i++)
        for (int z = 0; map[i][z] != -2; z++)
            if (map[i][z] >= 0)
                dg_scene_add_ent(scene_game, ent_decor(z * 32 * 2, i * 32 * 2, map[i][z], ss));
    for (int i = 0; map[i][0] != -3; i++) {
            free(map[i]);
    }
    free(map);

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
