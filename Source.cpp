#include "Pipe.h"
#include <iostream>
#include <thread>
#include <string>
#include "Piece.h"
#include "Board.h"
#include "ChessException.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;

void main()
{
	srand(time_t(NULL));

	
	Pipe p;
	bool isConnect = p.connect();
	
	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else 
		{
			p.close();
			return;
		}
	}
	

	char msgToGraphics[1024];
	// msgToGraphics should contain the board string accord the protocol

	strcpy_s(msgToGraphics, "RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr0"); // just example...
						  // RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr0   White starts
	                      //  rnbqkbnrpppppppp################################PPPPPPPPRNBQKBNR1  Black starts
	
	p.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();
	string protocolString;

	char protocolMSG[BUFFER_SIZE] = {};

	//Board* chessBoard = new Board;
	Board* chessBoard = new Board;
	int timesPlayed = 0;
	bool whiteTurn;

	while (msgFromGraphics != "quit")
	{
		
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)
		string currentPosition = msgFromGraphics.substr(0, 2);
		string goToPosition = msgFromGraphics.substr(2, 2);

		int currentRow = 0, currentColumn = 0;
		int goToRow = 0, goToColumn = 0;

		// this operation gives us the index of the position
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
					goToColumn = col;
					goToRow = row;
				}
			}
		}
		if (timesPlayed % 2 == 0)
		{
			whiteTurn = true;
		}
		else
		{
			whiteTurn = false;
		}

		try
		{
			protocolString = chessBoard->movePiece(msgFromGraphics, whiteTurn);		
		}
		catch (ChessException& e)
		{
			cout << e.what() << endl;
		}



		// Printing the board
		chessBoard->printBoard();

		for (unsigned int i = 0; i < protocolString.size(); i++)
		{
			protocolMSG[i] = protocolString[i];
		}

		p.sendMessageToGraphics(protocolMSG);

		// get the message from graphics
		msgFromGraphics = p.getMessageFromGraphics();

		if (protocolString == "0" || protocolString == "1")
		{
			timesPlayed++;
		}
	}

	p.close();
}