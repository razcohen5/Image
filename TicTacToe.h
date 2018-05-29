#pragma once
#include "Player.h"
#include "Board.h"
class TicTacToe{
    public:
    Board *b;
    Player *winP;
        TicTacToe(int size);
        void play(Player& X, Player& O);
        Player& winner() const;
		Board& board() const;
        bool isBoardFull();
        bool WinnerFound();
        bool checkDiagonalLeftDown();
        bool checkDiagonalLeftUp();
        bool checkRows();
        bool checkCols();
		~TicTacToe();
};