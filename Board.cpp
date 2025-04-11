#include "Bishop.h"
#include "Board.h"
#include "ChessException.h"
#include "NullPiece.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"

Board::Board(char board[66])
{
	int counter = 0;
	int nullCounter = 0;
	for (int i = 0; i < 64; i++)
	{
		if (board[i] == 'R')
		{
			this->_boardState[0][0] = new Rook("R", _boardIndexName[0][0]);
			this->_boardState[0][7] = new Rook("R", _boardIndexName[0][7]);
		}
		else if (board[i] == 'N')
		{
			this->_boardState[0][1] = new Knight("N", _boardIndexName[0][1]);
			this->_boardState[0][6] = new Knight("N", _boardIndexName[0][6]);
		}
		else if (board[i] == 'B')
		{
			this->_boardState[0][2] = new Bishop("B", _boardIndexName[0][2]);
			this->_boardState[0][5] = new Bishop("B", _boardIndexName[0][5]);
		}
		else if (board[i] == 'K')
		{
			this->_boardState[0][4] = new King("K", _boardIndexName[0][4]);
		}
		else if (board[i] == 'Q')
		{
			this->_boardState[0][3] = new Queen("Q", _boardIndexName[0][3]);
		}
		else if (board[i] == 'P')
		{
			if (counter == 0)
			{
				for (int i = 0; i < COLUMNS; i++) 
				{
					this->_boardState[1][i] = new Pawn("P", _boardIndexName[1][i]);
				}
			}
			counter += 1;
		}
		
		//Black Pieces:
		if (board[i] == 'r')
		{
			this->_boardState[7][0] = new Rook("r", _boardIndexName[7][0]);
			this->_boardState[7][7] = new Rook("r", _boardIndexName[7][7]);
		}
		else if (board[i] == 'n')
		{
			this->_boardState[7][1] = new Knight("n", _boardIndexName[7][1]);
			this->_boardState[7][6] = new Knight("n", _boardIndexName[7][6]);
		}
		else if (board[i] == 'q')
		{
			this->_boardState[7][3] = new Queen("q", _boardIndexName[7][3]);
		}
		else if (board[i] == 'k')
		{
			this->_boardState[7][4] = new King("k", _boardIndexName[7][4]);
		}
		else if (board[i] == 'b')
		{
			this->_boardState[7][5] = new Bishop("b", _boardIndexName[7][5]);
			this->_boardState[7][2] = new Bishop("b", _boardIndexName[7][2]);
		}
		else if (board[i] == 'p')
		{
			if (counter == 1)
			{
				for (int i = 0; i < COLUMNS; i++) 
				{
					this->_boardState[6][i] = new Pawn("p", _boardIndexName[6][i]);
				}
			}
		}

		//NullPieces:
		for (int row = 2; row < 6; row++)
		{
			for (int col = 0; col < COLUMNS; col++)
			{
				this->_boardState[row][col] = new NullPiece("#", _boardIndexName[row][col]);
			}
		}
	}
}
Board::Board()
{
	// White pieces
	this->_boardState[0][0] = new Rook("R", _boardIndexName[0][0]);
	this->_boardState[0][1] = new Knight("N", _boardIndexName[0][1]);
	this->_boardState[0][2] = new Bishop("B", _boardIndexName[0][2]);
	this->_boardState[0][3] = new Queen("Q", _boardIndexName[0][3]);
	this->_boardState[0][4] = new King("K", _boardIndexName[0][4]);
	this->_boardState[0][5] = new Bishop("B", _boardIndexName[0][5]);
	this->_boardState[0][6] = new Knight("N", _boardIndexName[0][6]);
	this->_boardState[0][7] = new Rook("R", _boardIndexName[0][7]);

	for(int current = 0; current < COLUMNS; current++){
		this->_boardState[1][current] = new Pawn("P", _boardIndexName[1][current]);
	}

	// Empty spots 
	for(int row = 2; row < 6; row++)
	{
		for (int col = 0; col < COLUMNS; col++)
		{
			this->_boardState[row][col] = new NullPiece("#", _boardIndexName[row][col]);
		}
	}

	// Black pieces
	this->_boardState[7][0] = new Rook("r", _boardIndexName[7][0]);
	this->_boardState[7][1] = new Knight("n", _boardIndexName[7][1]);
	this->_boardState[7][2] = new Bishop("b", _boardIndexName[7][2]);
	this->_boardState[7][3] = new Queen("q", _boardIndexName[7][3]);
	this->_boardState[7][4] = new King("k", _boardIndexName[7][4]);
	this->_boardState[7][5] = new Bishop("b", _boardIndexName[7][5]);
	this->_boardState[7][6] = new Knight("n", _boardIndexName[7][6]);
	this->_boardState[7][7] = new Rook("r", _boardIndexName[7][7]);

	for (int current = 0; current < COLUMNS; current++) {
		this->_boardState[6][current] = new Pawn("p", _boardIndexName[6][current]);
	}

	
}

Board::~Board()
{
	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLUMNS; col++)
		{
			delete this->_boardState[row][col];   // delete all pieces
		}
	}
}

void Board::printBoard()
{
	for (int row = 0; row < ROWS; row++) {
		for (int col = 0; col < COLUMNS; col++) {
			std::cout << this->_boardState[row][col]->getType()[0] << " ";

		}
		std::cout << "\n";
	}
}
int Board::Check()
{
	string whiteKingPosition;
	string blackKingPosition;
	string currentPosition;

	int currentRow, currentColumn;
	int checkAns = 0;  // the returned value

	bool breakVarible = false;   // this helps us in the loops to get every thing done correctly

	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLUMNS; col++)
		{
			// white king position
			if (this->_boardState[row][col]->getType() == "K")
			{
				whiteKingPosition = _boardIndexName[row][col];
			}

			// black king position 
			if (this->_boardState[row][col]->getType() == "k")
			{
				blackKingPosition = _boardIndexName[row][col];
			}
		}
	}

	for (int row = 0; row < ROWS; row++)
	{
		if (breakVarible)
		{
			break;
		}
		for (int col = 0; col < COLUMNS; col++)
		{
			if (breakVarible)
			{
				break;
			}

			this->_boardState[row][col]->pieceMovement(_boardIndexName[row][col], this);

			for (unsigned int current = 0; current < this->_boardState[row][col]->getAvaliblePositionsVector().size(); current++)
			{
				// check for the white king piece
				if (islower(this->_boardState[row][col]->getType()[0]))
				{
					if (this->_boardState[row][col]->getAvaliblePositionsVector()[current] == whiteKingPosition)
					{
						currentRow = row;
						currentColumn = col;
						currentPosition = _boardIndexName[row][col];
						checkAns = 1;

						_checkPositions.push_back(currentPosition);
						CheckVectorPositions(currentPosition, whiteKingPosition, currentRow, currentColumn, this->_boardState[currentRow][currentColumn]->getType());

						breakVarible = true; // if there is chess, get out of the outer loop and the more outside loop
					}
				}
				//check for the black king piece
				if (isupper(this->_boardState[row][col]->getType()[0]))
				{
					if (this->_boardState[row][col]->getAvaliblePositionsVector()[current] == blackKingPosition) {
						currentRow = row;
						currentColumn = col;
						currentPosition = _boardIndexName[row][col];
						
						_checkPositions.push_back(currentPosition);
						CheckVectorPositions(currentPosition, whiteKingPosition, currentRow, currentColumn, this->_boardState[currentRow][currentColumn]->getType());

						checkAns = 2;
						breakVarible = true;   // same as before
					}
				}
			}
		}
	}
	return checkAns;  // if 0-> no chess, if 1-> white chess, if 2-> black chess
}

/*
	This function moves the pieces after command from the graphics, and check if everything is ok
*/
string Board::movePiece(string movment, bool whiteTurn)
{
	//movment = "a8b7" --- currentPosition = "a8", goToPosition = "b8"
	string currentPosition = movment.substr(0, 2);
	string goToPosition = movment.substr(2, 2);

	int currentRow = 0, currentColumn = 0;
	int goToRow = 0, goToColumn = 0;
	string returnedValue = "6";
	bool tnay = false;

	// get the indexes of the current place of the piece and the place it's going to 
	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLUMNS; col++)
		{
			if (_boardIndexName[row][col] == currentPosition)
			{
				currentRow = row;
				currentColumn = col;
			}
			if (_boardIndexName[row][col] == goToPosition)
			{
				goToRow = row;
				goToColumn = col;
			}
		}
	}

	// this condition checks if the player is playing his turn
	if ((whiteTurn && isupper(this->_boardState[currentRow][currentColumn]->getType()[0])) || (!whiteTurn && islower(this->_boardState[currentRow][currentColumn]->getType()[0])))
	{
		try
		{
			// check if the movement is correct
			tnay = this->_boardState[currentRow][currentColumn]->checkMoving(movment, this);
		}
		catch (ChessException e)
		{
			returnedValue = e.what();
		}


		if (tnay)
		{
			// helpers
			bool helpingBool;
			Piece* tempPtr = nullptr;

			// move the piece
			if (this->_boardState[goToRow][goToColumn]->getType() == "#")
			{
				Piece* temp = this->_boardState[currentRow][currentColumn];
				this->_boardState[currentRow][currentColumn] = this->_boardState[goToRow][goToColumn];
				this->_boardState[goToRow][goToColumn] = temp;
				helpingBool = true;
			}
			else // if the space is not empty, then the space we're going to has an enemy piece, so we eat it
			{
				tempPtr = this->_boardState[goToRow][goToColumn];
				this->_boardState[goToRow][goToColumn] = nullptr;
				this->_boardState[goToRow][goToColumn] = this->_boardState[currentRow][currentColumn];
				this->_boardState[currentRow][currentColumn] = new NullPiece("#", _boardIndexName[currentRow][currentColumn]);
			}
			returnedValue = "0"; // correct move 

			if (Check() != NO_CHECK)
			{
				returnedValue = "1"; // chess has been made
				delete tempPtr; 

				if (CheckMate(currentRow, currentColumn))
				{
					returnedValue = "8";
				}
			}

			// if the player is making a move that would still put his king in danger 
			if((Check() == WHITE_CHECK && whiteTurn) || (Check() == BLACK_CHECK && !whiteTurn)) 
			{
				// we undo the movement
				if (helpingBool)
				{
					// if was #
					Piece* temp = this->_boardState[currentRow][currentColumn];
					this->_boardState[currentRow][currentColumn] = this->_boardState[goToRow][goToColumn];
					this->_boardState[goToRow][goToColumn] = temp;
				}
				else
				{
					//if anything has been eaten
					Piece* temp = this->_boardState[currentRow][currentColumn];
					this->_boardState[currentRow][currentColumn] = tempPtr;
					this->_boardState[goToRow][goToColumn] = temp;
				}
				returnedValue = "4";
				if (CheckMate(currentRow, currentColumn))
				{
					returnedValue = "8";
				}
			}
		
		}
		else
		{
			if (returnedValue == "6")
			{
				returnedValue = "6";
			}
		}
	}
	else
	{
		returnedValue = "2";
	}

	return returnedValue;
}


bool Board::CheckMate(int currentRow, int currentColumn)
{
	bool checkMate = false;

	if (_checkPositions.size() < this->_boardState[currentRow][currentColumn]->getAvaliblePositionsVector().size())
	{
		_checkPositions.resize(this->_boardState[currentRow][currentColumn]->getAvaliblePositionsVector().size());
	}

	if(_checkPositions.size() > this->_boardState[currentRow][currentColumn]->getAvaliblePositionsVector().size())
	{
		this->_boardState[currentRow][currentColumn]->getAvaliblePositionsVector().resize(_checkPositions.size());
	}


	for (unsigned int currentAvaliblePositionsVector = 0; currentAvaliblePositionsVector < this->_boardState[currentRow][currentColumn]->getAvaliblePositionsVector().size(); currentAvaliblePositionsVector++)
	{
		for (unsigned int currentCheckPositionsVector = 0; currentCheckPositionsVector < _checkPositions.size(); currentCheckPositionsVector++)
		{
			if (_checkPositions[currentCheckPositionsVector] == this->_boardState[currentRow][currentColumn]->getAvaliblePositionsVector()[currentAvaliblePositionsVector])
			{
				checkMate = true;
			}
		}
	}

	return checkMate;
}


void Board::CheckVectorPositions(string currentPosition, string kingPosition, int currentRow, int currentColumn, string type)
{
	int kingRow, kingColumn;

	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLUMNS; col++)
		{
			// white king row and column
			if (_boardIndexName[row][col] == kingPosition)
			{
				kingRow = row;
				kingColumn = col;
			}
		}
	}

	if (islower(type[0])) //black check to white 
	{
		if ( (type == "r") || (type == "q"))
		{
			if ((kingRow == currentRow) && (kingColumn > currentColumn))
			{
				for (int current = currentRow; current < kingRow; current++)
				{
					_checkPositions.push_back(_boardIndexName[currentRow][current]);
				}
			}

			if ((kingRow == currentRow) && (kingColumn < currentColumn))
			{
				for (int current = kingRow; current < currentColumn; current++)
				{
					_checkPositions.push_back(_boardIndexName[currentRow][current]);
				}
			}

			if ((kingRow > currentRow) && (kingColumn == currentColumn))
			{
				for (int current = currentRow; current < kingRow; current++)
				{
					_checkPositions.push_back(_boardIndexName[current][currentColumn]);
				}
			}

			if ((kingRow < currentRow) && (kingColumn == currentColumn))
			{
				for (int current = kingRow; current < currentRow; current++)
				{
					_checkPositions.push_back(_boardIndexName[current][currentColumn]);
				}
			}
		}

		if ((type == "b") || (type == "q"))
		{
			if ((kingRow > currentRow) && (kingColumn < currentColumn))
			{
				for (int row = currentRow; row < kingRow; row++)
				{
					for (int col = kingColumn; col < currentColumn; col++)
					{
						_checkPositions.push_back(_boardIndexName[row][col]);
					}
				}
			}

			if ((kingRow < currentRow) && (kingColumn < currentColumn))
			{
				for (int row = kingRow; row < currentRow; row++)
				{
					for (int col = kingColumn; col < currentColumn; col++)
					{
						_checkPositions.push_back(_boardIndexName[row][col]);
					}
				}
			}

			if ((kingRow > currentRow) && (kingColumn > currentColumn))
			{
				for (int row = currentRow; row < kingRow; row++)
				{
					for (int col = currentColumn; col < kingColumn; col++)
					{
						_checkPositions.push_back(_boardIndexName[row][col]);
					}
				}
			}

			if ((kingRow < currentRow) && (kingColumn > currentColumn))
			{
				for (int row = kingRow; row < currentRow; row++)
				{
					for (int col = currentColumn; col < kingColumn; col++)
					{
						_checkPositions.push_back(_boardIndexName[row][col]);
					}
				}
			}
		}
	}
}
