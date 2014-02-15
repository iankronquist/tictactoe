/*********************************************************************
Program Filename: noimminentvictoryexception.h
Author: Ian Kronquist
Date: 2013-12-31
Description: Implements and defines an exception class which 
	triggers when there is no imminent victory for either 
	player. Unlike many exceptions this is not an error but a 
	form of flow control.
********************************************************************/

#include <exception>
using namespace std;
/*********************************************************************
Class: NoImminentVictoryException
Description: Thrown when there is no imminent victory. Unlike most
	exceptions, this is not an error, it is instead used for 
	flow control.
*********************************************************************/ 
class NoImminentVictoryException: public exception
{
	/***********************************************************
	Function: what
	Description: Returns a message detailing what caused the
		exception.
	Parameters: None.
	Pre-Conditions: None.
	Post-Conditions: None.
	**********************************************************/ 
        virtual const char* what() const throw()
        {
                return "No imminent victory";
        }    
};
