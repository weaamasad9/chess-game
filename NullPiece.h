#pragma once
#include "Piece.h"
#include <string>

using std::string;

class NullPiece : public Piece
{
public:
	NullPiece(string type, string position);
	virtual ~NullPiece();
	bool checkMoving(string movement, Board*);
	void pieceMovement(string currentPosition, Board*);
};
