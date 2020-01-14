#pragma once
#include "raylib.h"
struct Player {
public:
	Color color;
	int score;
};
bool customCollision(Vector2, Rectangle);
int winCondition(int * board[], int size);
bool noWin(int * board[],int size);
void drawGrid(Rectangle * rec[], int size);
void drawShapes(int * board[], Color p1, Color p2, int size);
bool colorCompare(Color one, Color two);