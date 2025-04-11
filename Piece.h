#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Board.h"

using std::string;
using std::vector;


class Piece
{
public:

	Piece(string type, string postion);
	~Piece();
	
	virtual void pieceMovement(string, Board*) = 0; // in this function we get all the avalible places for the piece, according to it's legal movement in Chess game
	virtual bool checkMoving(string, Board*) = 0;  // this function checks if the movment is correct ---> if the position the piece is going to is found in the avalible spots if the piece

	virtual vector<string> getAvaliblePositionsVector();
	string getType() const;
	string getPosition() const;
	Piece& operator=(const Piece &other);

protected:
	string _type;
	string _position;
	vector <string> _avaliblePositions; // avalible spots on the board thet will help us move the piece
};