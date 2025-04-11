#pragma once

#include "Piece.h"
#include <string>

using std::vector;
using std::string;

class King : public Piece
{
public:
	King(string type, string position);
	~King();

	bool checkMoving(string movment, Board* chessBorad);
	void pieceMovement(string currentPosition, Board* chessBoard);

};
