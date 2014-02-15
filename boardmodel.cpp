/*********************************************************************
Program Filename: boardmodel.cpp
Author: Ian Kronquist
Date: 2013-12-31
Description: Implements a class which includes a datastructure to 
	represent a tic tac toe board, as well as common operations
	on this board.
********************************************************************/

#ifndef BOARDMODEL_CPP
#define BOARDMODEL_CPP
#include "boardmodel.h"
#include <stdio.h>

BoardModel::BoardModel(){}

BoardModel::~BoardModel(){}

void BoardModel::clearBoard()
{
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			board[y][x] = 0;
		}
	}
}

void BoardModel::play(Point p, int player)
{
	using namespace std;
	assert(player == 1 || player == 2);
	//assert(board[p.y][p.x] == 0);
	if(board[p.y][p.x] != 0)
	{
		throw new InvalidSquareException();
	}
	if(board[p.y][p.x] != 0)
	{
		assert(0);
	}
	board[p.y][p.x] = player;
}

bool BoardModel::checkForDraw()
{
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			if(board[x][y] == 0)
			{
				return false;
			}
		}
	}
	return true;
}

int BoardModel::checkForVictory(Point lastPlay)
{
	// If point is on the L to R diagonal
	if(lastPlay.x == lastPlay.y)
	{
		// If all the L to R diagonal points are the same,
		// we have a victor.
		if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
		{
			return board[lastPlay.y][lastPlay.x];
		}
	}
	// If the point is on the R to L diagonal
	if(lastPlay.x + lastPlay.y == 2)
	{
		// If all the R to L points are the same, 
		// we have a victor
		if(board[2][0] == board[1][1] && board[2][0] == board[0][2])
		{
			return board[lastPlay.y][lastPlay.x];
		}
	}
	// If all the points on that horizontal row are the same
	// we have a victor
	if(board[lastPlay.y][0] == board[lastPlay.y][1] && 
		board[lastPlay.y][0] == board[lastPlay.y][2])
	{
			return board[lastPlay.y][lastPlay.x];
	} 
	// If all the points on that vertical row are the same
	// we have a victor
	if(board[0][lastPlay.x] == board[1][lastPlay.x] && 
		board[0][lastPlay.x] == board[2][lastPlay.x])
	{
			return board[lastPlay.y][lastPlay.x];
	} 
	// Otherwise nobody, AKA player 0, won.
	return 0;
}

bool BoardModel::checkForAdjacentDoubles(Point lastPlay)
{
	// this should be an exception, not an assertion
	assert(getPoint(lastPlay) == 0);
	// If point is on the L to R diagonal
	if(lastPlay.x == lastPlay.y)
	{
		if(board[(lastPlay.y + 1) % 3][(lastPlay.x + 1) % 3] ==
			board[(lastPlay.y + 2) % 3][(lastPlay.x + 2) % 3] && 
			board[(lastPlay.y + 1) % 3][(lastPlay.x + 1) % 3] != 0)
		{
			return true;
		}
	}
	// If the point is on the R to L diagonal
	if(lastPlay.x + lastPlay.y == 2)
	{
		if(board[(lastPlay.y + 1) % 3][(lastPlay.x - 1) % 3] ==
			board[(lastPlay.y + 2) % 3][(lastPlay.x - 2) % 3] &&
			board[(lastPlay.y + 1) % 3][(lastPlay.x - 1) % 3] != 0)
		{
			return true;
		}
	}
	// If there are adjacent vertical points
	if(board[lastPlay.y][(lastPlay.x + 1) % 3] == 
		board[lastPlay.y][(lastPlay.x + 2) % 3] &&
		board[lastPlay.y][(lastPlay.x + 1) % 3] != 0)
	{
		return true;
	}
	// If there are adjacent horizontal points
	if(board[(lastPlay.y + 1) % 3][lastPlay.x] == 
		board[(lastPlay.y + 2) % 3][lastPlay.x] && 
		board[(lastPlay.y + 1) % 3][lastPlay.x] != 0)
	{
		return true;
	}
	// If none of those conditions are true.
	return false;
}

int BoardModel::getPoint(Point p)
{
	assert(p.x < 3 && p.y < 3 && p.x >= 0 && p.y >= 0);
	return board[p.y][p.x];
}

#endif

