#include "../include/pig_dice_game.h"
using namespace dice;

void initialize_game(GameState &gst) {
    Player playerOne = {true, 0};
    Player playerTwo = {true, 0};

    gst.players[0] = playerOne;
    gst.players[1] = playerTwo;
    
    gst.currentPlayer = rand() % 2;
    TurnSnapshot snap = {0, gst.players[gst.currentPlayer].score, gst.players[(gst.currentPlayer + 1) % 2].score, 0};
    gst.turn = snap;

    render_welcome_msg (gst);
}

bool game_over(GameState &gst) {
    return gst.players[0].score >= 100 || gst.players[1].score >= 100;
}

void process_events(GameState &gst) {   
    action_t nextAction = 0;

    if (gst.players[gst.currentPlayer].isHuman)
        std::cout << std::endl << "\u25ba  PLAYER " << gst.currentPlayer + 1 << "'S TURN" << std::endl;
    else
        std::cout << std::endl << "\u25ba  AI'S TURN" << std::endl;
    
    while (nextAction != 1) {
        if (gst.players[gst.currentPlayer].isHuman) {
            std::cout << "CHOOSE ACTION [0 TO ROLL OR 1 TO HOLD]: ";
            nextAction = next_action_user(gst.turn);
        } else {
            nextAction = next_action_ia(gst.turn);
        }

        if (nextAction == 0) {
            DiceFace face = roll();

            if (face == 1) {
                gst.turn.turnTotal = 0;
                update(gst);
            } else {
                gst.turn.turnTotal += face;
                ++gst.turn.turnRolls;
            }                

            std::cout << "ROLL: " << faceToUnicode(face) << std::endl;
        } else {
            std::cout << "HOLD!" << std::endl;
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

void render_welcome_msg(GameState &gst) {
    int option;

    std::cout << "######################################################################" << std::endl;
    std::cout << "    ___      ___      ___           ___      ___      ___      ___" << std::endl;
    std::cout << "   /\\  \\    /\\  \\    /\\  \\         /\\  \\    /\\  \\    /\\  \\    /\\  \\" << std::endl;
    std::cout << "  /::\\  \\  _\\:\\  \\  /::\\  \\       /::\\  \\  _\\:\\  \\  /::\\  \\  /::\\  \\" << std::endl;
    std::cout << " /::\\:\\__\\/\\/::\\__\\/:/\\:\\__\\     /:/\\:\\__\\/\\/::\\__\\/:/\\:\\__\\/::\\:\\__\\" << std::endl;
    std::cout << " \\/\\::/  /\\::/\\/__/\\:\\:\\/__/     \\:\\/:/  /\\::/\\/__/\\:\\ \\/__/\\:\\:\\/  /" << std::endl;
    std::cout << "    \\/__/  \\:\\__\\   \\::/  /       \\::/  /  \\:\\__\\   \\:\\__\\   \\:\\/  /" << std::endl;
    std::cout << "            \\/__/    \\/__/         \\/__/    \\/__/    \\/__/    \\/__/" << std::endl << std::endl;
    std::cout << "                  | PRESS \u2460 TO PLAYER VS PLAYER |" << std::endl;
    std::cout << "                  |   PRESS \u2461 TO PLAYER VS AI   |" << std::endl << std::endl;
    std::cout << "######################################################################" << std::endl << std::endl;
    std::cout << "                           INSERT OPTION: ";
    std::cin >> option;   
    std::cout << std::endl << "######################################################################" << std::endl << std::endl;
    std::cout << "                           | INSTRUCTIONS |" << std::endl << std::endl;
    std::cout << "         \u25ba  On a turn, a player rolls the dice repeatedly." << std::endl << std::endl;
    std::cout << "      \u25ba  The goal is to accumulate as many points as possible," << std::endl;
    std::cout << "               adding up the numbers rolled on the dice." << std::endl << std::endl;
    std::cout << "    \u25ba  However, if a player rolls a 1, the player's turn is over" << std::endl;
    std::cout << "          and any points accumulated during this turn are lost." << std::endl << std::endl;
    std::cout << "    \u25ba  A player can also choose to hold (stop rolling the dice)" << std::endl << std::endl;
    std::cout << "       \u25ba  This way, all of the points rolled during that turn" << std::endl;
    std::cout << "                     are added to his or her score." << std::endl << std::endl;
    std::cout << "       \u25ba  When a player reaches a total of 100 or more points," << std::endl;
    std::cout << "              the game ends and that player is the winner." << std::endl << std::endl;
    std::cout << "######################################################################" << std::endl;

    if (option == 2)
        gst.players[1].isHuman = false;
}