#include "mazeGen.h"


bool **getMaze(int size)
{
	bool **m = new bool*[size];
	for(int i = 0; i < size; i++)
		m[i] = new bool[size];
	
	int tries = 0;
	

	while(tries < 10)
	{
		int x = rand() % size;
		int y = rand() % size;

		if(!((x == 0 && y == 0) || (x == size - 1 && y == size - 1) || (m[x][y])))
		{
			m[x][y] = true;
		
			bool **cm = copyMaze(m,size);
			if(!isPassable(cm, size,0,0))
			{
				m[x][y] = false;
				tries++;
			}
			
			for(int r = 0; r < size; r++)
				delete cm[r];
			delete cm;
		}
	

	}
	return m;
}

bool **copyMaze(bool **maze, int size)
{
	bool **nm = new bool*[size];
	for(int i = 0; i < size; i++)
	{
		nm[i] = new bool[size];
		for(int j = 0; j < size; j++)
			nm[i][j] = maze[i][j];
	}
	return nm;
}

bool isPassable(bool **maze, int s, int cx, int cy)
{
	if(cx < 0 || cy < 0 || cx >= s || cy >= s || maze[cx][cy] )
		return false;
	if(cx == s-1 && cy == s-1)
		return true;

	maze[cx][cy] = true;
	if(isPassable(maze, s, cx + 1, cy))
	{
		return true;
	}
	
	if(isPassable(maze, s, cx, cy + 1))
	{
		return true;
	}
	if(isPassable(maze, s, cx - 1, cy))
	{
		return true;
	}
	
	if(isPassable(maze, s, cx, cy - 1))
	{
		return true;
	}	
	return false;
}

void deleteMaze(bool **maze, int size)
{
	for(int i = 0; i< size; i++)
		delete maze[i];
	delete maze;
}

void printMaze(bool **maze, int size)
{
	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
			cout << ((maze[i][j]) ? "X":" ") << (j == size-1 ? "\n" : "");
}
