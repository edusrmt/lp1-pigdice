#include "../include/pig_dice_ia.h"
#include <iostream>

int myTurnRolls = 0;
const Player *opponent = nullptr;
const Player *me = nullptr;

action_t next_action_ia(const TurnSnapshot &ts, const GameState &gst) {
    bool roll = false;

    if(opponent == nullptr || me == nullptr) {
        opponent = &(gst.players[0]);
        me = &(gst.players[1]);
    }
    
    int myPoints = me->score;
    int opponentPoints = opponent->score;
    
    int myTurnPoints = ts.turnTotal;

    if(myTurnPoints - 100 >= 0) return 1;

    if(myTurnPoints == 0) {
        myTurnRolls = 0;
    }

    if(myPoints < opponentPoints) { //Perdendo 
        int difference = opponentPoints - myPoints;
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