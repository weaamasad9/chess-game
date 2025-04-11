#pragma once

#include "Queen.h"

using std::vector;
using std::string;

class Bishop : public Queen
{
public:
	Bishop(string type, string position);
	~Bishop();

	bool checkMoving(string movment, Board*);
	void pieceMovement(string currentPosition, Board*);
	vector<string> getAvaliblePositionsVector();

private:
	vector<string> _bishopsAvaliblePositions;
};

