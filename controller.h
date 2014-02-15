/*********************************************************************
Program Filename: controller.h
Author: Ian Kronquist
Date: 2013-12-31
Description: Defines a class which controls the programs flow.
********************************************************************/

#include <iostream>
#include "inputControl.h"
#include "point.h"
#include "boardmodel.cpp"
#include "ai.cpp"
#include "human.cpp"
using namespace std;

class Controller
{
	public:
	
	/************************************************************
	Constructor: Controller
	Description: Initializes the board.
	Parameters: None.
	***********************************************************/ 
	Controller();
	
	/************************************************************
	Destructor: ~Controller
	Description: Destroys its children.
	Parameters: None.
	***********************************************************/ 
	~Controller();

	/************************************************************
	Function: start
	Description: Starts the game initializes variables and calls
		setUpGame and runLoop
	Parameters: None
	Pre-Conditions: None.
	Post-Conditions: None.
	***********************************************************/ 
	void start();

	private:

	// This is the canonical model of the board. Pointers
	// to it are passed to the players.
	BoardModel* board;

	// These are the players of the game. Player is a virtual
	// (abstract) class, so they may be of Human or Ai type.
	// player1 goes first, player2 goes second.
	Player* player1;
	Player* player2;	

	/************************************************************
	Function: setUpGame
	Description: Sets up the game. Determines whether the players
		are Humans or Ais and intializes them. Calls
		getPlayerCharacter and sets the players characters.
	Parameters: None.
	Pre-Conditions: None.
	Post-Conditions: None.
	***********************************************************/ 
	void setUpGame();
	
	/************************************************************
	Function: runLoop
	Description: This method contains a loop which executes for
		every move, getting and playing the next move, 
		checking for a victor, and checking for a draw.
		When this loop terminates the game is over.
	Parameters: None.
	Pre-Conditions: None.
	Post-Conditions: None.
	***********************************************************/ 
	void runLoop();

	/************************************************************
	Function: getNextMove
	Description: Gets the next move. If the current player is 
		player1 have player1 move and similarly for 
		player2.
	Parameters: An integer representing the player, may be
		either 1 or 2, and a Point representing the 
		last move which may be used by the player to
		make an informed decision about the next move.
		Returns the move the player chooses.
	Pre-Conditions: lastPlayerNumber is either 1 or 2 and
		the Point lastMove is a valid point.
	Post-Conditions: The returned point is valid.
	***********************************************************/ 
	Point getNextMove(int lastPlayerNumber, Point lastMove);

	/************************************************************
	Function: isPlayerAComputer
	Description: Asks the user whether the player with the given
		number should be an Ai or a Human. Returns true for
		Ai
	Parameters: An integer representing the player number.
	Pre-Conditions: The playerNumber is 1 or 2.
	Post-Conditions: None.
	***********************************************************/ 
	bool isPlayerAComputer(int playerNumber);

	/************************************************************
	Function: getPlayerCharacter
	Description: Gets the char representing a player from the 
		user. This char is a printable ascii value.
	Parameters: and integer representing the player
	Pre-Conditions: The playerNumber may be 1 or 2
	Post-Conditions: Returns a printable ascii value.
	***********************************************************/ 
	char getPlayerCharacter(int playerNumber);

	/************************************************************
	Function: prettyPrint
	Description: Prints the current layout of the board with the
		players' characters on squares they occupy.
	Parameters: None.
	Pre-Conditions: None.
	Post-Conditions: None.
	***********************************************************/ 
	void prettyPrint();

	/************************************************************
	Function: printInstructions
	Description: Prints instructions on how to play the game
		including an example game board and a board with
		example coordinates on it.
	Parameters: None.
	Pre-Conditions: None.
	Post-Conditions: None.
	***********************************************************/ 
	void printInstructions();
};

