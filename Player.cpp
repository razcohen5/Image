#include "Player.h"
#include "Board.h"
#include "DummyPlayers.h"
#include "Champion.h"

Player :: Player (){
    setChar('.');
}
Player :: Player (const Player& p){
    setChar(p.c);
} 
void Player :: setChar(char c){
    this->c=c;
} 
char Player :: getChar() const{
    return c;
}

const string Player :: name() const{return "a";}

const Coordinate Player :: play(const Board& board){return {0,0};}



