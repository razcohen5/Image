#include "TicTacToe.h"
TicTacToe :: TicTacToe(int size){
    b = new Board{size};
    
}

Board& TicTacToe :: board() const
{
	return *b;
}
bool TicTacToe :: isBoardFull()
{
    for(int i=0;i<b->size;i++)
        for(int j=0;j<b->size;j++)
            if(b->b[i][j]=='.')
        	    return false;
    return true;
}
void TicTacToe:: play(Player& X, Player& O){
	*b='.';
    bool gameover=false;
    X.setChar('X');
    O.setChar('O');
    while(!gameover)
	{
		//Player X
		try{	(*b)[X.play(*b)]='X';	}
		catch(const IllegalCoordinateException& i)
		{
			winP = &O;
			gameover = true;
		}
		if(!gameover&&WinnerFound())
		{
			winP = &X;
			gameover = true;
		}
		if(!gameover&&isBoardFull())
		{
			winP = &O;
			gameover = true;
		}
		//Player O
        if(!gameover)
		{
       	 	try{	(*b)[O.play(*b)]='O';	}
			catch(const IllegalCoordinateException& i)
			{
				winP = &X;
				gameover = true;
			}
			if(!gameover&&WinnerFound())
			{
				winP = &O;
				gameover = true;
			}
			if(!gameover&&isBoardFull())
			{
				winP = &O;
				gameover = true;
			}
        }

    }
}

bool TicTacToe :: checkDiagonalLeftDown() // this '\'
{
    for(int i=0;i<b->size-1;i++)
        if(b->b[i][i]!=b->b[i+1][i+1]||b->b[i][i]=='.')
			return false;
    return true;
}

bool TicTacToe :: checkDiagonalLeftUp() // this '/'
{
	for(int i=b->size-1,j=0;i>0,j<b->size-1;i--,j++)
		if(b->b[i][j]!=b->b[i-1][j+1]||b->b[i][j]=='.')
			return false;
	return true;
}

bool TicTacToe :: checkRows()
{
   bool rowfound=false;
   for(int i=0;i<b->size;i++)
   {
		bool currentrow=true;
        for(int j=0;j<b->size-1;j++)
			if(b->b[i][j]!=b->b[i][j+1]||b->b[i][j]=='.')
				currentrow=false;
		if(currentrow)
			rowfound=true;
   }
   return rowfound;
}
bool TicTacToe :: checkCols()
{
   bool colfound=false;
   for(int i=0;i<b->size;i++)
   {
		bool currentcol=true;
        for(int j=0;j<b->size-1;j++)
			if(b->b[j][i]!=b->b[j+1][i]||b->b[j][i]=='.')
				currentcol=false;
		if(currentcol)
			colfound=true;
   }
   return colfound;
}
bool TicTacToe :: WinnerFound()
{
	//checkCols()||checkDiagonalLeftDown()||checkDiagonalLeftUp()||checkRows()
    return checkCols()||checkDiagonalLeftDown()||checkDiagonalLeftUp()||checkRows();
}
Player& TicTacToe:: winner() const 
{
    return *winP;
}
TicTacToe :: ~TicTacToe()
{
	//b->deleteBoard();
	delete b;
}