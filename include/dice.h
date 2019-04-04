#ifndef _DICE_H_
#define _DICE_H_

#include <stdlib.h>
#include <iostream>
#include <string>

namespace dice {
    ///  Dice face type.
    typedef unsigned short DiceFace;

    /*!
     *  \brief Rolls 6-faced dice.
     *  This function simulares a roll of 6-faced dice.
     *
     *  \return The value of one of the 6 faces, i.e. a value in {1, 2, 3, 4, 5, 6}.
     */
    DiceFace roll();
    std::string faceToUnicode (DiceFace face);
}

#endif
