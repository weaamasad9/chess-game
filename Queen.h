#pragma once

#include "Piece.h"

using std::vector;
using std::string;

class Queen : public Piece
{
public:
	Queen(string type, string position);
	~Queen();

	virtual bool checkMoving(string movment, Board*);
	virtual void pieceMovement(string currentPosition, Board*);

protected:
	vector<string> CrossMovment(string currentPosition, Board*);
	vector<string> Xmovment(string currentPosition, Board*);
};
