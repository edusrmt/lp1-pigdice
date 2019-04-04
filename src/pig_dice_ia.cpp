#include "../include/pig_dice_ia.h"

action_t next_action_ia(const TurnSnapshot &ts) {
    int random = rand() % 10;

    if (random > 6)
        return 0;
    else
        return 1;
}