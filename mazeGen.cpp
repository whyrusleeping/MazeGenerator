#include "mazeGen.h"

#ifdef PRETTY
#define PVAL 2
#else
#define PVAL 3
#endif

bool **getMaze(int size)
{
	bool **m = new bool*[size];
	for(int i = 0; i < size; i++)
		m[i] = new bool[size];
	
	int tries = 0;
	

	while(tries < 40 * size * size)
	{
		int x = rand() % size;
		int y = rand() % size;

		if(!((x == 0 && y == 0) || (x == size - 1 && y == size - 1) || (m[x][y])))
		{
			m[x][y] = true;
			
			if(threeSideCheck(m,size,x,y))
			{
				m[x][y] = false;
				tries++;
				continue;
			}
			bool **cm = copyMaze(m,size);
			if(!isPassable(cm, size,0,0))
			{
				m[x][y] = false;
				tries+=5;
			}
			
			for(int r = 0; r < size; r++)
				delete cm[r];
			delete cm;
		}
	

	}
	return m;
}

bool threeSideCheck(bool **maze, int size, int x, int y)
{
	bool ret = _nSideCheck(maze,size,x,y,2);

	if(!ret && x > 0)
		ret |= _nSideCheck(maze,size,x-1,y,PVAL);

	if(!ret && x < size-1)
		ret |= _nSideCheck(maze,size,x+1,y,PVAL);

	if(!ret && y>0)
		ret |= _nSideCheck(maze,size,x,y-1,PVAL);
	
	if(!ret && y < size-1)
		ret |= _nSideCheck(maze,size,x,y+1,PVAL);
	return ret;
}

bool _nSideCheck(bool **maze, int size, int x, int y, int n)
{
	int c = 0;
	if(x > 0)
	{
		if(maze[x-1][y])
			c++;
	}
	else
	{
		c++;
	}

	if(x < size - 1)
	{
		if(maze[x+1][y])
			c++;
	}
	else
	{
		c++;
	}

	if(y > 0)
	{
		if(maze[x][y-1])
			c++;
	}
	else
	{
		c++;
	}

	if(y < size - 1)
	{
		if(maze[x][y+1])
			c++;
	}
	else
	{
		c++;
	}

	return c > n;
	
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
