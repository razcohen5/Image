#include "Champion.h"
const Coordinate Champion :: play(const Board& board) {
	if(board.b[0][board.size-1]=='.')
		return Coordinate(0,board.size-1);
	else
	{
		for(int i=board.size-1,j=0;i>0,j<board.size-1;i--,j++)
			if(board.b[i][j]=='.')
				return Coordinate(i,j);
	}
	return Coordinate(0,0);
}