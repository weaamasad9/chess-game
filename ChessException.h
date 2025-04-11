#pragma once

#include <iostream>
#include <exception>
#include <string>

using std::exception;
using std::string;

class ChessException : public exception
{
public:
	ChessException(string Msg);
	~ChessException();
	string what();

private:
	string _msg;
};
