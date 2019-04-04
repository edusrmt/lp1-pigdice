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
            roll = myTurnRolls < 4;
            roll = roll || (myTurnPoints < 16 && myTurnRolls < 5);
        } else if(difference > 15) {
            roll = myTurnRolls < 3;
            roll = roll || (myTurnPoints < 15 && myTurnRolls < 4);
        } else {
            roll = myTurnRolls < 3;
            roll = roll || (myTurnPoints < 8 && myTurnRolls < 4);
        }
    } else if(myPoints > opponentPoints) { //Ganhando
        int difference = myPoints - opponentPoints;
        if(difference > 30) {
            roll = myTurnRolls < 2;
        } else if(difference > 15) {
            roll = myTurnRolls < 2 || myTurnPoints < 5;
        } else {
            roll = myTurnRolls < 3 || myTurnPoints < 6;
        }
    } else { //Empatando
        roll = myTurnRolls < 3;
        roll = roll || (myTurnRolls < 4 && myTurnPoints < 10);
    }

    if(roll) {
        myTurnRolls++;
        return 0;
    } else {
        return 1;
    }
}