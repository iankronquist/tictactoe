/********************************************************************
Program Filename: human.cpp
Author: Ian Kronquist
Date: 2013-12-31
Description: Implements a class which subclasses a player and gets
	and validates the point on the board which the user chooses
********************************************************************/

#include "human.h"
#include <iostream>

Human::Human(BoardModel* boardIn)
{
	board = boardIn;
}

Point Human::makeMove(Point lastMove)
{
	return getPointFromUser();
}

Point Human::getPointFromUser()
{
	Point p(0,0);
	string data;
	while(true)
	{
		cout << "Input a blank point in the form x,y" << endl;
		cin >> data;
		cleanupCin();
		try
		{
			p = validateData(data);
		}
		catch(InvalidInputException* e)
		{
			cout << "Invalid input. Must be like 1,2 or 2,0" << endl;
			continue;
		}
		if(board->getPoint(p) != 0)
		{
			cout << "Invalid point. Has already been played." << endl;
			continue;
		}
		else
		{
			break;
		}
	}
	std::cout << "human input xy "<< p.x << p.y << std::endl;
	return p;
}

Point Human::validateData(string data)
{
	if(data.length() != 3)
	{
		throw new InvalidInputException();
	}
	if(data[0] > '2' or data[0] < '0')
	{
		throw new InvalidInputException();
	}
	if(data[1] != ',')
	{
		throw new InvalidInputException();
	}
	if(data[2] > '2' or data[2] < '0')
	{
		throw new InvalidInputException();
	}
	return Point(data[2] - '0', data[0] - '0');

}

