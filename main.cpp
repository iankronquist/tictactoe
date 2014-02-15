/*********************************************************************
Program Filename: main.cpp 
Author: Ian Kronquist
Date: 2013-12-31
Description: Starts the program.
********************************************************************/
#include "controller.cpp"

int main()
{
	Controller* controls = new Controller();
	controls->start();
	return 0;
}
