/*********************************************************************
Program Filename: point.h
Author: Ian Kronquist
Date: 2013-12-31
Description: Defines and implements a class which represents a point
	on the board. Essentially just an x,y pair.
********************************************************************/

#ifndef POINT_H
#define POINT_H
#include <assert.h>
/***********************************************************
Class: Point
Description: A simple datastructure representing an x,y
	pair on the board. and a simple constructor.
**********************************************************/ 
class Point
{
	public:
        /***********************************************************
	Constructor: Point
        Description: Assigns the given values to the Point's x and
		y values. Asserts that the given values are proper.
        Parameters: Two integers which should be less than or 
		equal to 2 and greater than or equal to 0
        **********************************************************/ 
	Point(int xInput, int yInput)
	{
		assert(xInput >= 0 && xInput <= 2);
		assert(yInput >= 0 && yInput <= 2);
		this->x = xInput;
		this->y = yInput;
	}

	int x;
	int y;
};

#endif

