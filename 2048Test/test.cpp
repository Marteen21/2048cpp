#include "pch.h"
#include "../board.hpp"

TEST(TestCaseName, TestName) {
	Board myBoard = Board();
	int data[16] = { 0,0,0,3, 0,0,0,0, 0,0,0,1, 0,0,0,1 };
	myBoard.Fill(data);
	myBoard.Print();
	myBoard.MoveTo(Direction::North);
	myBoard.Print();
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}