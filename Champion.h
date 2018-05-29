#pragma once
#include "Player.h"
#include "Board.h"
using namespace std;
class Champion : public Player
{
public:
	const string name() const { return "Raz and Yakir"; }
	const Coordinate play(const Board& board);
};

