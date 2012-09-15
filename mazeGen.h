#include <iostream>
#include <cstdlib>
#include <vector>

using std::vector;
using std::cout;
using std::cin;

vector<vector<short> > getMaze(int size);
bool isPassable(vector<vector<short> > &maze, int s, int cx, int cy);
void printMaze(vector<vector<short> > maze, int size);
vector<vector<short> > copyMaze(vector<vector<short> > maze, int size);
void deleteMaze(vector<vector<short> > maze, int size);
bool _nSideCheck(vector<vector<short> > maze, int size, int x, int y, int n);
bool threeSideCheck(vector<vector<short> > maze, int size, int x, int y);
bool deadSpaceCheck(vector<vector<short> > maze, int size, int x, int y);
