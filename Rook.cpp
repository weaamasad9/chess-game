#include "Rook.h"
#include "NullPiece.h"
#include "ChessException.h"

Rook::Rook(string type, string position) : Queen(type, position)
{
}

Rook::~Rook()
{
	Queen::~Queen();
}

bool Rook::checkMoving(string movment, Board* chessBoard)
{
	bool ans;

	int currentRow = 0, currentColumn = 0;
	int goToRow = 0, goToColumn = 0;
	string currentPosition = movment.substr(0, 2);
	string goToPosition = movment.substr(2, 2);

	pieceMovement(currentPosition, chessBoard);


	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLUMNS; col++)
		{
			if (chessBoard->_boardIndexName[row][col] == currentPosition)
			{
				currentRow = row;
				currentColumn = col;
			}
			if (chessBoard->_boardIndexName[row][col] == goToPosition)
			{
				goToRow = row;
				goToColumn = col;
			}
		}
	}


	if (_rooksAvaliblePositions.size() == 0)
	{
		ans = false;
	}

	for (unsigned int current = 0; current < _rooksAvaliblePositions.size(); current++)
	{
		if ((isupper(chessBoard->_boardState[currentRow][currentColumn]->getType()[0]) && isupper(chessBoard->_boardState[goToRow][goToColumn]->getType()[0]))
			|| (islower(chessBoard->_boardState[currentRow][currentColumn]->getType()[0]) && islower(chessBoard->_boardState[goToRow][goToColumn]->getType()[0])))
		{
			ans = false;
			throw(ChessException("3"));
			break;
		}
		else if (_rooksAvaliblePositions[current] == goToPosition)
		{
			ans = true;
			break;
		}
		else
		{
			ans = false;
		}
	}

	return ans;
}

void Rook::pieceMovement(string currentPosition, Board* chessBoard)
{
	_rooksAvaliblePositions = CrossMovment(currentPosition, chessBoard);
}


vector<string> Rook::getAvaliblePositionsVector()
{
	return vector<string>(_rooksAvaliblePositions);
}
