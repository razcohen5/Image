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

	// const Bridge Board :: operator[](const Coordinate& c) 
	// {
	// 	cout<<"not const";
	// 	if(c.row<0||c.col<0||c.row>=size||c.col>=size)
	// 		throw IllegalCoordinateException(c.row,c.col);
	// 	else if(b[c.row][c.col]=='O'||b[c.row][c.col]=='X')
	// 		throw IllegalCoordinateException(c.row,c.col);
	// 	else
	// 		return Bridge(this,c.row,c.col);
	// }

	const Bridge Board :: operator[](const Coordinate& c) const
	{
		//if(c.row<0||c.col<0||c.row>=size||c.col>=size)
			//throw IllegalCoordinateException(c.row,c.col);
		//else if(b[c.row][c.col]!='.')
		 //	throw IllegalCoordinateException(c.row,c.col);	
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

	inline bool exists(const std::string& name)
	{
		ifstream f(name.c_str());
		return f.good();
	}

	string Board :: draw(int n)
	{
		//check if file already exist and if it is create a new one
		string filename = "TicTacToe.ppm";
		for(int i=0;exists(filename);i++)
			filename = "TicTacToe" + to_string(i) + ".ppm";
		ofstream imageFile(filename, ios::out | ios::binary);
		imageFile << "P6" << endl << n <<" " << n << endl << 255 << endl;
		RGB *image = new RGB[n*n];

		int *PixelsRange = new int[size+1];
		int sum=0;
		int q;
		PixelsRange[0] = 0;
		for(q=1;q<size;q++)
		{
			PixelsRange[q] = n/size + sum;
			sum = PixelsRange[q];
		}
		PixelsRange[q] = n;

		int row = 0;
  		int col = 0;
		while(row < size)
		{
			for(int j=PixelsRange[row];j<PixelsRange[row+1];++j)
			{
				while(col < size)
				{
					for(int i=PixelsRange[col];i<PixelsRange[col+1];++i)
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
				}
				col = 0;
			}
			row++;
			col = 0;			
		}

		image[0].red = 255;
 		image[0].blue = 0;
  		image[0].green = 0;
		imageFile.write(reinterpret_cast<char*>(image), 3*n*n);
 		imageFile.close();
		delete[] image;
		delete[] PixelsRange;
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
		b.deleteBoard();
		string line = "";
		in >> line;
		b.size = line.length();
		char **t = new char* [b.size];
		for(int i=0;i<b.size;i++)
			t[i] = new char[b.size];

		for(int i=0;i<b.size;i++)
			for(int j=0;j<b.size;j++)
				t[i][j] = '.';
		b.b=t;

		int i;
		int j;
		for(i=0;i<b.size-1;i++)
		{		
			for(j=0;j<b.size;j++)
				b.b[i][j] = line[j];
			line = "";
			in >> line;
		}
		for(j=0;j<b.size;j++)
			b.b[i][j] = line[j];

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
		if(i<0||j<0||i>=bp->size||j>=bp->size)
			throw IllegalCoordinateException(i,j);
		if(bp->b[i][j]!='.')
			throw IllegalCoordinateException(i,j);	
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

	int main() {
	Board board;
	cin >> board;
	string filename = board.draw(600);
	cout << filename << endl;
}
	
