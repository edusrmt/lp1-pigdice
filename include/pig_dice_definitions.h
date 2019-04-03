#ifndef _PIG_DICE_DEFINITIONS_H_
#define _PIG_DICE_DEFINITIONS_H_

typedef struct turnSnapshot TurnSnapshot;
struct turnSnapshot {
    int turnTotal;
    int myPoints;
    int opponentPoints;
    int turnRolls;
};

typedef struct player Player;
struct player {
    bool isHuman;
    int score;    
};

typedef struct gameState GameState;
struct gameState {
    Player players[2];
    int currentPlayer;
    int turnScore;
    int turnRolls;
};

typedef int action_t;

#endif