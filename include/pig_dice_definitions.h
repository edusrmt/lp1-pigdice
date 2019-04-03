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
    TurnSnapshot turn;
    int currentPlayer;
};

typedef int action_t;

#endif