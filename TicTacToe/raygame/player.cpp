#include "player.h"

//A custom collision given a Vector2 and a Rectangle
bool customCollision(Vector2 v, Rectangle r) {
	if (v.x > r.x && v.y > r.y && v.y < r.y + r.height && v.x < r.x + r.width) {
		return true;
	}
	return false;
}
//Draws the board of the game
void drawGrid(Rectangle * rec[], int size) {
	for (int i = 0; i < size; i++) {
		for (int x = 0; x < size; x++) {
			DrawRectangleLines(rec[i][x].x, rec[i][x].y, rec[i][x].width, rec[i][x].height, BLACK);
		}
	}
}
//Draws the X's and  O's of the players
void drawShapes(int * board[], Color p1, Color p2, int size) {
	for (int i = 0; i < size; i++) {
		for (int x = 0; x < size; x++) {
			if (board[i][x] == 1) {
				DrawCircleLines((GetScreenWidth() / (size + 1)) + ((GetScreenWidth() * size / (size + 1)) / size * x), (GetScreenWidth() / (size + 1)) + ((GetScreenWidth() * size / (size + 1)) / size * i), (GetScreenWidth() / ((size * 2) + 2)) - (size + 1), p1);
			}
			else if (board[i][x] == -1) {
				DrawLine((GetScreenWidth() / ((size * 2) + 2)) + ((GetScreenWidth() * size / (size + 1)) / size * x), (GetScreenWidth() / ((size * 2) + 2)) + ((GetScreenWidth() * size / (size + 1)) / size * i), (GetScreenWidth() / ((size * 2) + 2)) + ((GetScreenWidth() * size / (size + 1)) / size * x) + ((GetScreenWidth() * size / (size + 1)) / size), (GetScreenWidth() / ((size * 2) + 2)) + ((GetScreenWidth() * size / (size + 1)) / size *i) + ((GetScreenWidth() * size / (size + 1)) / size), p2);
				DrawLine((GetScreenWidth() / ((size * 2) + 2)) + ((GetScreenWidth() * size / (size + 1)) / size * x)+ ((GetScreenWidth() * size / (size + 1)) / size), (GetScreenWidth() / ((size *2)+2)) + ((GetScreenWidth() *size / (size + 1)) / size * i), (GetScreenWidth() / ((size * 2) + 2)) + ((GetScreenWidth() * size / (size + 1)) / size * x), (GetScreenWidth() / ((size * 2) + 2)) + ((GetScreenWidth() * size / (size + 1)) / size * i) + ((GetScreenWidth() * size / (size + 1)) / size), p2);
			}
		}
	}
}
//Check to see if any of the players won the game
int winCondition(int * board[], int size) {
	for (int i = 0; i < size; i++) {
		int checks = 0;
		for (int x = 0; x < size; x++) {
			if (board[i][x] == 1) {
				checks++;
			}
		}
		if (checks == size) {
			return 1;
		}
		checks = 0;
		for (int x = 0; x < size; x++) {
			if (board[x][i] == 1) {
				checks++;
			}
		}
		if (checks == size) {
			return 1;
		}
		checks = 0;
		for (int x = 0; x < size; x++) {
			if (board[x][x] == 1) {
				checks++;
			}
		}
		if (checks == size) {
			return 1;
		}
		checks = 0;
		for (int x = 0; x < size; x++) {
			if (board[x][size - x] == 1) {
				checks++;
			}
		}
		if (checks == size) {
			return 1;
		}

		checks = 0;
		for (int x = 0; x < size; x++) {
			if (board[i][x] == -1) {
				checks++;
			}
		}
		if (checks == size) {
			return -1;
		}
		checks = 0;
		for (int x = 0; x < size; x++) {
			if (board[x][i] == -1) {
				checks++;
			}
		}
		if (checks == size) {
			return -1;
		}
		checks = 0;
		for (int x = 0; x < size; x++) {
			if (board[x][x] == -1) {
				checks++;
			}
		}
		if (checks == size) {
			return -1;
		}
		checks = 0;
		for (int x = 0; x < size; x++) {
			if (board[x][size - x] == -1) {
				checks++;
			}
		}
		if (checks == size) {
			return -1;
		}
	}
	return 0;
}
//Checks to see if there is a tie
bool noWin(int * board[], int size){
	int zero = 0;
	for (int i = 0; i < size; i++) {
		for (int x = 0; x < size; x++) {
			if (board[i][x] == 0) {
				zero++;
			}
		}
	}
	if (zero == 0) {
		if (winCondition(board,size) == 0) {
			return true;
		}
	}
	return false;
}
//Custom color comparison
bool colorCompare(Color one, Color two) {
	return (one.r == two.r && one.b == two.b && one.g == two.g && one.a == two.a) ? true : false;
}