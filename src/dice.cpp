#include "../include/dice.h"

dice::FaceType roll() {
    return 1 + (rand() % 7);
}