#include "../include/pig_dice_ia.h"
#include <iostream>

action_t next_action_ia(const TurnSnapshot &ts) {
    bool roll = false;

    if(ts.myPoints < ts.opponentPoints) { //Perdendo 
        int difference = ts.opponentPoints - ts.myPoints;
        if(difference > 30) {
            roll = ts.turnRolls < 4;
            roll = roll || (ts.turnTotal < 16 && ts.turnRolls < 5);
        } else if(difference > 15) {
            roll = ts.turnRolls < 3;
            roll = roll || (ts.turnTotal < 15 && ts.turnRolls < 4);
        } else {
            roll = ts.turnRolls < 3;
            roll = roll || (ts.turnTotal < 8 && ts.turnRolls < 4);
        }
    } else if(ts.myPoints > ts.opponentPoints) { //Ganhando
        int difference = ts.myPoints - ts.opponentPoints;
        if(difference > 30) {
            roll = ts.turnRolls < 2;
        } else if(difference > 15) {
            roll = ts.turnRolls < 2 || ts.turnTotal < 5;
        } else {
            roll = ts.turnRolls < 3 || ts.turnTotal < 6;
        }
    } else { //Empatando
        roll = ts.turnRolls < 3;
        roll = roll || (ts.turnRolls < 4 && ts.turnTotal < 10);
    }

    if(roll) {
        return 0;
    } else {
        return 1;
    }
}