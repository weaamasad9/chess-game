#include "Piece.h"
#include "ChessException.h"

Piece::Piece(string type, string position) : _type(type), _position(position) {}


Piece::~Piece() {
	_avaliblePositions.clear();
}

vector<string> Piece::getAvaliblePositionsVector()
{
	return vector<string>(_avaliblePositions);
}

string Piece::getType() const{
	return _type;
}

string Piece::getPosition() const{
	return _position;
}

Piece & Piece::operator=(const Piece & other)
{
	_type = other.getType();
	_position = other.getPosition();

	return *this;
}
