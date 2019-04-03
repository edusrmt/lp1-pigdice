#include "../include/pig_dice_game.h"

void initialize_game(GameState &gst) {
    std::cout << "PIG DICE" << std::endl;
    std::cout << "Press (1) to Player vs Player" << std::endl;
    std::cout << "Press (2) to Player vs Machine" << std::endl;
    int option;
    std::cin >> option; 

    Player playerOne = {true, 0};
    Player playerTwo = {true, 0};

    if (option == 2)
        playerTwo.isHuman = false;

    gst.players[0] = playerOne;
    gst.players[1] = playerTwo;
    gst.currentPlayer = rand() % 2;
    gst.turnScore = 0;
    gst.turnRolls = 0;
}

bool game_over(GameState &gst) {
    return gst.players[0].score >= 100 || gst.players[1].score >= 100;
}

void process_events(GameState &gst) {    
    TurnSnapshot ts = {gst.turnScore, gst.players[gst.currentPlayer].score, gst.players[(gst.currentPlayer + 1) % 2].score, gst.turnRolls};
    action_t nextAction;

    switch (gst.players[gst.currentPlayer].isHuman) {
        case true:
            nextAction = next_action_user(ts);             
            break;
    
        case false:
            nextAction = next_action_ia(ts);
            break;
    }

    switch (nextAction)
    {
        case 0:
            // ROLL
            break;

        case 1:
            // HOLD
            break;

    }
}