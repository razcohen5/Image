#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include "Coordinate.h"

using namespace std;
struct RGB;
class Bridge;
class Board;
class IllegalCharException;
class IllegalCoordinateException;
class Board
{
public:
	int size;
	char **b;

	Board();
	
	Board(int size);

	Board(const Board& other);


	//const Bridge operator[](const Coordinate& c);

	const Bridge operator[](const Coordinate& c) const;

	void operator=(char c);

	Board& operator=(const Board& other);

	string draw(int n);

	inline bool exists_test0 (const std::string& name);

	friend istream& operator >> (istream& in, Board& b);

	friend ostream& operator<< (ostream& os, const Board& b);

	void deleteBoard();

	~Board();

};



class Bridge
{
public:

	const Board* bp;
	int i;
	int j;
	
	Bridge(Board* p,const int a,const int b);
	Bridge(const Board* p,const int a,const int b);
	Bridge(const Bridge& other);

	void operator=(char c) const;

	bool operator==(char c) const;

	bool operator!=(char c) const;

	bool operator==(const Bridge& other);

	bool operator!=(const Bridge& other);
};

class IllegalCoordinateException : public exception 
{
	public:	

	int i;
	int j;

	IllegalCoordinateException(int a, int b);


	string theCoordinate() const;
};

class IllegalCharException : public exception 
{
public:

	char c;

	IllegalCharException(char a);


	char theChar() const;

};
struct RGB {
  uint8_t red, green, blue;
  public:
  RGB() {}
  RGB(uint8_t red, uint8_t green, uint8_t blue): red(red), green(green), blue(blue) {}
};
