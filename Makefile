CC      = g++
CFLAGS  = -std=c++11


default: all

all: game2048 test

game2048: game2048.cpp
	$(CC) $(CFLAGS) -o out/game2048 game2048.cpp field.cpp board.cpp -g

test: game2048Test.cpp
	$(CC) $(CFLAGS) -o out/game2048Test game2048Test.cpp field.cpp board.cpp
