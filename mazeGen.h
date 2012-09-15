#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;

bool **getMaze(int size);
bool isPassable(bool **maze, int s, int cx, int cy);
void printMaze(bool **maze, int size);
bool **copyMaze(bool **maze, int size);
void deleteMaze(bool **maze, int size);
bool _nSideCheck(bool **maze, int size, int x, int y, int n);
bool threeSideCheck(bool **maze, int size, int x, int y);
bool deadSpaceCheck(bool **maze, int size, int x, int y);
