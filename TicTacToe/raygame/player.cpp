#include "player.h"

//A custom collision given a Vector2 and a Rectangle
bool customCollision(Vector2 v, Rectangle r) {
	if (v.x > r.x && v.y > r.y && v.y < r.y + r.height && v.x < r.x + r.width) {
		return true;
	}
	return false;
}
//Draws the board of the game
void drawGrid(Rectangle rec[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int x = 0; x < 3; x++) {
			DrawRectangleLines(rec[i][x].x, rec[i][x].y, rec[i][x].width, rec[i][x].height, BLACK);
		}
	}
}
//Draws the X's and  O's of the players
void drawShapes(int * board[3], Color p1, Color p2) {
	for (int i = 0; i < 3; i++) {
		for (int x = 0; x < 3; x++) {
			if (board[i][x] == 1) {
				DrawCircleLines((GetScreenWidth() / 4) + ((GetScreenWidth() * 3 / 4) / 3 * x), (GetScreenWidth() / 4) + ((GetScreenWidth() * 3 / 4) / 3 * i), (GetScreenWidth()/8)- 5, p1);
			}
			else if (board[i][x] == -1) {
				DrawLine((GetScreenWidth() / 8) + ((GetScreenWidth() * 3 / 4) / 3 * x), (GetScreenWidth() / 8) + ((GetScreenWidth() * 3 / 4) / 3 * i), (GetScreenWidth() / 8) + ((GetScreenWidth() * 3 / 4) / 3 * x) + ((GetScreenWidth() * 3 / 4) / 3), (GetScreenWidth() / 8) + ((GetScreenWidth() * 3 / 4) / 3 *i) + ((GetScreenWidth() * 3 / 4) / 3), p2);
				DrawLine((GetScreenWidth() / 8) + ((GetScreenWidth() * 3 / 4) / 3 * x)+ ((GetScreenWidth() * 3 / 4) / 3), (GetScreenWidth() / 8) + ((GetScreenWidth() * 3 / 4) / 3 * i), (GetScreenWidth() / 8) + ((GetScreenWidth() * 3 / 4) / 3 * x), (GetScreenWidth() / 8) + ((GetScreenWidth() * 3 / 4) / 3 * i) + ((GetScreenWidth() * 3 / 4) / 3), p2);
			}
		}
	}
}
//Check to see if any of the players won the game
int winCondition(int * board[3]) {
	if (board[0][0] == 1 && board[0][1] == 1 && board[0][2] == 1) {
		return 1;
	}
	else if (board[1][0] == 1 && board[1][1] == 1 && board[1][2] == 1) {
		return 1;
	}
	else if (board[2][0] == 1 && board[2][1] == 1 && board[2][2] == 1) {
		return 1;
	}
	else if (board[0][0] == 1 && board[1][0] == 1 && board[2][0] == 1) {
		return 1;
	}
	else if (board[0][1] == 1 && board[1][1] == 1 && board[2][1] == 1) {
		return 1;
	}
	else if (board[0][2] == 1 && board[1][2] == 1 && board[2][2] == 1) {
		return 1;
	}
	else if (board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1) {
		return 1;
	}
	else if (board[0][2] == 1 && board[1][1] == 1 && board[2][0] == 1) {
		return 1;
	}
	if (board[0][0] == -1 && board[0][1] == -1 && board[0][2] == -1) {
		return -1;
	}
	else if (board[1][0] == -1 && board[1][1] == -1 && board[1][2] == -1) {
		return -1;
	}
	else if (board[2][0] == -1 && board[2][1] == -1 && board[2][2] == -1) {
		return -1;
	}
	else if (board[0][0] == -1 && board[1][0] == -1 && board[2][0] == -1) {
		return -1;
	}
	else if (board[0][1] == -1 && board[1][1] == -1 && board[2][1] == -1) {
		return -1;
	}
	else if (board[0][2] == -1 && board[1][2] == -1 && board[2][2] == -1) {
		return -1;
	}
	else if (board[0][0] == -1 && board[1][1] == -1 && board[2][2] == -1) {
		return -1;
	}
	else if (board[0][2] == -1 && board[1][1] == -1 && board[2][0] == -1) {
		return -1;
	}
	return 0;
}
//Checks to see if there is a tie
bool noWin(int * board[3]) {
	int zero = 0;
	for (int i = 0; i < 3; i++) {
		for (int x = 0; x < 3; x++) {
			if (board[i][x] == 0) {
				zero++;
			}
		}
	}
	if (zero == 0) {
		if (winCondition(board) == 0) {
			return true;
		}
	}

	return false;
}
//Custom color comparison
bool colorCompare(Color one, Color two) {
	return (one.r == two.r && one.b == two.b && one.g == two.g && one.a == two.a) ? true : false;
}