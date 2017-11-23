// Gaju Gatera Section 01
// Implementation of Game of Life
#include "life.h"
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

Life :: Life()
{	
	for (int i = 0; i < 40; i++) {
		for (int j = 0; j < 40; j++){
			board[i][j] = '.';
			temp[i][j] = '.';
		}
	}
}

Life :: ~Life ()
{	}


void Life :: print()
{
	for (int i = 0; i < 40; i++){
		for (int j = 0; j < 40; j++){
			cout << board[i][j];
		}
		cout << endl;
	}
}


void Life :: menu ()
{
	cout << "----------------------------\n";
	cout << "a : add a new cell " << endl;
	cout <<	"r : remove a cell " << endl;
	cout <<	"n : advance the simulation " << endl;
	cout << "q : quit the program." << endl;
	cout <<	"p : play the game continuously " << endl;

}

void Life :: add (int x, int y)
{
	board[x][y] = 'X';

}

void Life :: remove (int x, int y)
{
	board[x][y] = '.';

}


void Life :: advance ()
{
	// check through entire board to find live cells
	for (int i = 0; i < 40; i++)	{
		for (int j = 0; j < 40; j++)	{
			int live = 0;
			if (board[i][j] == 'X' || 1) {
				
				if (i+1<40 && board[i+1][j] == 'X' )				// check right
					live++;
				
				if (i-1>=0 && board[i-1][j] == 'X')					// check left
					live++;
				
				if (j+1<40 && board[i][j+1] == 'X')					// check down
					live++;
				
				if (i+1 < 40 && j+1<40 && board[i+1][j+1] == 'X')	// check right-down
					live++;
				
				if (i-1 >=0 && j+1<40 && board[i-1][j+1] == 'X')	// check left-down
					live++;
				
				if (j-1>=0 && board[i][j-1] == 'X')					// check up
					live++;
				
				if (i+1<40 && j-1>=0 && board[i+1][j-1] == 'X')		// check right-up
					live++;
				
				if (i-1>=0 && j-1>=0 && board[i-1][j-1] == 'X')		// check left-up
					live++;
			}

			// implement game of life rules
			if (board [i][j] == 'X' && live < 2)	{	// live cell with fewer than 
													// two live neighbours dies
				temp [i][j] = '.';
			}
			
			else if (board[i][j] == 'X' && live > 3)	{	// live cell with more than three live neighbours dies
                temp [i][j] = '.';
            }
           
            else if (board[i][j] == 'X' && (live == 2 || live == 3)) {	// live cell with two or three live neighbours lives on to the next generation
                temp [i][j] = 'X';
            }
           
            else if (board[i][j] == '.' && live == 3)	{	// dead cell with exactly three live neighbours becomes a live cell
                temp [i][j] = 'X';
            }
            
            else 	{
            	temp[i][j] = '.';
            }

		}
	}

	// switch the current board to temp board
	for (int i = 0; i < 40; i++)	{
		for (int j = 0; j < 40; j++)	{
			board[i][j] = temp[i][j];
		}
	}
}

void Life :: play()
{
	bool play = true;
	int sec = 80000;
	while (play)	{
		advance();
		system("clear");  
		print();
		usleep(sec);
	}
}








