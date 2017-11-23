// Gaju Gatera
// Game of Life interface

class Life	{
	public:
		Life();	// constructor default
		~Life();	// destructor
		
		void print ();
		void menu ();

		void add(int x, int y);     // going through board to find coordinates of x
		void remove(int x, int y);  // remove a cell
		void advance();	// advance simulation to the next iteration
		void play();	// continuously play the game

	private:
		char board [40][40];
		char temp [40][40];
};