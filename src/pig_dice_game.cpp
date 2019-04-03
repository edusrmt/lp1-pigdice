#include "../include/pig_dice_game.h"

void initialize_game(GameState &gst) {
    Player playerOne = {true, 0};
    Player playerTwo = {false, 0};
    gst.playerOne = playerOne;
    gst.playerTwo = playerTwo;
}

bool game_over(GameState &gst) {
    return gst.playerOne.score >= 100 || gst.playerTwo.score >= 100;
}