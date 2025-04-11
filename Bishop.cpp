#include "Bishop.h"
#include "NullPiece.h"
#include "ChessException.h"

Bishop::Bishop(string type, string position) : Queen(type, position)
{
}

Bishop::~Bishop()
{
	Queen::~Queen();
}

bool Bishop::checkMoving(string movment, Board* chessBoard)
{
	bool ans; 

	int currentRow = 0, currentColumn = 0;
	int goToRow = 0, goToColumn = 0;

	//movment = "a8b7" --- currentPosition = "a8", goToPosition = "b8"
	string currentPosition = movment.substr(0, 2);
	string goToPosition = movment.substr(2, 2);

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

	pieceMovement(currentPosition, chessBoard);

	if (_bishopsAvaliblePositions.size() == 0)
	{
		ans = false;
	}

	for (unsigned int current = 0; current < _bishopsAvaliblePositions.size(); current++)
	{
		if ((isupper(chessBoard->_boardState[currentRow][currentColumn]->getType()[0]) && isupper(chessBoard->_boardState[goToRow][goToColumn]->getType()[0]))
			|| (islower(chessBoard->_boardState[currentRow][currentColumn]->getType()[0]) && islower(chessBoard->_boardState[goToRow][goToColumn]->getType()[0])))
		{
			ans = false;
			throw(ChessException("3"));
			break;
		}
		else if (_bishopsAvaliblePositions[current] == goToPosition)
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

void Bishop::pieceMovement(string currentPosition, Board* chessBoard)
{
	_bishopsAvaliblePositions = Xmovment(currentPosition, chessBoard);
}


vector<string> Bishop::getAvaliblePositionsVector()
{
	return vector<string>(_bishopsAvaliblePositions);
}
