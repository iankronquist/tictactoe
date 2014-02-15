/*********************************************************************
Program Filename: controller.cpp
Author: Ian Kronquist
Date: 2013-12-31
Description: Implements a class which controls the programs flow.
********************************************************************/

#include "controller.h"
#include <stdio.h>

Controller::Controller()
{
	player1 = NULL;
	player2 = NULL;
	board = new BoardModel();
	board->clearBoard();
}

Controller::~Controller()
{
	if(player1 != NULL && player2 != NULL)
	{
		delete player1;
		delete player2;
	}
	delete board;
}

void Controller::start()
{
	setUpGame();
	runLoop();
}

void Controller::setUpGame()
{
	cout << "Ready to play tic-tac-toe?" << endl;
	printInstructions();
	if(not isPlayerAComputer(1))
	{
		player1 = new Human(board);
		if(isPlayerAComputer(2))
		{
			player2 = new Ai(board);
		}
		else
		{
			player2 = new Human(board);
		}
	}
	else
	{
		player1 = new Ai(board);
		player2 = new Human(board);
	}
	cout << "Each player has their own character, which can be " <<
		"any printable character on the keyboard" << endl;
	player1->character = getPlayerCharacter(1);
	player2->character = getPlayerCharacter(2);	
}

void Controller::printInstructions()
{
	cout << "You will see a board which looks like this: " << endl;
	prettyPrint();
	cout << "You will be asked for a point on the board. The points " <<
		" are numbered like this: " << endl;
	cout << " 0,0 | 1,0 | 2,0 \n-----------------\n 0,1 | 1,1 | 2,1 \n" <<
		"-----------------\n 0,2 | 1,2 | 2,2 \n";
	cout << "When you are asked, type in a point formatted like one of " <<
		"those" << endl; 
	cout << "Let's start!" << endl;
}


bool Controller::isPlayerAComputer(int playerNumber)
{
	string input;
	while(true)
	{
		cout << "Will player " << playerNumber <<
			 " be a computer? type y or n " << endl;
		cin >> input;
		cleanupCin();
		//checkStream(cin);
		if(input == string("y"))
		{
			return true;
		}
		else if(input == string("n"))
		{	
			return false;
		}
		else
		{
			cout << "Invalid Input" << endl;
			continue;
		}
	}	
}

char Controller::getPlayerCharacter(int playerNumber)
{
	string input;
	while(true)	
	{
		cout << "Choose player " << playerNumber << 
			"`s character: " << endl;
		cin >> input;
		//checkStream(cin);
		if(input.length() != 1)
		{
			cout << "The character must be one symbol. Try again." << endl;
			continue;
		}
		else if(input[0] < 33 || input[0] > 126)
		{
			cout << "The character must be a printable ascii character. " 
			<< "try again" << endl;
			continue;
		}
		else
		{
			return input[0];
		}
	}
}

void Controller::runLoop()
{
	int currentPlayer = 1;
	Point lastMove(0, 0);
	while(true)
	{
		cout << "Player " << currentPlayer << "`s move: " << endl;
		lastMove = getNextMove(currentPlayer, lastMove);
		board->play(lastMove, currentPlayer);
		prettyPrint();
		int victor = board->checkForVictory(lastMove);
		if(victor != 0)
		{
			if(victor == 1)
			{
				cout << player1->character << " wins!" << endl;
			}
			else if(victor == 2)
			{
				cout << player2->character << " wins!" << endl;
			}
			break;
		}
		if(board->checkForDraw())
		{
			cout << "Draw!" << endl;
			break;
		}
		if(currentPlayer == 1)
		{
			currentPlayer = 2;
		}
		else
		{
			currentPlayer = 1;
		}
	}
}

Point Controller::getNextMove(int lastPlayerNumber, Point lastMove)
{
	if(lastPlayerNumber == 1)
	{
		return player1->makeMove(lastMove);
	}	
	else
	{
		return player2->makeMove(lastMove);
	}
}

void Controller::prettyPrint()
{
	string out;
	out += "\n";
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			char c;
			int value = board->getPoint(Point(x, y));
			out += ' ';
			switch (value)
			{
				case 0:
					out += ' ';
					break;
				case 1:
					out += player1->character;
					break;
				case 2:
					out += player2->character;
					break;
			}
			out += ' ';
			if(y != 2)
			{
				out += '|';
			}
		}
		if(x != 2)
		{
			out += "\n-----------\n";
		}
	}
	cout << out << endl;
}
