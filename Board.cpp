	#include "Board.h"

    using namespace std;

	Board :: Board()
	{
		this->size = 3;
		char **t = new char* [size];
		for(int i=0;i<size;i++)
			t[i] = new char[size];

		for(int i=0;i<size;i++)
			for(int j=0;j<size;j++)
				t[i][j] = '.';

		b=t;
	}

	Board :: Board(int size)
	{
		this->size = size;
		char **t = new char* [size];
		for(int i=0;i<size;i++)
			t[i] = new char[size];

		for(int i=0;i<size;i++)
			for(int j=0;j<size;j++)
				t[i][j] = '.';

		b=t;
	}

	Board :: Board(const Board& other)
	{
		size = other.size;
		char **t = new char* [size];
		for(int i=0;i<size;i++)
			t[i] = new char[size];

		for(int i=0;i<size;i++)
			for(int j=0;j<size;j++)
				t[i][j] = other.b[i][j];
		b=t;
	}

	const Bridge Board :: operator[](const Coordinate& c) 
	{
		if(c.row<0||c.col<0||c.row>=size||c.col>=size)
			throw IllegalCoordinateException(c.row,c.col);
		else if(b[c.row][c.col]=='O'||b[c.row][c.col]=='X')
			throw IllegalCoordinateException(c.row,c.col);
		else
			return Bridge(this,c.row,c.col);
	}

	const Bridge Board :: operator[](const Coordinate& c) const
	{
		if(c.row<0||c.col<0||c.row>=size||c.col>=size)
			throw IllegalCoordinateException(c.row,c.col);
		else if(b[c.row][c.col]=='O'||b[c.row][c.col]=='X')
			throw IllegalCoordinateException(c.row,c.col);
		else
			return Bridge(this,c.row,c.col);
	}

	void Board :: operator=(char c)
	{
		if(c!='X'&&c!='O'&&c!='.')
			throw IllegalCharException(c);
		for(int i=0;i<size;i++)
			for(int j=0;j<size;j++)
				b[i][j] = c;
	}

	void Board :: deleteBoard()
	{
		for(int i=0;i<size;i++)
			delete[] b[i];
		delete[] b;
	}

	Board& Board :: operator=(const Board& other)
	{
		deleteBoard();
		size = other.size;
		char **t = new char* [size];
		for(int i=0;i<size;i++)
			t[i] = new char[size];

		for(int i=0;i<size;i++)
			for(int j=0;j<size;j++)
				t[i][j] = other.b[i][j];
		b=t;
	}

	string Board :: draw(int n)
	{
		string filename = "TicTacToe5.ppm";
		ofstream imageFile(filename, ios::out | ios::binary);
		imageFile << "P6" << endl << n <<" " << n << endl << 255 << endl;
		RGB *image = new RGB[n*n];
		int row = 0;
  		int col = 0;
		for(int j=0;j<n/3;++j)
		{
			for(int i=0;i<n/3;++i)
			{
				if(b[row][col]=='X')
				{
					image[n*j+i].red = 102;
					image[n*j+i].green = 178;
					image[n*j+i].blue = 255;
				}
				else if(b[row][col]=='O')
				{
					image[n*j+i].red = 102;
					image[n*j+i].green = 255;
					image[n*j+i].blue = 178;
				}
				else
				{
					image[n*j+i].red = 255;
					image[n*j+i].green = 255;
					image[n*j+i].blue = 255;
				}
			}
			col++;
			for(int i = n/3;i<2*(n/3);++i)
			{
				if(b[row][col]=='X')
				{
					image[n*j+i].red = 102;
					image[n*j+i].green = 178;
					image[n*j+i].blue = 255;
				}
				else if(b[row][col]=='O')
				{
					image[n*j+i].red = 102;
					image[n*j+i].green = 255;
					image[n*j+i].blue = 178;
				}
				else
				{
					image[n*j+i].red = 255;
					image[n*j+i].green = 255;
					image[n*j+i].blue = 255;
				}
			}
			col++;
			for(int i = 2*(n/3);i<n;++i)
			{
				if(b[row][col]=='X')
				{
					image[n*j+i].red = 102;
					image[n*j+i].green = 178;
					image[n*j+i].blue = 255;
				}
				else if(b[row][col]=='O')
				{
					image[n*j+i].red = 102;
					image[n*j+i].green = 255;
					image[n*j+i].blue = 178;
				}
				else
				{
					image[n*j+i].red = 255;
					image[n*j+i].green = 255;
					image[n*j+i].blue = 255;
				}
			}
			col=0;
		}
		row++;
		for(int j=n/3;j<2*(n/3);++j)
		{
			for(int i=0;i<n/3;++i)
			{
				if(b[row][col]=='X')
				{
					image[n*j+i].red = 102;
					image[n*j+i].green = 178;
					image[n*j+i].blue = 255;
				}
				else if(b[row][col]=='O')
				{
					image[n*j+i].red = 102;
					image[n*j+i].green = 255;
					image[n*j+i].blue = 178;
				}
				else
				{
					image[n*j+i].red = 255;
					image[n*j+i].green = 255;
					image[n*j+i].blue = 255;
				}
			}
			col++;
			for(int i = n/3;i<2*(n/3);++i)
			{
				if(b[row][col]=='X')
				{
					image[n*j+i].red = 102;
					image[n*j+i].green = 178;
					image[n*j+i].blue = 255;
				}
				else if(b[row][col]=='O')
				{
					image[n*j+i].red = 102;
					image[n*j+i].green = 255;
					image[n*j+i].blue = 178;
				}
				else
				{
					image[n*j+i].red = 255;
					image[n*j+i].green = 255;
					image[n*j+i].blue = 255;
				}
			}
			col++;
			for(int i = 2*(n/3);i<n;++i)
			{
				if(b[row][col]=='X')
				{
					image[n*j+i].red = 102;
					image[n*j+i].green = 178;
					image[n*j+i].blue = 255;
				}
				else if(b[row][col]=='O')
				{
					image[n*j+i].red = 102;
					image[n*j+i].green = 255;
					image[n*j+i].blue = 178;
				}
				else
				{
					image[n*j+i].red = 255;
					image[n*j+i].green = 255;
					image[n*j+i].blue = 255;
				}
			}
			col=0;
		}
		row++;
		for(int j=2*(n/3);j<n;++j)
		{
			for(int i=0;i<n/3;++i)
			{
				if(b[row][col]=='X')
				{
					image[n*j+i].red = 102;
					image[n*j+i].green = 178;
					image[n*j+i].blue = 255;
				}
				else if(b[row][col]=='O')
				{
					image[n*j+i].red = 102;
					image[n*j+i].green = 255;
					image[n*j+i].blue = 178;
				}
				else
				{
					image[n*j+i].red = 255;
					image[n*j+i].green = 255;
					image[n*j+i].blue = 255;
				}
			}	
			col++;
			for(int i = n/3;i<2*(n/3);++i)
			{
				if(b[row][col]=='X')
				{
					image[n*j+i].red = 102;
					image[n*j+i].green = 178;
					image[n*j+i].blue = 255;
				}
				else if(b[row][col]=='O')
				{
					image[n*j+i].red = 102;
					image[n*j+i].green = 255;
					image[n*j+i].blue = 178;
				}
				else
				{
					image[n*j+i].red = 255;
					image[n*j+i].green = 255;
					image[n*j+i].blue = 255;
				}
			}
			col++;
			for(int i = 2*(n/3);i<n;++i)
			{
				if(b[row][col]=='X')
				{
					image[n*j+i].red = 102;
					image[n*j+i].green = 178;
					image[n*j+i].blue = 255;
				}
				else if(b[row][col]=='O')
				{
					image[n*j+i].red = 102;
					image[n*j+i].green = 255;
					image[n*j+i].blue = 178;
				}
				else
				{
					image[n*j+i].red = 255;
					image[n*j+i].green = 255;
					image[n*j+i].blue = 255;
				}
			}
			col=0;
		}
		image[0].red = 255;
 		image[0].blue = 0;
  		image[0].green = 0;
		imageFile.write(reinterpret_cast<char*>(image), 3*n*n);
 		imageFile.close();
		delete[] image;
		return filename;
	}

	Board :: ~Board()
	{
		deleteBoard();
	}

	ostream& operator<< (ostream& os, const Board& b){
		int i, j;
		for(i = 0; i < b.size; i++){
			for(j = 0; j < b.size; j++)
				os << b.b[i][j];
			os << endl;
		}
		return os;
	}

	istream& operator >> (istream& in, Board& b)
	{
		for(int i=0;i<b.size;i++)
		{		
			string line = "";
			in >> line;
			for(int j=0;j<b.size;j++)
				b.b[i][j] = line[j];
		}
		return in;
	}

	Bridge :: Bridge(Board* p,const int a,const int b)
	{
		bp = p;
		i=a;
		j=b;
	}

	Bridge :: Bridge(const Board* p,const int a,const int b)
	{
		bp = p;
		i=a;
		j=b;
	}

	Bridge :: Bridge(const Bridge& other)
	{
		bp = other.bp;
		i = other.i;
		j = other.j;
	}

	void Bridge :: operator=(char c) const
	{
		if(c!='X'&&c!='O'&&c!='.')
			throw IllegalCharException(c);
		bp->b[i][j] = c;
	}

	bool Bridge :: operator==(char c) const
	{
		bool check = bp->b[i][j]==c;
		return check;
	}

	bool Bridge :: operator!=(char c) const
	{
		bool check = bp->b[i][j]!=c;
		return check;
	}

	bool Bridge :: operator==(const Bridge& other)
	{
		return bp->b[i,j]==other.bp->b[other.i,other.j];
	}

	bool Bridge :: operator!=(const Bridge& other)
	{
		return !(*this==other);
	}

    IllegalCoordinateException :: IllegalCoordinateException(int a, int b)
	{
		i = a;
		j = b;
	}

	string IllegalCoordinateException :: theCoordinate() const
	{
		string s = to_string(i) + "," + to_string(j);
		return s;
	}

	IllegalCharException :: IllegalCharException(char a)
	{
		c=a;
	}

	char IllegalCharException :: theChar() const
	{
		return c;
	}

/*	int main() {
	Board board;
	cin >> board;
	string filename = board.draw(600);
	cout << filename << endl;
}*/
	
