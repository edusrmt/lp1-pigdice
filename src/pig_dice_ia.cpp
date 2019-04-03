#include "../include/pig_dice_ia.h"

action_t next_action_ia(const TurnSnapshot &ts) {
    return rand() % 2;
}