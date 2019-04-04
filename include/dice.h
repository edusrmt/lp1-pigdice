#ifndef _DICE_H_
#define _DICE_H_

#include <stdlib.h>

namespace dice {
    ///  Dice face type.
    typedef unsigned short FaceType;

    /*!
     *  \brief Rolls n-faced dice.
     *  This function simulares a roll of n-faced dice.
     *  You might simulate a regular 6-sided dice  or a coin toss.
     *
     *
     *  \param n_faces_ Number of dice faces (a integer >0). Default is a 6-sided dice.
     *  \param seed_ Seed used to generate the random event. If nothing is informed, we assume (pseudo) random generation.
     *
     *  \note Providing the same `seed` means we got the same random numbers.
     *
     *  \return The value of one of the n faces, i.e. a value in {0, 1, 2, ..., n-1}.
     */
    FaceType roll( FaceType n_faces_=6 );
}

#endif
