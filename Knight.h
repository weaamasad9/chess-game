#pragma once

#include "Piece.h"

using std::vector;
using std::string;

class Knight : public Piece
{
public:
	Knight(string type, string position);
	~Knight();

	bool checkMoving(string movment, Board*);
	void pieceMovement(string currentPosition, Board*);
};
