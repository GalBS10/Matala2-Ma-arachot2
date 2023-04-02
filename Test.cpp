// People who i talked to:
// Yuval Yurzdichinsky
//Yarin Levi
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

   
   
TEST_CASE("Checking case : Initialization"){
    Player p1("Alice");
    Player p2("Bob");
    Player p3 = Player();
    

    CHECK( p3.getName() == "Gal"); //default init
    CHECK_THROWS_AS(Player p4("Ga@l"),invalid_argument);//cant give a name with somthing othe than letters or numbers.
    //CHECK_THROWS_AS(Player p5("Bob"),invalid_argument);//the name is already in use.
    CHECK( p1.stacksize() == 0);
    CHECK( p2.stacksize() == 0);
    CHECK( p1.cardesTaken() == 0);
    CHECK( p2.cardesTaken() == 0);
    
    Game game(p1,p2);
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26); 

    // for(int i=0 ; i<13 ; i++){
    //     CHECK( game.pack[i] == 4);//checking if there are 4 cards of each value
    // }

    CHECK( game.getP1() == "Alice");
    CHECK ( game.getP2() == "Bob");

}

TEST_CASE("Checking whether you succeed to play"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2); 
    
    game.playTurn();

    CHECK( p1.stacksize() != 26);//after 1 turn it means that one of them won (even if it wad a tie) therefore the amount of cards...
    CHECK( p2.stacksize() != 26);//...they holds is different now.

    game.playAll();
    CHECK( p1.cardesTaken() + p2.cardesTaken() == 52); //if the game ends and played correctly it should be 52(cards amount) 


}

TEST_CASE("Checking Case : player confusion"){

    Player p1("Alice");
    Player p2("Bob");
    Player p3("Zetz");

    Game game(p1,p2);
    CHECK_THROWS_AS(Game game2(p1,p3), invalid_argument);//can't start a game with a taken player.
    CHECK_THROWS_AS(Game game3(p1,p2), invalid_argument);//same but with 2 players.

}

TEST_CASE("Checking Case : out of cards"){

    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    CHECK_NOTHROW(game.playAll());
    //if the playall() only happens in the check
    //need to make another game with another player
    // CHECK( (p1.stacksize() == 0) || (p2.stacksize() == 0)); // when the game ends one of the player has 0 cards.
    // //How ever when the game is finished it doesnt mean that the winner has 52 cards (example : ends with a tie)

}

TEST_CASE("Checking Case : after the end"){

    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);

    game.playAll();
    CHECK_THROWS( game.playAll());//can't run because the game is already finished.
    CHECK_THROWS( game.playTurn());
    CHECK_NOTHROW( game.printLastTurn());
    CHECK_NOTHROW( game.printLog());
    CHECK_NOTHROW( game.printStats());
    CHECK_NOTHROW( game.printWiner());

}

TEST_CASE("Checking Case : play with the same plyers after the game ends"){

    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);

    game.playAll();
    CHECK_NOTHROW(Game game2(p1,p2));  
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);

}



