#include "../include/dice.h"

namespace dice {

    DiceFace roll() {
        return 1 + (rand() % 7);
    }

    std::string faceToUnicode (DiceFace face) {
        std::string uni;
        
        switch (face)   
        {
            case 1:
            uni = "\u2680";
            break;

            case 2:
            uni = "\u2681";
            break;

            case 3:
            uni = "\u2682";
            break;

            case 4:
            uni = "\u2683";
            break;

            case 5:
            uni = "\u2684";
            break;

            case 6:
            uni = "\u2685";
            break;
        }

        return uni;
    }

}