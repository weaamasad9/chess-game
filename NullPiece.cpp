#include "NullPiece.h"

NullPiece::NullPiece(string type, string position) : Piece(type, position)
{
}

NullPiece::~NullPiece()
{
	Piece::~Piece();
}

bool NullPiece::checkMoving(string movment, Board* chessBoard)
{
	return false;
}

void NullPiece::pieceMovement(string currentPosition, Board* chessBoard)
{
}




