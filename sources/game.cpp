#include "player.hpp"
#include "game.hpp"

Game::Game(){

}

Game::Game(Player& p1, Player& p2){

}

string Game:: getP1(){
    return NULL;

}
string Game:: getP2(){
    return NULL;
}

void Game:: playTurn(){// print the last turn stats. For example:
                                                    // Alice played Queen of Hearts Bob played 5 of Spades. Alice wins.
                                                    // Alice played 6 of Hearts Bob played 6 of Spades. Draw. Alice played 10 of Clubs Bob played 10 of Diamonds. draw. Alice played Jack of Clubs Bob played King of Diamonds. Bob wins.


}
void Game:: printLastTurn(){

}
void Game:: printWiner(){// prints the name of the winning player

}
void Game:: playAll(){//playes the game untill the end

}
void Game:: printLog(){// prints all the turns played one line per turn (same format as game.printLastTurn())

}
void Game:: printStats(){// for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )

}