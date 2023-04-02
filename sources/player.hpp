#ifndef PLAYER
#define PLAYER
#include "iostream"
//#include "card.hpp"

using namespace std;
class Player{

    
    string name;
    //int cards_left;
    //string turns [5];
    //Card card_stack[52];
    public:
        //constructor
        Player ();
        Player (string n);

      //  Card card_out();
      //  void add_turn(string turn);
      //  string last_turn();
      //  int how_many_cards();
       // bool is_playing = false;
        string getName();
        int stacksize();
        int cardesTaken();
};
#endif