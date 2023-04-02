#ifndef GAME
#define GAME
#include "iostream"
#include "player.hpp"
#include <array>
using namespace std;

namespace ariel{

}
    constexpr int CARDS_AMOUNT = 52;
    constexpr int PACK_SIZE = 13;
    /// @brief - In part 2 I will try to first "shuffle" the cards and then split the pack to the players
    class Game{

        public:
            Player player1;
            Player player2;
            //int pack [PACK_SIZE];
           // array<int, PACK_SIZE> pack;//52/4. every card in the pack is there 4 time(without regards to the signs(heart,diamond etc)).
            //each cell will hold the amount of cards with the same value. as i said if it worked properly should be 4.

            Game();
            Game(Player& player1, Player& player2);

            string getP1();
            string getP2();
            void playTurn();
            void printLastTurn();
            void playAll();
            void printWiner();
            void printLog();
            void printStats();

    };
#endif