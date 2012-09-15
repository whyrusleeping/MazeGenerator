#include "mazeGen.h"
#define PRETTY
using std::cin;

int main()
{
	srand(time(NULL));	

	int s = 0;
	cout << "enter size: ";
	cin >> s;
	bool **m = getMaze(s);
	printMaze(m, s); 
	deleteMaze(m, s);
	return 0;
}
