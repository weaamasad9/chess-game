#include "Queen.h"
#include "NullPiece.h"
#include "ChessException.h"

Queen::Queen(string type, string position) : Piece(type, position)
{
}

Queen::~Queen()
{
	Piece::~Piece();
}


bool Queen::checkMoving(string movment, Board* chessBoard)
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
			}
			if (chessBoard->_boardIndexName[row][col] == goToPosition)
			{
				goToRow = row;
				goToColumn = col;
			}
		}
	}

	for (unsigned int current = 0; current < _avaliblePositions.size(); current++)
	{
		// check if the same color
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
			ans = false;
		}
	}

	return ans;
}

void Queen::pieceMovement(string currentPosition, Board* chessBoard)
{
	_avaliblePositions = CrossMovment(currentPosition, chessBoard);
	vector<string> helpingVector = Xmovment(currentPosition, chessBoard);

	for (unsigned int i = 0; i < helpingVector.size(); i++) {
		_avaliblePositions.push_back(helpingVector[i]);
	}
}


// gives us the movement of +
vector<string> Queen::CrossMovment(string currentPosition, Board* chessBoard)
{
	int currentRow = 0, currentColumn = 0;
	vector<string> realAvaliblePositions;

	// this opiration gives us the index of the position
	for(int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLUMNS; col++)
		{ 
			if ( chessBoard->_boardIndexName[row][col] == currentPosition )
			{
				currentRow = row;
				currentColumn = col;
				break;
			}
		}
	}


	// upwards
	if (currentRow - 1 >= 0)
	{
		for (int row = currentRow - 1; row >= 0; row--)
		{
			if (chessBoard->_boardState[row][currentColumn]->getType()[0] != '#')
			{
				realAvaliblePositions.push_back(chessBoard->_boardIndexName[row][currentColumn]);
				break;
			}
			else
			{
				realAvaliblePositions.push_back(chessBoard->_boardIndexName[row][currentColumn]);
			}
		}
	}


	// downwards
	if (currentRow + 1 < 8)
	{
		for (int row = currentRow + 1; row < 8; row++)
		{
			if (chessBoard->_boardState[row][currentColumn]->getType()[0] != '#') {
				realAvaliblePositions.push_back(chessBoard->_boardIndexName[row][currentColumn]);
				break;
			}
			else
			{
				realAvaliblePositions.push_back(chessBoard->_boardIndexName[row][currentColumn]);
			}
		}
	}


	// rightSide
	if (currentColumn + 1 < 8)
	{
		for (int col = currentColumn + 1; col < 8; col++)
		{
			if (chessBoard->_boardState[currentRow][col]->getType()[0] != '#') {
				realAvaliblePositions.push_back(chessBoard->_boardIndexName[currentRow][col]);
				break;
			}
			else
			{
				realAvaliblePositions.push_back(chessBoard->_boardIndexName[currentRow][col]);
			}
		}
	}


	// leftSide
	if (currentColumn - 1 >= 0)
	{
		for (int col = currentColumn - 1; col >= 0; col--)
		{
			if (chessBoard->_boardState[currentRow][col]->getType()[0] != '#') {
				realAvaliblePositions.push_back(chessBoard->_boardIndexName[currentRow][col]);
				break;
			}
			else
			{
				realAvaliblePositions.push_back(chessBoard->_boardIndexName[currentRow][col]);
			}
		}
	}

	return vector<string>(realAvaliblePositions);
}

// gives us the movement of X
vector<string> Queen::Xmovment(string currentPosition, Board* chessBoard)
{
	int currentRow = 0, currentColumn = 0;
	vector<string> realAvaliblePositions;
	bool breakVar = false;
	int count = 1;
	// this opiration gives us the index of the position
	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLUMNS; col++)
		{
			if (chessBoard->_boardIndexName[row][col] == currentPosition)
			{
				currentRow = row;
				currentColumn = col;
			}
		}
	}

	// upRight 
	for (int row = currentRow - 1; row >= 0; row--) 
	{
		
		if (breakVar == true)
		{
			break;
		}

		for (int col = currentColumn + count; col < 8; col++)
		{
			if (chessBoard->_boardState[row][col]->getType()[0] != '#')
			{
				realAvaliblePositions.push_back(chessBoard->_boardIndexName[row][col]);
				breakVar = true;
				break;
			}
			else
			{
				realAvaliblePositions.push_back(chessBoard->_boardIndexName[row][col]);
				break;
			}
		}
		count++;
	}
	breakVar = false;

	count = 1;
	// upLeft
	for (int row = currentRow-1; row >= 0; row--)
	{
		if (breakVar == true)
		{
			break;
		}

		for (int col = currentColumn - count; col >= 0; col--)
		{
			if (chessBoard->_boardState[row][col]->getType()[0] != '#')
			{
				realAvaliblePositions.push_back(chessBoard->_boardIndexName[row][col]);
				breakVar = true;
				break;
			}
			else
			{
				realAvaliblePositions.push_back(chessBoard->_boardIndexName[row][col]);
				break;
			}
		}
		count++;
	}
	breakVar = false;

	//downRight
	count = 1;
	for (int row = currentRow + 1; row < 8; row++)
	{
		
		if (breakVar == true)
		{
			break;
		}

		for (int col = currentColumn + count; col < 8; col++)
		{
			if (chessBoard->_boardState[row][col]->getType()[0] != '#')
			{
				realAvaliblePositions.push_back(chessBoard->_boardIndexName[row][col]);
				breakVar = true;
				break;
			}
			else
			{
				realAvaliblePositions.push_back(chessBoard->_boardIndexName[row][col]);
				break;
			}
		}
		count++;
	}
	breakVar = false;

	count = 1;
	//downLeft
	for (int row = currentRow + 1; row < 8; row++)
	{
		if (breakVar == true)
		{
			break;
		}

		for (int col = currentColumn - count; col >= 0; col--)
		{
			if (chessBoard->_boardState[row][col]->getType()[0] != '#')
			{
				realAvaliblePositions.push_back(chessBoard->_boardIndexName[row][col]);
				breakVar = true;
				break;
			}
			else
			{
				realAvaliblePositions.push_back(chessBoard->_boardIndexName[row][col]);
				break;
			}
		}
		count++;
	}
	breakVar = false;

	return (realAvaliblePositions);
}
