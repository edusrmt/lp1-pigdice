#include "../include/pig_dice_game.h"
using namespace dice;

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
    TurnSnapshot snap = {0, gst.players[gst.currentPlayer].score, gst.players[(gst.currentPlayer + 1) % 2].score, 0};
    gst.turn = snap;
}

bool game_over(GameState &gst) {
    return gst.players[0].score >= 100 || gst.players[1].score >= 100;
}

void process_events(GameState &gst) {   
    action_t nextAction = 0;
    
    while (nextAction != 1) {
        if (gst.players[gst.currentPlayer].isHuman) {
            std::cout << "Player " << gst.currentPlayer + 1 << ", what do you want do to?" << std::endl;
            std::cout << "Press (0) to roll | Press (1) to hold" << std::endl;
            nextAction = next_action_user(gst.turn);                 
        } else {
            nextAction = next_action_ia(gst.turn, gst);
        }

        if (nextAction == 0) {
            FaceType face = 1 + (rand() % 6);

            if (face == 1) {
                gst.turn.turnTotal = 0;
                update(gst);
            } else {
                gst.turn.turnTotal += face;
                ++gst.turn.turnRolls;
            }                

            std::cout << "Dado: " << face << std::endl;
        }
    }
}

action_t next_action_user(const TurnSnapshot &ts) {
    action_t action;
    std::cin >> action;
    return action;
}

void update (GameState &gst) {
    gst.players[gst.currentPlayer].score += gst.turn.turnTotal;
    gst.turn.turnTotal = 0;
    gst.turn.opponentPoints = gst.players[gst.currentPlayer].score;
    ++gst.currentPlayer %= 2;
    gst.turn.myPoints = gst.players[gst.currentPlayer].score;
    gst.turn.turnRolls = 0;
}

void render(GameState &gst) {
    std::cout << "SITUAÇÃO ATUAL" << std::endl;
    std::cout << "Jogador 1: " << gst.players[0].score << std::endl;
    std::cout << "Jogador 2: " << gst.players[1].score << std::endl;
}