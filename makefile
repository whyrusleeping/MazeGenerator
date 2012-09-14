CC=g++

BIN=testMaze

all:
	$(CC) main.cpp mazeGen.cpp -o $(BIN)


