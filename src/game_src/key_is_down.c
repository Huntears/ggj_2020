#include "libdragon.h"

int key_is_down_left_mouse(void)
{
    static int stat = 0;

    if (!sfMouse_isButtonPressed(sfMouseLeft))
        stat = 0;
    else if (stat == 0) {
        stat = 1;
        return 1;
    }
    return 0;
}

int key_is_down_right_mouse(void)
{
    static int stat = 0;

    if (!sfMouse_isButtonPressed(sfMouseRight))
        stat = 0;
    else if (stat == 0) {
        stat = 1;
        return 1;
    }
    return 0;
}
