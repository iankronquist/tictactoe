/********************************************************************
Program Filename: inputcontrol.h
Author: Ian Kronquist
Date: 2013-12-31
Description: Defines and implements a simple method used to prevent
	errors from closing cin or bad/invalid bits.
********************************************************************/

#ifndef INPUTCONTROL_H
#define INPUTCONTROL_H

#include <iostream>
#include <stdlib.h>

using namespace std;

/*********************************************************************
Function: cleanupCin
Description: cleans up cin to accept more input. If the EOF signal
	(AKA ctrl+d) is given, terminate the program with exit
	code 0 for success. If the bad bit is set, unset it, clear 
	and sync the stream.
Parameters: None.
Pre-Conditions: None.
Post-Conditions: None.
********************************************************************/ 
void cleanupCin()
{
        if(cin.eof())
	{
		cout << "Goodbye!" << endl;
		exit(0);
	}
	if(!cin.good())
	{
		cout << "Invalid input" << endl;
		cin.clear();
		cin.sync();
	}
}

#endif

