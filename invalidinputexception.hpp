/*********************************************************************
Program Filename: invalidinputexception.h 
Author: Ian Kronquist
Date: 2013-12-31
Description: defines and implements an exception class user when
	the user inputs an invalid string to represent a pair of 
	points
********************************************************************/
#include <exception>
using namespace std;

/*********************************************************************
** Class: InvalidInputException
** Description: Thrown when the user inputs a pair of points not in 
	the form x,y i.e. 1,2
*********************************************************************/ 
class InvalidInputException: public exception
{
	// A non-pure virtual method which simply
	// returns a message saying what caused the exception.
        virtual const char* what() const throw()
        {
                return "Data must be input in the form x,y where x and y are "
			"integers between 0 and 2";
        }    
};
