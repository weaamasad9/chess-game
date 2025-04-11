#include "King.h"
#include "NullPiece.h"
#include "ChessException.h"

King::King(string type, string position) : Piece(type, position)
{
}

King::~King()
{
	Piece::~Piece();
}

bool King::checkMoving(string movment, Board *chessBoard)
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
		if((isupper(chessBoard->_boardState[currentRow][currentColumn]->getType()[0]) && isupper(chessBoard->_boardState[goToRow][goToColumn]->getType()[0]))
			|| (islower(chessBoard->_boardState[currentRow][currentColumn]->getType()[0]) && islower(chessBoard->_boardState[goToRow][goToColumn]->getType()[0])))
		{
			ans = false;
			throw(ChessException("3"));
			break;
		}
		else
		{
			if (_avaliblePositions[current] == goToPosition)
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
	}
	return ans;
}



void King::pieceMovement(string currentPosition, Board *chessBoard) 
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
			}
		}
	}

	/*
		in these opirations we check every single possibility of movment the king has, 
		whether he's in the corners or in the center or any other thing   
	*/

	// move down one step or left or right or diameter
	if (chessBoard->_boardState[currentRow][currentColumn]->getType() == "k" || chessBoard->_boardState[currentRow][currentColumn]->getType() == "K") {
		if (currentColumn == 0 && currentRow == 0) {
			_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow + 1][currentColumn]); // down
			_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow][currentColumn + 1]); // right
			_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow + 1][currentColumn + 1]); //diameter
		}

		else if (currentColumn == 7 && currentRow == 0) {
			_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow + 1][currentColumn]); // down
			_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow][currentColumn - 1]); // left
			_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow + 1][currentColumn - 1]); // Diameter
		}

		else if ((0 < currentColumn && currentColumn < 7) && (0 < currentRow && currentRow < 7)) {
			_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow + 1][currentColumn]); // down
			_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow - 1][currentColumn]); // up
			_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow][currentColumn + 1]); // right
			_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow][currentColumn - 1]); // left
			_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow - 1][currentColumn - 1]); // Diameter
			_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow + 1][currentColumn + 1]); // Diameter
			_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow - 1][currentColumn + 1]); // Diameter
			_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow + 1][currentColumn - 1]); // Diameter
		}

		else if (currentColumn == 0 && (0 < currentRow && currentRow < 7)) {
			_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow + 1][currentColumn]); // down
			_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow - 1][currentColumn]); // up
			_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow][currentColumn + 1]); // right
			_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow + 1][currentColumn + 1]); // Diameter
			_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow - 1][currentColumn + 1]); // Diameter
		}

		else if ((0 < currentColumn && currentColumn < 7 )&& currentRow == 0) {
			_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow + 1][currentColumn]); // down
			_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow][currentColumn + 1]); // right
			_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow][currentColumn - 1]); // left
			_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow + 1][currentColumn + 1]); // Diameter
			_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow + 1][currentColumn - 1]); // Diameter
		}

		else if (currentColumn == 7 && (0 < currentRow && currentRow < 7)) {
			_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow + 1][currentColumn]); // down
			_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow - 1][currentColumn]); // up
			_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow][currentColumn - 1]); // left
			_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow - 1][currentColumn - 1]); // Diameter
			_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow + 1][currentColumn - 1]); // Diameter
		}

		else if ((0 < currentColumn && currentColumn < 7) && currentRow == 7) {
			_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow][currentColumn + 1]); // right
			_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow][currentColumn - 1]); // left
			_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow - 1][currentColumn]); // up
			_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow - 1][currentColumn + 1]); // Diameter
			_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow - 1][currentColumn - 1]); // Diameter

		}

		else if (currentColumn == 0 && currentRow == 7) {
			_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow][currentColumn + 1]); // right
			_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow - 1][currentColumn]); // up
			_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow - 1][currentColumn + 1]); // Diameter
		}

		else if (currentColumn == 7 && currentRow == 7) {
			_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow][currentColumn - 1]); // left
			_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow - 1][currentColumn]); // up
			_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow - 1][currentColumn - 1]); // Diameter
		}
	}

}


