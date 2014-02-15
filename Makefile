#makefile for the tic-tac-toe project
# CS 161

CPPC=g++
#CPPC=clang++


all: 
	$(CPPC) ./main.cpp -o tictactoe 
	
clean:
	rm -rf *.o ticktactoe

