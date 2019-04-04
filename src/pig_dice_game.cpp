#include "../include/pig_dice_game.h"
using namespace std;
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
        cout << endl << "\u25ba  PLAYER " << gst.currentPlayer + 1 << "'S TURN" << endl;
    else
        cout << endl << "\u25ba  AI'S TURN" << endl;
    
    while (nextAction != 1) {
        if (gst.players[gst.currentPlayer].isHuman) {
            cout << "CHOOSE ACTION [0 TO ROLL OR 1 TO HOLD]: ";
            nextAction = next_action_user(gst.turn);
        } else {
            nextAction = next_action_ia(gst.turn, gst);
        }

        if (nextAction == 0) {
            DiceFace face = roll();

            if (face == 1) {
                gst.turn.turnTotal = 0;
                cout << "PIG: " << faceToUnicode(face) << endl;
                break;
            } else {
                gst.turn.turnTotal += face;
                ++gst.turn.turnRolls;
                cout << "ROLL: " << faceToUnicode(face) << endl;
            }                

            
        } else {
            cout << "HOLD!" << endl;
        }
    }
}

action_t next_action_user(const TurnSnapshot &ts) {
    action_t action;
    cin >> action;
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
    cout << endl << "######################################################################" << endl << endl;
    cout << "                         .------------------." << endl;
    cout << "                         |    SCOREBOARD    |" << endl;
    cout << "                         :------------.-----:" << endl;
    cout << "                         | Player 1   | " << gst.players[0].score;

    if (gst.players[0].score < 10)
        cout << "   |" << endl;
    else if (gst.players[0].score < 100)
        cout << "  |" << endl;
    else
        cout << " |" << endl;

    cout << "                         :------------+-----:" << endl;
    
    if(gst.players[1].isHuman)
        cout << "                         | Player 2   | ";
    else
        cout << "                         | AI         | ";

    cout << gst.players[1].score;

    if (gst.players[1].score < 10)
        cout << "   |" << endl;
    else if (gst.players[1].score < 100)
        cout << "  |" << endl;
    else
        cout << " |" << endl;


    cout << "                         '------------'-----'" << endl << endl;
    cout << "######################################################################" << endl;
}

void render_welcome_msg(GameState &gst) {
    int option;

    cout << "######################################################################" << endl;
    cout << "    ___      ___      ___           ___      ___      ___      ___" << endl;
    cout << "   /\\  \\    /\\  \\    /\\  \\         /\\  \\    /\\  \\    /\\  \\    /\\  \\" << endl;
    cout << "  /::\\  \\  _\\:\\  \\  /::\\  \\       /::\\  \\  _\\:\\  \\  /::\\  \\  /::\\  \\" << endl;
    cout << " /::\\:\\__\\/\\/::\\__\\/:/\\:\\__\\     /:/\\:\\__\\/\\/::\\__\\/:/\\:\\__\\/::\\:\\__\\" << endl;
    cout << " \\/\\::/  /\\::/\\/__/\\:\\:\\/__/     \\:\\/:/  /\\::/\\/__/\\:\\ \\/__/\\:\\:\\/  /" << endl;
    cout << "    \\/__/  \\:\\__\\   \\::/  /       \\::/  /  \\:\\__\\   \\:\\__\\   \\:\\/  /" << endl;
    cout << "            \\/__/    \\/__/         \\/__/    \\/__/    \\/__/    \\/__/" << endl << endl;
    cout << "                  | PRESS \u2460 TO PLAYER VS PLAYER |" << endl;
    cout << "                  |   PRESS \u2461 TO PLAYER VS AI   |" << endl << endl;
    cout << "######################################################################" << endl << endl;
    cout << "                           INSERT OPTION: ";
    cin >> option;   
    cout << endl << "######################################################################" << endl << endl;
    cout << "                           | INSTRUCTIONS |" << endl << endl;
    cout << "         \u25ba  On a turn, a player rolls the dice repeatedly." << endl << endl;
    cout << "      \u25ba  The goal is to accumulate as many points as possible," << endl;
    cout << "               adding up the numbers rolled on the dice." << endl << endl;
    cout << "    \u25ba  However, if a player rolls a 1, the player's turn is over" << endl;
    cout << "          and any points accumulated during this turn are lost." << endl << endl;
    cout << "    \u25ba  A player can also choose to hold (stop rolling the dice)" << endl << endl;
    cout << "       \u25ba  This way, all of the points rolled during that turn" << endl;
    cout << "                     are added to his or her score." << endl << endl;
    cout << "       \u25ba  When a player reaches a total of 100 or more points," << endl;
    cout << "              the game ends and that player is the winner." << endl << endl;
    cout << "######################################################################" << endl;

    if (option == 2)
        gst.players[1].isHuman = false;
}

void render_final_msg (const GameState &gst) {
    if (gst.players[0].score >= 100) {
        cout << endl << "  _____ __    _____ __ __ _____ _____    ___      _ _ _ _____ _____" << endl;
        cout << " |  _  |  |  |  _  |  |  |   __| __  |  |_  |    | | | |     |   | |" << endl;
        cout << " |   __|  |__|     |_   _|   __|    -|   _| |_   | | | |  |  | | | |" << endl;
        cout << " |__|  |_____|__|__| |_| |_____|__|__|  |_____|  |_____|_____|_|___|" << endl << endl;
    } else if (gst.players[1].isHuman) {
        cout << endl << "   _____ __    _____ __ __ _____ _____    ___    _ _ _ _____ _____" << endl;
        cout << "  |  _  |  |  |  _  |  |  |   __| __  |  |_  |  | | | |     |   | |" << endl;
        cout << "  |   __|  |__|     |_   _|   __|    -|  |  _|  | | | |  |  | | | |" << endl;
        cout << "  |__|  |_____|__|__| |_| |_____|__|__|  |___|  |_____|_____|_|___|" << endl << endl;
    } else {
        cout << endl << "                   _____ _____    _ _ _ _____ _____" << endl;
        cout << "                  |  _  |     |  | | | |     |   | |" << endl;
        cout << "                  |     |-   -|  | | | |  |  | | | |" << endl;
        cout << "                  |__|__|_____|  |_____|_____|_|___|" << endl << endl;
    }
}