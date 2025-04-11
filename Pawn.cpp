#include "Pawn.h"
#include "NullPiece.h"
#include "ChessException.h"
#include <cmath>

Pawn::Pawn(string type, string position) : Piece(type, position) {
}


Pawn::~Pawn()
{
	Piece::~Piece();
}


bool Pawn::checkMoving(string movment, Board* chessBoard)
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
	
	if (abs(currentRow - goToRow) == 2) {
		_avaliblePositions.erase(_avaliblePositions.begin());
	}

	for (unsigned int current = 0; current < _avaliblePositions.size(); current++)
	{	

		if ((isupper(chessBoard->_boardState[currentRow][currentColumn]->getType()[0]) && isupper(chessBoard->_boardState[goToRow][goToColumn]->getType()[0]))
			|| (islower(chessBoard->_boardState[currentRow][currentColumn]->getType()[0]) && islower(chessBoard->_boardState[goToRow][goToColumn]->getType()[0])))
		{
			throw(ChessException("3"));
			ans = false;
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


void Pawn::pieceMovement(string currentPosition, Board* chessBoard)
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

	// White Pawn piece
	if (isupper(chessBoard->_boardState[currentRow][currentColumn]->getType()[0]))
	{

		if (currentRow == 1) {
			if (chessBoard->_boardState[currentRow + 1][currentColumn]->getType() == "#" )
			{
				_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow + 1][currentColumn]); // down
			}	
			if (chessBoard->_boardState[currentRow + 2][currentColumn]->getType() == "#")
			{
				_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow + 2][currentColumn]); // down two step
			}
		}
		else {
			if (chessBoard->_boardState[currentRow + 1][currentColumn]->getType() == "#")
			{
				_avaliblePositions.clear();
				_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow + 1][currentColumn]); // down
			}
		}

		// eating part
		if (currentColumn == 0) {
			if (islower(chessBoard->_boardState[currentRow + 1][currentColumn + 1]->getType()[0])) {
				_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow + 1][currentColumn + 1]);
			}
		}
		else if (currentColumn == 7) {
			if (islower(chessBoard->_boardState[currentRow + 1][currentColumn - 1]->getType()[0])) {
				_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow + 1][currentColumn - 1]);
			}
		}

		else if (currentColumn > 0 && currentColumn < 7) {
			if (islower(chessBoard->_boardState[currentRow + 1][currentColumn + 1]->getType()[0])) {
				_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow + 1][currentColumn + 1]);
			}
			if (islower(chessBoard->_boardState[currentRow + 1][currentColumn - 1]->getType()[0])) {
				_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow + 1][currentColumn - 1]);
			}
		}
	}


	// Black Pawn piece
	if (islower(chessBoard->_boardState[currentRow][currentColumn]->getType()[0])) {
		if (currentRow == 6) {
			if (chessBoard->_boardState[currentRow - 1][currentColumn]->getType() == "#")
			{
				_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow - 1][currentColumn]); // down
			}
			if (chessBoard->_boardState[currentRow - 2][currentColumn]->getType() == "#")
			{
				_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow - 2][currentColumn]);
			}// down two step
		}
		else {
			if (chessBoard->_boardState[currentRow - 1][currentColumn]->getType() == "#")
			{
				_avaliblePositions.clear();  // to clear the vector  
				_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow - 1][currentColumn]);// down
			}
		}


	// eating part
		if (currentColumn == 0) {
			if (isupper(chessBoard->_boardState[currentRow - 1][currentColumn + 1]->getType()[0])) {
				_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow - 1][currentColumn + 1]);
			}
		}
		else if (currentColumn == 7) {
			if (isupper(chessBoard->_boardState[currentRow - 1][currentColumn - 1]->getType()[0])) {
				_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow - 1][currentColumn - 1]);
			}
		}

		else if (currentColumn > 0 && currentColumn < 7) {
			if (isupper(chessBoard->_boardState[currentRow - 1][currentColumn + 1]->getType()[0])) {
				_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow - 1][currentColumn + 1]);
			}
			if (isupper(chessBoard->_boardState[currentRow - 1][currentColumn - 1]->getType()[0])) {
				_avaliblePositions.push_back(chessBoard->_boardIndexName[currentRow - 1][currentColumn - 1]);
			}
		}
	}
}

