/*********************************************************************
Program Filename: boardmodel.h
Author: Ian Kronquist
Date: 2013-12-31
Description: Defines a class which implements a datastructure 
	representing a tic-tac-toe board and common operations on 
	the board
********************************************************************/

#ifndef BOARDMODEL_H
#define BOARDMODEL_H
#include <iostream>
#include "point.h"
#include "invalidsquareexception.h"
#include <assert.h>

class BoardModel
{
	public:
	/**********************************************************
	Constructor: BoardModel
	Description: Creates a new blank board.
	Parameters: None.
	**********************************************************/ 
	BoardModel();

	/**********************************************************
	Destructor: BoardModel
	Description: Destroys this object..
	Parameters: None.
	**********************************************************/ 
	~BoardModel();

        /**********************************************************
        Constructor: clearBoard
        Description: Fills the board with 0s, clearing it.
        Parameters: None.
        Pre-Conditions: None.
        Post-Conditions: None.
        **********************************************************/ 	
	void clearBoard();

        /**********************************************************
        Constructor: play
        Description: Puts a point on the board with the value of
		the player's number.
        Parameters: A blank point on the board and a number, 
		either 1 or 2, representing the player
		making this play.
        Pre-Conditions: The Point is valid. The int player is 
		either 1 or 2
        Post-Conditions: None.
        **********************************************************/ 	
	void play(Point p, int player);

        /**********************************************************
        Constructor: checkForDraw
        Description: Returns true if there is a draw.
        Parameters: None.
        Pre-Conditions: None.
        Post-Conditions: None.
        **********************************************************/ 
	bool checkForDraw();

        /**********************************************************
        Constructor: checkForVictory
        Description: Takes a point represnting the last play
		and checks whether a player has won with 
		that play. Returns an int representing the
		winner, may be 1 or 2.
        Parameters: A Point representing the last play.
        Pre-Conditions: Point is valid.
        Post-Conditions: The returned int is wither 1 or 2.
        **********************************************************/ 
	int checkForVictory(Point lastPlay);

        /**********************************************************
        Constructor: checkForAdjacentDoubles
        Description: Checks whether the given point has identical 
		points on either side. If so, returns true, 	
		else returns false.
        Parameters: A Point representing the last play.
        Pre-Conditions: The Point is well-formed.
        Post-Conditions: None.
        **********************************************************/ 
	bool checkForAdjacentDoubles(Point lastPlay);
	
        /**********************************************************
        Constructor: getPoint
        Description: Takes a Point and returns an int representing
		the player who has the point either 1 or 2, or 0
		for an open square.
        Parameters: A Point to check.
        Pre-Conditions: None.
        Post-Conditions: None.
        **********************************************************/ 
	int getPoint(Point p);

	private:

	// This datastructure represents the 3x3 tic-tac-toe board.
	int board[3][3];
};
#endif

