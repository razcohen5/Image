#include <iostream>
#include <string>
#include <exception>
#include "DummyPlayers.h"
using namespace std;

const Coordinate XYPlayer :: play(const Board& board) {
    for(int i=0;i<board.size;i++){
        for(int j=0;j<board.size;j++){
            if(board.b[i][j]=='.'){
                const Coordinate c{i,j};
                return c;
            }
        }
    }
    return Coordinate{0,0};
}
const Coordinate YXPlayer :: play(const Board& board) {
    for(int i=0;i<board.size;i++){
        for(int j=0;j<board.size;j++){
            if(board.b[j][i]=='.'){
                const Coordinate c{j,i};
                return c;
            }
        }
    }
    return Coordinate{0,0};
}
// const Coordinate IllegalPlayer :: play(const Board& board) {
//     for(int i=0;i<board.size;i++){
//         for(int j=0;j<board.size;j++){
//             if(board.b[i][j]!='.'){
//                 const Coordinate c{i,j};
//                 return c;
//             }
//         }
//     }
// 	return Coordinate(0,0);
// }
const Coordinate IllegalPlayer::play(const Board& board) {
	char charOfOtherPlayer = (
		c=='X'? 'O': 'X'
		);
	for (int y=0; y<board.size; ++y) {
		for (int x=0; x<board.size; ++x) {
			Coordinate c{x,y};
			if (board[c]==charOfOtherPlayer) {
				return c;
			}
		}
	}
	return {0,0};  // did not find an illegal square - play on the top-left
}
const Coordinate ExceptionPlayer :: play(const Board& board) {
    throw IllegalCoordinateException(0,0);
}





// int main() {
// 	TicTacToe game(4);       // Initializes a game on a 4x4 board
// 	XYPlayer player1;
// 	YXPlayer player2;
// 	IllegalPlayer player3;
// 	ExceptionPlayer player4;

// 	playAndPrintResults(game, player1, player2);
// 	/*
// 		The final board is 
// 		XXXX
// 		O...
// 		O...
// 		O...
//     	And the winner is XYPlayer, playing as X!
// 	*/

// 	playAndPrintResults(game, player2, player1);  
// 	/*
// 		The final board is 
// 		XOOO
// 		X...
// 		X...
// 		X...
//         And the winner is YXPlayer, playing as X!
// 	*/

// 	playAndPrintResults(game, player1, player3);  
// 	/*
// 		The final board is 
// 		X...
// 		....
// 		....
// 		....
//         And the winner is XYPlayer, playing as X!
// 	*/


// 	playAndPrintResults(game, player3, player1);  
// 	/*
// 		The final board is 
// 		XO..
// 		....
// 		....
// 		....
//         And the winner is XYPlayer, playing as O!
// 	*/

// 	playAndPrintResults(game, player2, player4);  
// 	/*
// 		The final board is 
// 		X...
// 		....
// 		....
// 		....
// 		And the winner is YXPlayer, playing as X!
// 	*/

// 	playAndPrintResults(game, player4, player2);  
// 	/*
// 		The final board is 
// 		....
// 		....
// 		....
// 		....
// 		And the winner is YXPlayer, playing as O!
// 	*/

// 	cout<<endl;
// 	Champion champion;
// 	playAndPrintWinner(game, champion, player1);
// 	cout<<game.board();
// 		// The winner is <your name>, playing as X!
// 	playAndPrintWinner(game, player1, champion);
// 		// The winner is <your name>, playing as O!
// 		cout<<game.board();
// 	playAndPrintWinner(game, champion, player2);
// 		// The winner is <your name>, playing as X!
// 		cout<<game.board();
// 	playAndPrintWinner(game, player2, champion);
// 		// The winner is <your name>, playing as O!
// 		cout<<game.board();
// 	playAndPrintWinner(game, champion, player3);
// 		// The winner is <your name>, playing as X!
// 		cout<<game.board();
// 	playAndPrintWinner(game, player3, champion);
// 		// The winner is <your name>, playing as O!
// 		cout<<game.board();
// 	playAndPrintWinner(game, champion, player4);
// 		// The winner is <your name>, playing as X!
// 		cout<<game.board();
// 	playAndPrintWinner(game, player4, champion);
// 		// The winner is <your name>, playing as O!
// 		cout<<game.board();

// 	return 0;
// }