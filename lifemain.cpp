// Gaju Gatera Section 01 
// driver of Game of Life
#include "life.h"
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char *argv[])	{

	if (argc == 1)	{
		cout << "Interactive mode: " << endl;
		Life current;
		char ans;
		bool done = false;

		current.print();
		cout << "Hello! Here is the menu: \n";
		
		while (!done)	{
			cout << endl;
			current.menu();	// display menu
			cin >> ans;
			int x, y;

			switch (ans)	{
				case ('a'):
					cout << "Please place your desired x and y coordinate between 0 and 40 to add: ";
					cin >> x >> y;
					if (x >= 40 || y >= 40 )	{
						cout << "Out of bounds" << endl;
						break;
					}
					else	{
						current.add(x, y);
						current.print();
					}
					break;

				case ('r'):
					cout << "Please place your desired x and y coordinate between 0 and 40 to remove: ";
					cin >> x >> y;
					if (x >= 40 || y >= 40 )	{
						cout << "Out of bounds" << endl;
						break;
					}
					else	{
					current.remove(x, y);
					current.print();
					}
					break;

				case ('n'):
					current.advance();
					current.print();
					break;

				case ('p'):
					current.play();
					break;

				case ('q'):
					cout << " Goodbye! ";
					cout << endl;
					done = true;
					break;

				default:
					cout << "invalid output" << endl;
					break;

			}
		}

		return 1;

	}	

	else if (argc == 2)	{

		Life current_2;

		string letter, x_s, y_s;
		int x2, y2;
		char l;

		ifstream ifs;
		string thescene;

		// open filename:
		thescene = argv[1];
		ifs.open(thescene);

		// check for error
		if (!ifs)	{
			cout << "Error accessing the scene text" << endl;
			return 1;
		}

		cout << "3" << endl;

		while (ifs.peek()!= EOF)	{
			getline(ifs, letter, ' ');	// get the letter
			getline(ifs, x_s, ' ');		// get x
			getline(ifs, y_s, '\n');	// get y
			l = letter [0];
			x2 = stoi (x_s);
			y2 = stoi (y_s);
			
			if (l == 'a')	{
				current_2.add(x2, y2);	// don't think this is right
			}
			else if (l =='r')	{
				current_2.remove(x2, y2);
			}
			else if (l == 'p')	{
				current_2.play();
			}
		}

		return 2;
	}	

	else	{
		cout << "too many outputs" << endl;

		return 0;
	}

}






