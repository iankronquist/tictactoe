/*********************************************************************
Program Filename: ai.hpp
Author: Ian Kronquist
Date: 2013-12-31
Description: Defines the interface for an algorithm to play tic-tac-toe which 
        subclasses player.
********************************************************************/

#include "point.hpp"
#include "boardmodel.cpp"
#include "player.hpp"
#include "noimminentvictoryexception.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std;

class Ai : public Player
{

	public:
	/****************************************
	Constructor: Ai
	Description: Constructs an Ai object.
		Takes a pointer to a board model.
	Parameters:
		A pointer to the board model.
	****************************************/ 
	Ai(BoardModel* boardIn);

	/************************************************************
	Function: makeMove
	Description: Implements the parent class player's makeMove
		method, called when it is this Ai's turn to make
		a move. Returns a Point object representing the 
		point where this Ai intends to move
	Parameters: A Point object representing the last move to be
		used when calculating the point where this Ai 
		intends to move.
	Pre-Conditions: Point must be a valid point.
	Post-Conditions: The returned Point will be a valid Point.
	**********************************************************/ 
	Point makeMove(Point lastMove);

	private:

	
	/************************************************************
	Function: checkForImminentVictory
	Description: Checks for imminent victory, that is a blank
		point where if this player moves he will either
		ensure his own victory or prevent his opponent's
	Parameters: A point representing the last play, which
		will be checked for nearby points which may result
		in a victory.
	Pre-Conditions: Point must be valid.
	Post-Conditions: The returned Point will be a valid Point.
	**********************************************************/ 
	Point checkForImminentVictory(Point lastPlay);
	
	//Point checkForAdjacentPoint();

	/************************************************************
	Function: getRandomPoint
	Description: Returns a random point which has not been 
		played.
	Parameters: None.
	Pre-Conditions: There is an open point on the board.
	Post-Conditions: The return Point is valid and unplayed.
	**********************************************************/ 
	Point getRandomPoint();

};
