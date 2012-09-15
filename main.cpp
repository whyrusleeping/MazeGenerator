#include "mazeGen.h"
#define PRETTY
using std::cin;

int main()
{
/*
	vector<vector<bool> > a;
	a.resize(4);
	a[0].resize(6);
	a[1].resize(6);

	a[2].resize(6);

	a[3].resize(6);

	a[2][3] = true;
	

	vector<vector<bool> > b(a);


	if(b[2][3] == true)
		cout << "tittie sprinkles";


	b[2][3] = false;

	if(a[2][3] == true)
		cout << "MORE TITTIE SPRINKLES";
*/
	srand(time(NULL));	

	int s = 0;
	cout << "enter size: ";
	cin >> s;
	vector<vector<short> > m = getMaze(s);
	printMaze(m, s); 
	deleteMaze(m, s);
	return 0;
}
