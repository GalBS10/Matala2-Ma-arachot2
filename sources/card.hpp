#ifndef CARD
#define CARD
#include "iostream"
#include "string.h"


//each card will have only a value (and sign (enum)) 1 is for Ace , 2 is for two , ... , 11 is for Jack , 12 is for Queen , 13 is for king.
    class Card{
        public:
            int value;

            Card();
            Card (int val);
    };
#endif
