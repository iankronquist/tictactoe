/*********************************************************************
Program Filename: ai.cpp 
Author: Ian Kronquist
Date: 2013-12-31
Description: Implements an algorithm to play tic-tac-toe which 
	subclasses player.
********************************************************************/

#include "ai.hpp"
#include <stdio.h>

Ai::Ai(BoardModel* boardIn)
{
	board = boardIn;
}

Point Ai::makeMove(Point lastMove)
{
	// If there will be an imminent victory play there
	// to block/win
	try
	{
		Point move = checkForImminentVictory(lastMove);
		return move;
	}
	// If not, do nothing
	catch(NoImminentVictoryException* e)
	{}
	// Else play at a random point.
	Point move = getRandomPoint();
	return move;
}

Point Ai::checkForImminentVictory(Point lastPlay)
{
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			Point test(x, y);
			if(board->getPoint(test) == 0 && 
				board->checkForAdjacentDoubles(test))
			{
				return test;
			}
		}
	}
	throw new NoImminentVictoryException();
}

Point Ai::getRandomPoint()
{
	Point p(0,0);
	// seed the prng with the system time
	srand(time(0));
	do
	{
		p.x = rand() % 3;
		p.y = rand() % 3;
	}
	while(board->getPoint(p) != 0);
	return p;
}

