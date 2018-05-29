    #include "Coordinate.h"
    Coordinate :: Coordinate(int a,int b){
		row=a;
		col=b;
	}

		Coordinate :: Coordinate(const Coordinate& other){
		row = other.row;
		col = other.col;
	}