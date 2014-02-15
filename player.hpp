/*********************************************************************
Program Filename: player.h
Author: Ian Kronquist
Date: 2013-12-31
Description: Defines a virtual (aka abstract) class representing a
	player of the game.
********************************************************************/

#ifndef PLAYER_H
#define PLAYER_H
#include "point.h"
#include "boardmodel.cpp"
/**********************************************************
Class: Player
Description: An abstract class representing a player for 
	the game. Subclassed by Ai and Human.
**********************************************************/ 
class Player
{
	public:

        /***********************************************************
        Constructor: Player
        Description: A simple template constructor which does 
		nothing.
        Parameters: None.
        **********************************************************/ 
	Player(){}

        /***********************************************************
        Destructor: ~PLayer
        Description: A virtual destructor to ensure this is a
		virtual (AKA abstract) class
        Parameters: None.
        **********************************************************/ 
	virtual ~Player(){}

        /***********************************************************
        Function: makeMove
        Description: A pure virtual function used in subclasses
		to return the move they would like to make.
        Parameters: A Point representing the last move.
        Pre-Conditions: None.
        Post-Conditions: None.
        **********************************************************/ 
	virtual Point makeMove(Point lastMove) = 0;

	// A pointer to the canonical model of the board.
	BoardModel* board;

	// A character to represent the player when pretty printing
	char character;
};
#endif

