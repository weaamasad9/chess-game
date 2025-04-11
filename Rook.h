#pragma once

#include "Queen.h"

using std::vector;
using std::string;

class Rook : public Queen
{
public:
	Rook(string type, string position);
	~Rook();

	virtual bool checkMoving(string movment, Board*) override;
	virtual void pieceMovement(string currentPosition, Board*) override;
	vector<string> getAvaliblePositionsVector();

private:
	vector<string> _rooksAvaliblePositions;
};


