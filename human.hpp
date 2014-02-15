/*********************************************************************
Program Filename: human.h
Author: Ian Kronquist
Date: 2013-12-31
Description: Defines a class subclassing player which gets and
	validates a point on the board qhich the user chooses.
********************************************************************/

#include <iostream>
#include "inputControl.h"
#include "invalidinputexception.h"
#include "player.h"
#include <string>

using namespace std;

class Human : public Player
{	
	public:

	/***********************************************************
	Constructor: Human
	Description: Initilizes the pointer to the board model
	Parameters: A pointer to the board model.
	***********************************************************/ 	
	Human(BoardModel* boardIn);
	
	/***********************************************************
	Function: makeMove
	Description: Asks the user for the move they would like to
		make as two numbers separated by commas.
		Returns a point representing the move the user 
		would like to make.
	Parameters: A Point representing the last move.
	Pre-Conditions: The lastMove Point is valid.
	Post-Conditions: The returned Point is valid.
	***********************************************************/ 	
	Point makeMove(Point lastMove);
	
	private:

	/***********************************************************
	Function: getPointFromUser
	Description: Actually gets the point from the user. Does 
		the input validation and parsing of the user
		submitted data.
	Parameters: None.
	Pre-Conditions: None.
	Post-Conditions: The returned Point is valid.
	***********************************************************/ 	
	Point getPointFromUser();

	/***********************************************************
	Function: validateString
	Description: validates and parses the string provided by the
		user. Can throw an InvalidInputException.
	Parameters: None.
	Pre-Conditions: None.
	Post-Conditions: The returned Point is valid.
	***********************************************************/ 	
	Point validateData(string number);
};
