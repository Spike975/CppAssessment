#pragma once
#include "raylib.h"
struct Player {
public:
	Color color;
	int score;
};
bool customCollision(Vector2, Rectangle);
int winCondition(int * board[3]);
bool noWin(int * board[3]);
void drawGrid(Rectangle rec[3][3]);
void drawShapes(int * board[3], Color p1, Color p2);
bool colorCompare(Color one, Color two);