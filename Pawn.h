#pragma once

#include "Piece.h"

using std::vector;
using std::string;

using std::string;

class Pawn : public Piece
{
public:
	Pawn(string type, string position);
	~Pawn();

	bool checkMoving(string movment, Board*);
	void pieceMovement(string currentPosition, Board*);
};
