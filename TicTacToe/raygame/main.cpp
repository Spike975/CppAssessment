/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include <iostream>
#include "player.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------

	int screen = 0;
	int boardSize;

	//sets the size of the screen
	std::cout << "Please enter a size of the screen:\n";
	std::cin >> screen;

	if (screen < 600) {
		std::cout << "Size to small... Auto update will incur\n";
		screen = 600;
	}
	else if (screen > 1000) {
		std::cout << "Size to large... Auto update will incur\n";
		screen = 1000;
	}


	//Sets size of board
	std::cout << "Please enter a size of the board:\n";
	std::cin >> boardSize;

	if (boardSize < 2) {
		std::cout << "Size to small... Auto update will incur\n";
		boardSize = 2;
	}
	else if (boardSize > 10) {
		std::cout << "Size to large for screen... Auto update will incur\n";
		boardSize = 10;
	}

	bool onePlayer = false;
	bool playerOne = true;
	bool win = false;
	bool start = true;
	int startPhase = 0;
	int currPlayer;

	Player * one = new Player();
	Player * two = new Player();
	one->score = 0;
	two->score = 0;
	one->color = RAYWHITE;
	two->color = RAYWHITE;

	int ** board = new int*[boardSize];
	for (int i = 0; i < boardSize; i++) {
			board[i] = new int[boardSize];
	}
	for (int i = 0; i < boardSize; i++) {
		for (int x = 0; x < boardSize; x++) {
			board[i][x] = 0;
		}
	}
	//The area for the boxes of the board
	Rectangle ** checkers = new Rectangle*[boardSize];
	for (int i = 0; i < boardSize; i++) {
		checkers[i] = new Rectangle[boardSize];
	}

	InitWindow(screen, screen, "Basic Tic-Tac-Toe");

	//creats the board for the game
	for (int i = 0; i < boardSize; i++) {
		for (int x = 0; x < boardSize; x++) {
			checkers[i][x].x = (float)(GetScreenWidth() / ((boardSize * 2) + 2)) + ((GetScreenWidth() * boardSize / (boardSize + 1)) / boardSize * x);
			checkers[i][x].y = (float)(GetScreenHeight() / ((boardSize * 2) + 2)) + ((GetScreenHeight() * boardSize / (boardSize + 1)) / boardSize * i);
			checkers[i][x].height = (float)(GetScreenWidth() * boardSize / (boardSize+1)) / boardSize;
			checkers[i][x].width = (float)(GetScreenHeight() * boardSize / (boardSize+1)) / boardSize;
		}
	}
	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------
		//Resets game
		if (IsKeyPressed(KEY_R)) {
			for (int i = 0; i < boardSize; i++) {
				for (int x = 0; x < boardSize; x++) {
					board[i][x] = 0;
				}
			}
			playerOne = true;
			win = false;
		}
		//Prints current board state
		if (IsKeyPressed(KEY_H)){
			for (int i = 0; i < 3; i++) {
				for (int x = 0; x < 3; x++) {
					std::cout << board[i][x];
				}
				std::cout << std::endl;
			}
		}
		//Changes the turn of the player
		if (!win) {
			if (playerOne) {
				DrawText("Turn: Player One", (GetScreenWidth()/2)-100, 0, 20, BLACK);
				currPlayer = 1;
			}
			else {
				DrawText("Turn: Player Two", 200, 0, 20, BLACK);
				currPlayer = -1;
			}
		}
		//Makes sure the board can't be chaned after someone won
		else {
			currPlayer = 0;
		}

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();
		ClearBackground(RAYWHITE);

		//Draws the board
		drawGrid(checkers, boardSize);
		
		//Draws the scores of the players
		DrawText(FormatText("Player 1: %01i", one->score), 10, 0, 20, one->color);
		DrawText(FormatText("Player 2: %01i", two->score), GetScreenWidth()-150, 0, 20, two->color);

		//Draws the shapes
		drawShapes(board,one->color,two->color,boardSize);
		//Initial Startup for color pick
		if (start) {
			Rectangle Blue;
			Blue.x = (GetScreenWidth() / 2) - 70;
			Blue.y = (GetScreenHeight() / 2) - 40;
			Blue.width = 70;
			Blue.height = 70;
			Rectangle Red;
			Red.x = (GetScreenWidth() / 2) +20;
			Red.y = (GetScreenHeight() / 2) - 40;
			Red.width = 70;
			Red.height = 70;
			Rectangle Black;
			Black.x = (GetScreenWidth() / 2) - 70;
			Black.y = (GetScreenHeight() / 2) + 50;
			Black.width = 70;
			Black.height = 70;
			Rectangle Green;
			Green.x = (GetScreenWidth() / 2) + 20;
			Green.y = (GetScreenHeight() / 2) + 50;
			Green.width = 70;
			Green.height = 70;
			DrawRectangle((GetScreenWidth() / 2)-140, (GetScreenHeight() / 2)- 170, 300, 350, LIGHTGRAY);
			//Player one color pick
			if (startPhase == 0) {
				DrawText("Player 1", (GetScreenWidth() / 2) - 40, (GetScreenHeight() / 2) - 150, 20, BLACK);
				if (customCollision(GetMousePosition(),Blue)) {
					if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
						one->color = BLUE;
						startPhase++;
					}
				}
				if (customCollision(GetMousePosition(), Red)) {
					if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
						one->color = RED;
						startPhase++;
					}
				}
				if (customCollision(GetMousePosition(), Black)) {
					if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
						one->color = BLACK;
						startPhase++;
					}
				}
				if (customCollision(GetMousePosition(), Green)) {
					if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
						one->color = DARKGREEN;
						startPhase++;
					}
				}
			}
			//Player two color pick
			else if (startPhase == 1) {
				DrawText("Player 2", (GetScreenWidth()/2) - 40, (GetScreenHeight()/2) - 150, 20, BLACK);
				if (!colorCompare(one->color, BLUE)) {
					if (customCollision(GetMousePosition(), Blue)) {
						if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
							two->color = BLUE;
							startPhase++;
						}
					}
				}
				if (!colorCompare(one->color, RED)) {
					if (customCollision(GetMousePosition(), Red)) {
						if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
							two->color = RED;
							startPhase++;
						}
					}
				}
				if (!colorCompare(one->color, BLACK)) {
					if (customCollision(GetMousePosition(), Black)) {
						if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
							two->color = BLACK;
							startPhase++;
						}
					}
				}
				if (!colorCompare(one->color, DARKGREEN)) {
					if (customCollision(GetMousePosition(), Green)) {
						if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
							two->color = DARKGREEN;
							startPhase++;
						}
					}
				}
			}
			else {
				start = false;
			}
			
			DrawText("Choose Color:", (GetScreenWidth() / 2) - 70, (GetScreenHeight() / 2) - 90, 20, BLACK);
			
			if (!colorCompare(one->color,BLUE)) {
				DrawRectangleRec(Blue,BLUE);
			}
			if (!colorCompare(one->color, RED)) {
				DrawRectangleRec(Red, RED);
			}
			if (!colorCompare(one->color, BLACK)) {
				DrawRectangleRec(Black, BLACK);
			}
			if (!colorCompare(one->color, DARKGREEN)) {
				DrawRectangleRec(Green, DARKGREEN);
			}
		}
		//Main loop for game
		else {
			//Player pick the square they wish to chose
			for (int i = 0; i < boardSize; i++) {
				for (int x = 0; x < boardSize; x++) {
					if (customCollision(GetMousePosition(), checkers[i][x])) {
						if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
							if (board[i][x] == 0) {
								board[i][x] = currPlayer;
								playerOne = !playerOne;
							}
						}
					}
				}
			}
			//Checks board to see if Player 1 won
			if (winCondition(board,boardSize) == 1) {
				DrawRectangle((GetScreenWidth() / 2) - 150, (GetScreenWidth() / 2) - 150, 300, 300, LIGHTGRAY);
				DrawText("Player One Wins!", (GetScreenWidth() / 2) - 90, (GetScreenWidth() / 2) - 90, 20, BLACK);
				DrawText("Press R to reset game", (GetScreenWidth() / 2) - 120, (GetScreenWidth() / 2) - 20, 20, BLACK);
				if (!win) {
					one->score++;
					win = true;
				}
			}
			//Checks board to see if Player 2 won
			else if (winCondition(board,boardSize) == -1) {
				DrawRectangle(150, 150, 300, 300, LIGHTGRAY);
				DrawText("Player Two Wins!", (GetScreenWidth() / 2) - 90, (GetScreenWidth() / 2) - 90, 20, BLACK);
				DrawText("Press R to reset game", (GetScreenWidth() / 2) - 120, (GetScreenWidth() / 2) - 20, 20, BLACK);
				if (!win) {
					two->score++;
					win = true;
				}
			}
			//Checks board to see if no one won
			else if (noWin(board,boardSize)) {
				DrawRectangle((GetScreenHeight() / 2) - 150, (GetScreenHeight() / 2) - 150, 300, 300, LIGHTGRAY);
				DrawText("Looks like a stalemate.", (GetScreenWidth() / 2) - 115, (GetScreenWidth() / 2) - 90, 20, BLACK);
				DrawText("Press R to reset game", (GetScreenWidth() / 2) - 120, (GetScreenWidth() / 2) - 20, 20, BLACK);
			}
		}
		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------
	//Deleting
	for (int i = 0; i < 3; ++i) {
		delete[] board[i];
	}
	delete[] board;
	delete[] checkers;
	delete one;
	delete two;
	return 0;
}