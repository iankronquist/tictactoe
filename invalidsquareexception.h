/*********************************************************************
Program Filename: invalidsquareexception.h
Author: Ian Kronquist
Date: 2013-12-31
Description: Defines and implements an exception class which is 
	thrown when a player (human or ai) trys to play on a square
	which has already been played.
********************************************************************/
#include <exception>
using namespace std;
/*********************************************************************
** Class: InvalidSquareException
** Description: Thrown when a player attempts to play on a square 
	which is != 0, that is it is not blank and is owned by a 
	player.
*********************************************************************/ 
class InvalidSquareException: public exception
{
	/***********************************************************
	Function: what
	Description: returns a message saying what caused the 
		exception.
	Parameters: None.
	Pre-Conditions: None.
	Post-Conditions: None.
	***********************************************************/ 
        virtual const char* what() const throw()
        {
                return "This square has already been played";
        }    
};
