#include "Knight.h"
#include "NullPiece.h"
#include "ChessException.h"

Knight::Knight(string type, string position) : Piece(type, position)
{
}

Knight::~Knight()
{
	Piece::~Piece();
}

bool Knight::checkMoving(string movment, Board* chessBoard)
{
	bool ans;

	//movment = "a8b7" --- currentPosition = "a8", goToPosition = "b8"
	string currentPosition = movment.substr(0, 2);
	string goToPosition = movment.substr(2, 2);

	int currentRow = 0, currentColumn = 0;
	int goToRow = 0, goToColumn = 0;

	pieceMovement(currentPosition, chessBoard);

	if (_avaliblePositions.size() == 0)
	{
		ans = false;
	}

	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLUMNS; col++)
		{
			if (chessBoard->_boardIndexName[row][col] == currentPosition)
			{
				currentRow = row;
				currentColumn = col;
				break;
			}
			if (chessBoard->_boardIndexName[row][col] == goToPosition)
			{
				goToRow = row;
				goToColumn = col;
				break;
			}
		}
	}

	for (unsigned int current = 0; current < _avaliblePositions.size(); current++)
	{
		if ((isupper(chessBoard->_boardState[currentRow][currentColumn]->getType()[0]) && isupper(chessBoard->_boardState[goToRow][goToColumn]->getType()[0]))
			|| (islower(chessBoard->_boardState[currentRow][currentColumn]->getType()[0]) && islower(chessBoard->_boardState[goToRow][goToColumn]->getType()[0])))
		{
			ans = false;
			throw(ChessException("3"));
			break;
		}
		else if (_avaliblePositions[current] == goToPosition)
		{
			ans = true;
			break;
		}
		else
		{
			//throw(ChessException("6"));
			ans = false;
		}
	}

	return ans;
}


void Knight::pieceMovement(string currentPosition, Board* chessBoard)
{
	int currentRow = 0, currentColumn = 0;

	// this opiration gives us the index of the position
	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLUMNS; col++)
		{
			if (chessBoard->_boardIndexName[row][col] == currentPosition)
			{
				currentRow = row;
				currentColumn = col;
				break;
			}
		}
	}

	// L movmement
	if ((currentRow + 2 < 8 && currentRow + 2 >= 0) && (currentColumn + 1 < 8 && currentColumn + 1 >= 0))
	{
		_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow + 2][currentColumn + 1]);
	}

	// _| movement
	if ((currentRow + 2 < 8 && currentRow + 2 >= 0) && (currentColumn - 1 < 8 && currentColumn - 1 >= 0))
	{
		_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow + 2][currentColumn - 1]);
	}

	//___  m v m n
	//  |   o e e t
	if ((currentRow + 1 < 8 && currentRow + 1 >= 0) && (currentColumn + 2 < 8 && currentColumn + 2 >= 0))
	{
		_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow + 1][currentColumn + 2]);
	}

	// ____  movement
	//|
	if ((currentRow + 1 < 8 && currentRow + 1 >= 0) && (currentColumn - 2 < 8 && currentColumn - 2 >= 0))
	{
		_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow + 1][currentColumn - 2]);
	}

	//___| movement
	if ((currentRow - 1 < 8 && currentRow - 1 >= 0) && (currentColumn + 2 < 8 && currentColumn + 2 >= 0))
	{
		_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow - 1][currentColumn + 2]);
	}

	// |___ movement
	if ((currentRow - 1 < 8 && currentRow - 1 >= 0) && (currentColumn - 2 < 8 && currentColumn - 2 >= 0))
	{
		_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow - 1][currentColumn - 2]);
	}

	// _     movement
	//  |
	if ((currentRow - 2 < 8 && currentRow - 2 >= 0) && (currentColumn - 1 < 8 && currentColumn - 1 >= 0))
	{
		_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow - 2][currentColumn - 1]);
	}

	//  __
	// |
	if ((currentRow - 2 < 8 && currentRow - 2 >= 0) && (currentColumn + 1 < 8 && currentColumn + 1 >= 0))
	{
		_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow - 2][currentColumn + 1]);
	}
	


}
