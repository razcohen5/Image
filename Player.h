#pragma once
#include "Coordinate.h"
#include "Board.h"
using namespace std;
class Player{
  
    public:
      char c;
        Player();
        Player(const Player& p);
        virtual const string name() const;
        virtual const Coordinate play(const Board& board);
        void setChar(char c);
        char getChar() const;
       
};